/*

AscTec AutoPilot HL SDK v2.0

Copyright (c) 2011, Ascending Technologies GmbH
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
DAMAGE.

 */

#include "main.h"
#include "sdk.h"
#include "LL_HL_comm.h"
#include "gpsmath.h"
#include "uart.h"
#include "system.h"

struct WO_SDK_STRUCT WO_SDK;
struct WO_CTRL_INPUT WO_CTRL_Input;
struct RO_RC_DATA RO_RC_Data;
struct RO_ALL_DATA RO_ALL_Data;
struct WO_DIRECT_MOTOR_CONTROL WO_Direct_Motor_Control;
struct WO_DIRECT_INDIVIDUAL_MOTOR_CONTROL WO_Direct_Individual_Motor_Control;

struct MATLAB_DEBUG matlab_debug;
struct MATLAB_UART matlab_uart, matlab_uart_tmp;

void SDK_EXAMPLE_direct_individual_motor_commands(void);
void SDK_EXAMPLE_direct_motor_commands_with_standard_output_mapping(void);
void SDK_EXAMPLE_attitude_commands(void);
void SDK_EXAMPLE_gps_waypoint_control(void);
int SDK_EXAMPLE_turn_motors_on(void);
int SDK_EXAMPLE_turn_motors_off(void);

/* SDK_mainloop(void) is triggered @ 1kHz.
 *
 * RO_(Read Only) data is updated before entering this function
 * and can be read to obtain information for supervision or control
 *
 * WO_(Write Only) data is written to the LL processor after
 * execution of this function.
 *
 * WO_ and RO_ structs are defined in sdk.h
 *
 * The struct RO_ALL_Data (defined in sdk.h)
 * is used to read all sensor data, results of the data fusion
 * and R/C inputs transmitted from the LL-processor. This struct is
 * automatically updated at 1 kHz.
 * */

/* How to flash the high level processor
 *
 * The easiest way to get your code on the high level processor is to use the JTAG-adapter.
 *
 * It needs three steps to get your code on the high level processor.
 * 1. Build your code ("Build Project")
 * 2. Connect your JTAG adapter and start the JTAG connection ("OpenOCD Asctec-JTAG")
 * 3. Flash the processor ("Asctec JTAG Debug")
 *
 * In the menu "Run -> External Tools -> External Tools Configuration..." you
 * will find "OpenOCD Asctec-JTAG". If the JTAG connection was activated
 * correctly, the console will show only the following line:
 * "Info:    openocd.c:92 main(): Open On-Chip Debugger (2007-08-10 22:30 CEST)"
 *
 * Do not launch more than ONE JTAG-connection at the same time!
 *
 * In the menu "Run -> Debug Configurations..." you will find "Asctec JTAG Debug"
 * If the code was successfully flashed on the processor, the program will switch
 * to the Debug window.
 *************
 * If you want to flash the high level processor using a serial interface (AscTec USB adapter)
 * and bootloader software like "Flash Magic", you need to change
 * the following in the "makefile" (line 113):
 *
 * FORMAT = ihex
 * #FORMAT = binary
 *
 * After buidling your code you will find the main.hex in your workspace folder.
 *************
 * */

/* After flashing the HL, your code can be debugged online. The ARM7 supports ONE hardware breakpoint.
 * You can monitor the CPU-load by looking at HL_Status.cpu_load. As long as this value is 1000 your
 * code in SDK_mainloop() is executed at 1 kHz.
 *
 * To activate the SDK controls, the serial interface switch on your R/C (channel 5) needs to be in ON position.
 *
 * If your project needs communication over a serial link, you find an example of how to do so in main.c, line 178.
 * All sample functions for transmitting and receiving data over the UART (HL_serial_0) are in uart.c - you can use
 * these examples to code your own communication state machine.
 */


void SDK_mainloop(void) //write your own code within this function
{
	static unsigned short uart_count = 1; //counter for uart communication

	//WO_SDK.ctrl_mode=0x00;	//0x00: direct individual motor control: individual commands for motors 0..3
							//0x01: direct motor control using standard output mapping: commands are interpreted as pitch, roll, yaw and thrust inputs; no attitude controller active
							//0x02: attitude and throttle control: commands are input for standard attitude controller
							//0x03: GPS waypoint control

	//WO_SDK.ctrl_enabled=1;  //0: disable control by HL processor
							//1: enable control by HL processor

	//WO_SDK.disable_motor_onoff_by_stick=0;

	rt_OneStep(); //call RTW function rt_OneStep
	//ctrl_mode is set in tr_one_step




	if (uart_count==0 && xbee_send_flag) //call function for uart transmission with 50 Hz
	{
		matlab_debug.cpu_load = HL_Status.cpu_load;
		matlab_debug.battery_voltage = HL_Status.battery_voltage_1;

		UART0_SendPacket(&matlab_debug, sizeof(matlab_debug), 'd');
	}
	uart_count++;
	uart_count%=ControllerCyclesPerSecond/50;
}







