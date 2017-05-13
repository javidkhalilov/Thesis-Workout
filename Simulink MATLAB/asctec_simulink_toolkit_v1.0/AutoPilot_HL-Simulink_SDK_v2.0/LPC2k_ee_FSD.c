/****************************************************************************************/
/*                                                                            			*/
/*			   	                                                                        */
/****************************************************************************************/
#include "uart.h"
#include <string.h>
#include "LPC214x.h"
#include "LPC2K_EE.H"					/* LPC2000 EEPROM definitions */
#define IAP_LOCATION 			0x7ffffff1

//const unsigned char eeprom[EE_SIZE] _at_ EE_ADDR_L;


typedef void (*IAP)(unsigned int [],unsigned int[]);
IAP iap_entry;

/************************************************************************/
/*                                                                     	*/
/************************************************************************/
unsigned char ee_erase(void)
{
	unsigned int command_iap[5];
	unsigned int result_iap[3];
	unsigned long int enabled_interrupts;

	enabled_interrupts = VICIntEnable;  //disable all interrupts
	VICIntEnClr        = enabled_interrupts;

	command_iap[0]=50;					//prepare sectors from EE_SEC_L to EE_SEC_H for erase
	command_iap[1]=EE_SEC_L;
	command_iap[2]=EE_SEC_H;
	iap_entry=(IAP) IAP_LOCATION;
	iap_entry(command_iap,result_iap);

	command_iap[0]=52;					//erase sectors from EE_SEC_L to EE_SEC_H
	command_iap[1]=EE_SEC_L;
	command_iap[2]=EE_SEC_H;
	command_iap[3]=EE_CCLK;
	iap_entry=(IAP) IAP_LOCATION;
	iap_entry(command_iap,result_iap);

	command_iap[0]=53;					//blankcheck sectors from EE_SEC_L to EE_SEC_H
	command_iap[1]=EE_SEC_L;
	command_iap[2]=EE_SEC_H;
	iap_entry=(IAP) IAP_LOCATION;
	iap_entry(command_iap,result_iap);

	VICIntEnable = enabled_interrupts;  //restore interrupt enable register

	return (result_iap[0]);
}

/************************************************************************/
/*                                                                    	*/
/* adapted for simulink code                                            */
/*                                                                     	*/
/************************************************************************/
unsigned char ee_write(unsigned int *buffer)
{
	int location=EE_ADDR_L;
	unsigned int command_iap[5], result_iap[3];
	unsigned long int enabled_interrupts;

		enabled_interrupts = VICIntEnable;  //disable all interrupts
		VICIntEnClr        = enabled_interrupts;

		command_iap[0]=50;					//prepare sectors from EE_SEC_L to EE_SEC_H for erase
		command_iap[1]=EE_SEC_L;
		command_iap[2]=EE_SEC_H;
		iap_entry=(IAP) IAP_LOCATION;
		iap_entry(command_iap,result_iap);

		command_iap[0]=51;					//copy RAM to flash/eeprom
		command_iap[1]=(unsigned int) (location);
		command_iap[2]=(unsigned int) (buffer);
		command_iap[3]=1024;//EE_BUFFER_SIZE;
		command_iap[4]=EE_CCLK;
		iap_entry=(IAP) IAP_LOCATION;
		iap_entry(command_iap,result_iap);
		//UART_SendPacket(&result_iap, 4, 1);
		command_iap[0]=56;					//compare RAM and flash/eeprom
		command_iap[1]=(unsigned int) buffer;
		command_iap[2]=(unsigned int) location;
		command_iap[3]=EE_BUFFER_SIZE;
		iap_entry=(IAP) IAP_LOCATION;
		iap_entry(command_iap,result_iap);

		VICIntEnable = enabled_interrupts;  //restore interrupt enable register


	return (result_iap[0]);
}

/************************************************************************/
/*                                                                    	*/
/* adapted for simulink code                                            */
/*                                                                     	*/
/************************************************************************/
void ee_read(unsigned int *buffer)
{
	unsigned int *ptr=(unsigned int*)EE_ADDR_L;
    memcpy(buffer, ptr, EE_BUFFER_SIZE);


	return;
}

