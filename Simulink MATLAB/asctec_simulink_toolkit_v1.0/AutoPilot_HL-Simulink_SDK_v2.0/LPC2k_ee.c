/****************************************************************************************/
/*                                                                            			*/
/*  LPC2k_ee.C:  basic LPC213x EEPROM routines (rev 1.1, Jan 27th, 2006.)				*/
/*  Adapted for AscTec Simulink Example Code                                                                          			*/
/* Functions provided here:																*/
/*   	                                                    		                    */
/* ee_erase(command_ee, result_ee[]):	erases all EEPROM								*/
/* ee_write(command_ee, result_ee[]):	writes record of ee_data (defined in LPC2k_ee.h)*/
/* ee_read(command_ee, result_ee[]) :	reads the last record added into EEPROM			*/
/* ee_readn(command_ee, result_ee[]):	reads the n-th record in EEPROM					*/
/* ee_count(command_ee, result_ee[]):	counts records of ee_data type in EEPROM		*/
/*			   	                                                                        */
/****************************************************************************************/
#include "uart.h"
#include "LPC214x.h"
//#define _EEPROM_
#include "LPC2K_EE.H"					/* LPC2000 EEPROM definitions */
//#undef _EEPROM_
#define IAP_LOCATION 			0x7ffffff1

//const unsigned char eeprom[EE_SIZE] _at_ EE_ADDR_L;
//void ee_erase(unsigned int ,unsigned int[]);	//function erases EEPROM
//void ee_write(unsigned int ,unsigned int[]);	//function adds a record in EEPROM
//void ee_read (unsigned int ,unsigned int[]);	//function reads the latest valid record in EEPROM
//void ee_count(unsigned int ,unsigned int[]);	//function counts records in EEPROM
//void ee_readn(unsigned int ,unsigned int[]);	//function reads n-th record in EEPROM
//int ee_locate(void);							   	//function locates the next available location

typedef void (*IAP)(unsigned int [],unsigned int[]);
IAP iap_entry;

/************************************************************************/
/*                                                                    	*/
/* function: 															*/
/*  void ee_erase(unsigned int command_ee,unsigned int result_ee[])		*/
/*                                                                     	*/
/* type: void                                                          	*/
/*                                                                     	*/
/* parameters: 															*/
/* 	command_ee   - Not used.  	                              			*/
/*  result_ee[0] - Returns a response to the last IAP command used.		*/
/*                 0 - EEPROM successfully erased.						*/
/*                 For all other response values, see microcontroller 	*/
/*				   User Manual, IAP Commands and Status Codes Summary.	*/
/*  result_ee[1] - Not used.  	                              			*/
/*                                                                     	*/
/* version: 1.1 (01/27/2006)                                           	*/
/*                                                                     	*/
/* constants defined in LPC2k_ee.h used in this function:              	*/
/*  EE_SEC_L 	 - microcontroller's Flash sector where EEPROM begins	*/
/*  EE_SEC_H 	 - microcontroller's Flash sector where EEPROM ends		*/
/*  EE_CCLK		 - microcontroller's system clock (cclk)                */
/*                                                                     	*/
/* description:															*/
/*  This function erases LPC2000 on-chip Flash sectors selected to act 	*/
/*  as an EEPROM. All Flash sectors between EE_SEC_L abd EE_SEC_H		*/
/*  (including these sectors) will be erased using the In Application	*/
/*  Programming (IAP) routines (see User Manual for more details). 		*/
/*  Also, this function disables all interrupts while erasing the       */
/*  EEPROM. If this is not needed, three lines of the ee_erase          */
/*  subroutine can simply be commented-out without affecting the        */
/*  routine performance at all.                                         */
/*                                                                     	*/
/* revision history:                                                   	*/
/* - Rev. 1.1 adds interrupt disable feature.							*/
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
/* function: 															*/
/*  void ee_write(unsigned int command_ee,unsigned int result_ee[])		*/
/*                                                                     	*/
/* type: void                                                          	*/
/*                                                                     	*/
/* parameters: 															*/
/* 	command_ee   - An address of a content of ee_data type that has		*/
/*                 to be programmed into EEPROM.                       	*/
/*  result_ee[0] - Returns a response to the last IAP command used.		*/
/*                 0 - data successfully programmed in EEPROM.			*/
/*               501 - no space in EEPROM to program data.             	*/
/*                 For all other response values, see microcontroller 	*/
/*				   User Manual, IAP Commands and Status Codes Summary.	*/
/*  result_ee[1] - Not used.  	                              			*/
/*                                                                     	*/
/* version: 1.1 (01/27/2006)                                           	*/
/*                                                                     	*/
/* constants defined in LPC2k_ee.h used in this function:              	*/
/*  EE_BUFFER_SIZE 	   - IAP buffer size; must be 256 or 512 			*/
/*  NO_SPACE_IN_EEPROM - EEPROM is full and no data can be programmed	*/
/*  EE_BUFFER_MASK	   - parameter used for interfacing with IAP		*/
/*  EE_REC_SIZE   	   - ee_data structure size in bytes        		*/
/*  EE_SEC_L 	 	   - micro's Flash sector where EEPROM begins		*/
/*  EE_SEC_H 	 	   - micro's Flash sector where EEPROM ends			*/
/*  EE_CCLK		 	   - micro's system clock (cclk)                	*/
/*                                                                     	*/
/* description:															*/
/*  This function writes a single structure of ee_data type into the	*/
/*  EEPROM using an In Application	Programming (IAP) routines (see 	*/
/*  User Manual for more details). command_ee contains an address of	*/
/*  this structure. EEPROM is scanned for the last (if any) record 		*/
/*  identifier (EE_REC_ID), and a new record is added next to it.      	*/
/*  Also, this function disables all interrupts while erasing the       */
/*  EEPROM. If this is not needed, three lines of the ee_write          */
/*  subroutine can simply be commented-out without affecting the        */
/*  routine performance at all.                                         */
/*                                                                     	*/
/* revision history:                                                   	*/
/* - Rev. 1.1 fixes a bug related to verifying a content written into	*/
/*   the EEPROM. 1.0 was reporting missmatch even when there were no	*/
/*   problems at all.													*/
/*   Rev. 1.1 adds interrupt disable feature.							*/
//* adapted for simulink code                                            */                                                                    	*/
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
/* function: 															*/
/*  void ee_read(unsigned int command_ee,unsigned int result_ee[])		*/
/*                                                                     	*/
/* type: void                                                          	*/
/*                                                                     	*/
/* parameters: 															*/
/* 	command_ee   - Not used.											*/
/*  result_ee[0] - Returns a response.									*/
/*                 0 - data successfully found in EEPROM.				*/
/*               500 - no data/records available in EEPROM.				*/
/*  result_ee[1] - an address of the last record of ee_data type		*/
/*				   in EEPROM.  	                              			*/
/*                                                                     	*/
/* version: 1.1 (01/27/2006)                                           	*/
/*                                                                     	*/
/* constants defined in LPC2k_ee.h used in this function:              	*/
/*  NO_RECORDS_AVAILABLE - EEPROM is empty/no records identifiable		*/
/*						   with a record identifier (EE_REC_ID) found	*/
/*  EE_ADR_L 	 	   - micro's Flash address from where EEPROM begins	*/
/*  EE_REC_SIZE 	   - size (in bytes) of a ee_data structure        	*/
/*                                                                     	*/
/* description:															*/
/*  This function scans an EEPROM content looking for the last record 	*/
/*  that can be identified with a record identifier (EE_REC_ID). When 	*/
/*  such data is found, its address is passed as result_ee[1].			*/
/*                                                                     	*/
/* revision history:                                                   	*/
/* - Rev. 1.0 had problems with accessing the last record in a fully	*/
/*   occupied EEPROM. Rev. 1.1 fixes this.								*/
/*                                                                     	*/
/************************************************************************/

/* adapted for simulink code                                            */
/*                                                                     	*/
/************************************************************************/
void ee_read(unsigned int *buffer)
{
	unsigned int *ptr=(unsigned int*)EE_ADDR_L;
    memcpy(buffer, ptr, EE_BUFFER_SIZE);


	return;
}

