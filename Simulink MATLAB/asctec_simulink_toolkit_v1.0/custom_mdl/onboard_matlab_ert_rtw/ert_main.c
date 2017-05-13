/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'onboard_matlab'.
 *
 * Model version                  : 1.1561
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 19 2013)
 * C/C++ source code generated on : Thu Feb 04 00:10:56 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "onboard_matlab.h"

/****************** include sdk header files ******************/
#include "main.h"
#include "sdk.h"
#include "uart.h"

/************************************/

/****************** declare uart up channels ******************/
uint32_T uart_up_p_01 = 0;             // Variable: uart_up_p_01
uint32_T uart_up_p_02 = 0;             // Variable: uart_up_p_02
uint32_T uart_up_p_03 = 0;             // Variable: uart_up_p_03
uint32_T uart_up_p_04 = 0;             // Variable: uart_up_p_04
uint32_T uart_up_p_05 = 0;             // Variable: uart_up_p_05
uint32_T uart_up_p_06 = 0;             // Variable: uart_up_p_06
uint32_T uart_up_p_07 = 0;             // Variable: uart_up_p_07
uint32_T uart_up_p_08 = 0;             // Variable: uart_up_p_08
uint32_T uart_up_p_09 = 0;             // Variable: uart_up_p_09
uint32_T uart_up_p_10 = 0;             // Variable: uart_up_p_10
uint32_T uart_up_p_11 = 0;             // Variable: uart_up_p_11
uint32_T uart_up_p_12 = 0;             // Variable: uart_up_p_12
uint32_T uart_up_p_13 = 0;             // Variable: uart_up_p_13
uint32_T uart_up_p_14 = 0;             // Variable: uart_up_p_14
uint32_T uart_up_p_15 = 0;             // Variable: uart_up_p_15
uint32_T uart_up_p_16 = 0;             // Variable: uart_up_p_16
uint32_T uart_up_p_17 = 0;             // Variable: uart_up_p_17
uint32_T uart_up_p_18 = 0;             // Variable: uart_up_p_18
uint32_T uart_up_p_19 = 0;             // Variable: uart_up_p_19
uint32_T uart_up_p_20 = 0;             // Variable: uart_up_p_20
uint32_T uart_up_p_21 = 0;             // Variable: uart_up_p_21
uint32_T uart_up_p_22 = 0;             // Variable: uart_up_p_22
uint32_T uart_up_p_23 = 0;             // Variable: uart_up_p_23
uint32_T uart_up_p_24 = 0;             // Variable: uart_up_p_24
uint32_T uart_up_p_25 = 0;             // Variable: uart_up_p_25
uint32_T uart_up_p_26 = 0;             // Variable: uart_up_p_26
uint32_T uart_up_p_27 = 0;             // Variable: uart_up_p_27
uint32_T uart_up_p_28 = 0;             // Variable: uart_up_p_28
uint32_T uart_up_p_29 = 0;             // Variable: uart_up_p_29
uint32_T uart_up_p_30 = 0;             // Variable: uart_up_p_30
uint32_T uart_up_p_31 = 0;             // Variable: uart_up_p_31
uint32_T uart_up_p_32 = 0;             // Variable: uart_up_p_32
uint32_T uart_up_p_33 = 0;             // Variable: uart_up_p_33
uint32_T uart_up_p_34 = 0;             // Variable: uart_up_p_34
uint32_T uart_up_p_35 = 0;             // Variable: uart_up_p_35
uint32_T uart_up_p_36 = 0;             // Variable: uart_up_p_36
uint32_T uart_up_p_37 = 0;             // Variable: uart_up_p_37
uint32_T uart_up_p_38 = 0;             // Variable: uart_up_p_38
uint32_T uart_up_p_39 = 0;             // Variable: uart_up_p_39
uint32_T uart_up_p_40 = 0;             // Variable: uart_up_p_40

/************************************/
void rt_OneStep(void)
{
  static boolean_T OverrunFlags[2] = { 0, 0 };

  static boolean_T eventFlags[2] = { 0, 0 };/* Model has 2 rates */

  static int_T taskCounter[2] = { 0, 0 };

  /* Disable interrupts here */

  /* Check base rate for overrun */
  if (OverrunFlags[0]++) {
    ((void) 0);
    return;
  }

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /****************** get Inputs ******************/
  /****************** get RC-Inputs ******************/
  onboard_matlab_U.RC_Data_In.CMD_1 = ((short) RO_ALL_Data.channel[0] - 2048)*8;
  onboard_matlab_U.RC_Data_In.CMD_2 = ((short) RO_ALL_Data.channel[1] - 2048)*8;
  onboard_matlab_U.RC_Data_In.CMD_3 = ((short) RO_ALL_Data.channel[2] - 2048)*8;
  onboard_matlab_U.RC_Data_In.CMD_4 = ((short) RO_ALL_Data.channel[3] - 2048)*8;
  onboard_matlab_U.RC_Data_In.CMD_5 = ((short) RO_ALL_Data.channel[4] - 2048)*8;
  onboard_matlab_U.RC_Data_In.CMD_6 = ((short) RO_ALL_Data.channel[5] - 2048)*8;
  onboard_matlab_U.RC_Data_In.CMD_7 = ((short) RO_ALL_Data.channel[6] - 2048)*8;
  onboard_matlab_U.RC_Data_In.CMD_8 = ((short) RO_ALL_Data.channel[7] - 2048)*8;

  /****************** get IMU Data ******************/
  onboard_matlab_U.IMU_Data_In.angle_pitch = RO_ALL_Data.angle_pitch;
  onboard_matlab_U.IMU_Data_In.angle_roll = RO_ALL_Data.angle_roll;
  onboard_matlab_U.IMU_Data_In.angle_yaw = RO_ALL_Data.angle_yaw;
  onboard_matlab_U.IMU_Data_In.angvel_pitch = RO_ALL_Data.angvel_pitch;
  onboard_matlab_U.IMU_Data_In.angvel_roll = RO_ALL_Data.angvel_roll;
  onboard_matlab_U.IMU_Data_In.angvel_yaw = RO_ALL_Data.angvel_yaw;
  onboard_matlab_U.IMU_Data_In.acc_x = RO_ALL_Data.acc_x;
  onboard_matlab_U.IMU_Data_In.acc_y = RO_ALL_Data.acc_y;
  onboard_matlab_U.IMU_Data_In.acc_z = RO_ALL_Data.acc_z;
  onboard_matlab_U.IMU_Data_In.Hx = RO_ALL_Data.Hx;
  onboard_matlab_U.IMU_Data_In.Hy = RO_ALL_Data.Hy;
  onboard_matlab_U.IMU_Data_In.Hz = RO_ALL_Data.Hz;
  onboard_matlab_U.IMU_Data_In.height_data_fusion = RO_ALL_Data.fusion_height;
  onboard_matlab_U.IMU_Data_In.dheight_data_fusion = RO_ALL_Data.fusion_dheight;
  onboard_matlab_U.IMU_Data_In.data_fusion_speed_EW = RO_ALL_Data.fusion_speed_x;
  onboard_matlab_U.IMU_Data_In.data_fusion_speed_NS = RO_ALL_Data.fusion_speed_y;
  onboard_matlab_U.IMU_Data_In.gps_latitude_data_fusion =
    RO_ALL_Data.fusion_latitude;
  onboard_matlab_U.IMU_Data_In.gps_longitude_data_fusion =
    RO_ALL_Data.fusion_longitude;

  /****************** get Motor Data ******************/
  onboard_matlab_U.MOTOR_Data_In.m1 = RO_ALL_Data.motor_rpm[0];
  onboard_matlab_U.MOTOR_Data_In.m2 = RO_ALL_Data.motor_rpm[1];
  onboard_matlab_U.MOTOR_Data_In.m3 = RO_ALL_Data.motor_rpm[2];
  onboard_matlab_U.MOTOR_Data_In.m4 = RO_ALL_Data.motor_rpm[3];
  onboard_matlab_U.MOTOR_Data_In.m5 = RO_ALL_Data.motor_rpm[4];
  onboard_matlab_U.MOTOR_Data_In.m6 = RO_ALL_Data.motor_rpm[5];

  /****************** get Uart Params ******************/
  uart_up_p_01 = matlab_params.p01;
  uart_up_p_02 = matlab_params.p02;
  uart_up_p_03 = matlab_params.p03;
  uart_up_p_04 = matlab_params.p04;
  uart_up_p_05 = matlab_params.p05;
  uart_up_p_06 = matlab_params.p06;
  uart_up_p_07 = matlab_params.p07;
  uart_up_p_08 = matlab_params.p08;
  uart_up_p_09 = matlab_params.p09;
  uart_up_p_10 = matlab_params.p10;
  uart_up_p_11 = matlab_params.p11;
  uart_up_p_12 = matlab_params.p12;
  uart_up_p_13 = matlab_params.p13;
  uart_up_p_14 = matlab_params.p14;
  uart_up_p_15 = matlab_params.p15;
  uart_up_p_16 = matlab_params.p16;
  uart_up_p_17 = matlab_params.p17;
  uart_up_p_18 = matlab_params.p18;
  uart_up_p_19 = matlab_params.p19;
  uart_up_p_20 = matlab_params.p20;
  uart_up_p_21 = matlab_params.p21;
  uart_up_p_22 = matlab_params.p22;
  uart_up_p_23 = matlab_params.p23;
  uart_up_p_24 = matlab_params.p24;
  uart_up_p_25 = matlab_params.p25;
  uart_up_p_26 = matlab_params.p26;
  uart_up_p_27 = matlab_params.p27;
  uart_up_p_28 = matlab_params.p28;
  uart_up_p_29 = matlab_params.p29;
  uart_up_p_30 = matlab_params.p30;
  uart_up_p_31 = matlab_params.p31;
  uart_up_p_32 = matlab_params.p32;
  uart_up_p_33 = matlab_params.p33;
  uart_up_p_34 = matlab_params.p34;
  uart_up_p_35 = matlab_params.p35;
  uart_up_p_36 = matlab_params.p36;
  uart_up_p_37 = matlab_params.p37;
  uart_up_p_38 = matlab_params.p38;
  uart_up_p_39 = matlab_params.p39;
  uart_up_p_40 = matlab_params.p40;

  /****************** get Uart Ctrl ******************/
  onboard_matlab_U.UART_Data_In.uart_ctrl_01 = matlab_uart.ctrl01;
  onboard_matlab_U.UART_Data_In.uart_ctrl_02 = matlab_uart.ctrl02;
  onboard_matlab_U.UART_Data_In.uart_ctrl_03 = matlab_uart.ctrl03;
  onboard_matlab_U.UART_Data_In.uart_ctrl_04 = matlab_uart.ctrl04;
  onboard_matlab_U.UART_Data_In.uart_ctrl_05 = matlab_uart.ctrl05;
  onboard_matlab_U.UART_Data_In.uart_ctrl_06 = matlab_uart.ctrl06;
  onboard_matlab_U.UART_Data_In.uart_ctrl_07 = matlab_uart.ctrl07;
  onboard_matlab_U.UART_Data_In.uart_ctrl_08 = matlab_uart.ctrl08;
  onboard_matlab_U.UART_Data_In.uart_ctrl_09 = matlab_uart.ctrl09;
  onboard_matlab_U.UART_Data_In.uart_ctrl_10 = matlab_uart.ctrl10;
  onboard_matlab_U.UART_Data_In.uart_ctrl_11 = matlab_uart.ctrl11;
  onboard_matlab_U.UART_Data_In.uart_ctrl_12 = matlab_uart.ctrl12;

  /****************** get GPS-Data ******************/
  onboard_matlab_U.GPS_Data_In.gps_latitude = RO_ALL_Data.GPS_latitude;
  onboard_matlab_U.GPS_Data_In.gps_longitude = RO_ALL_Data.GPS_longitude;
  onboard_matlab_U.GPS_Data_In.gps_height = RO_ALL_Data.GPS_height;
  onboard_matlab_U.GPS_Data_In.gps_speed_EW = RO_ALL_Data.GPS_speed_x;
  onboard_matlab_U.GPS_Data_In.gps_speed_NS = RO_ALL_Data.GPS_speed_y;
  onboard_matlab_U.GPS_Data_In.gps_heading = RO_ALL_Data.GPS_heading;
  onboard_matlab_U.GPS_Data_In.gps_position_acc =
    RO_ALL_Data.GPS_position_accuracy;
  onboard_matlab_U.GPS_Data_In.gps_height_acc = RO_ALL_Data.GPS_height_accuracy;
  onboard_matlab_U.GPS_Data_In.gps_speed_acc = RO_ALL_Data.GPS_speed_accuracy;
  onboard_matlab_U.GPS_Data_In.gps_num_sat = RO_ALL_Data.GPS_sat_num;
  onboard_matlab_U.GPS_Data_In.gps_status = RO_ALL_Data.GPS_status;
  onboard_matlab_U.GPS_Data_In.gps_time_of_week = RO_ALL_Data.GPS_time_of_week;
  onboard_matlab_U.GPS_Data_In.gps_time_week = RO_ALL_Data.GPS_week;

  /***************** end inputs *******************/

  /* Check subrate overrun, set rates that need to run this time step*/
  if (taskCounter[1] == 0) {
    if (eventFlags[1]) {
      OverrunFlags[0] = FALSE;
      OverrunFlags[1] = TRUE;
      return;
    }

    eventFlags[1] = TRUE;
  }

  taskCounter[1]++;
  if (taskCounter[1] == 2) {
    taskCounter[1]= 0;
  }

  /* Step the model for base rate */
  onboard_matlab_step0();

  /* Get model outputs here */

  /****************** write LL commands ******************/
  WO_SDK.ctrl_mode = onboard_matlab_Y.CTRL_mode.ctrl_mode;
  WO_SDK.ctrl_enabled = onboard_matlab_Y.CTRL_mode.ctrl_enabled;
  WO_SDK.disable_motor_onoff_by_stick =
    onboard_matlab_Y.CTRL_mode.disable_motor_onoff_by_stick;
  WO_CTRL_Input.ctrl = onboard_matlab_Y.CTRL_mode.flight_mode;

  //commands will be directly interpreted by each motor individually
  WO_Direct_Individual_Motor_Control.motor[0] = (unsigned char)
    (onboard_matlab_Y.LL_CMD_Out.motor_rpm_1);
  WO_Direct_Individual_Motor_Control.motor[1] = (unsigned char)
    (onboard_matlab_Y.LL_CMD_Out.motor_rpm_2);
  WO_Direct_Individual_Motor_Control.motor[2] = (unsigned char)
    (onboard_matlab_Y.LL_CMD_Out.motor_rpm_3);
  WO_Direct_Individual_Motor_Control.motor[3] = (unsigned char)
    (onboard_matlab_Y.LL_CMD_Out.motor_rpm_4);
  WO_Direct_Individual_Motor_Control.motor[4] = (unsigned char)
    (onboard_matlab_Y.LL_CMD_Out.motor_rpm_5);
  WO_Direct_Individual_Motor_Control.motor[5] = (unsigned char)
    (onboard_matlab_Y.LL_CMD_Out.motor_rpm_6);

  //direct motor commands with standard output mapping
  WO_Direct_Motor_Control.roll = (unsigned char)
    (onboard_matlab_Y.LL_CMD_Out.motor_mapped_roll);
  WO_Direct_Motor_Control.pitch = (unsigned char)
    (onboard_matlab_Y.LL_CMD_Out.motor_mapped_pitch);
  WO_Direct_Motor_Control.yaw = (unsigned char)
    (onboard_matlab_Y.LL_CMD_Out.motor_mapped_yaw);
  WO_Direct_Motor_Control.thrust = (unsigned char)
    (onboard_matlab_Y.LL_CMD_Out.motor_mapped_thrust);

  //attitude commands
  WO_CTRL_Input.roll = (short)(onboard_matlab_Y.LL_CMD_Out.att_cmd_roll);
  WO_CTRL_Input.pitch = (short)(onboard_matlab_Y.LL_CMD_Out.att_cmd_pitch);
  WO_CTRL_Input.yaw = (short)(onboard_matlab_Y.LL_CMD_Out.att_cmd_yaw);
  WO_CTRL_Input.thrust = (short)(onboard_matlab_Y.LL_CMD_Out.att_cmd_thrust);

  /****************** write debug channels ******************/
  matlab_debug.debug01 = onboard_matlab_Y.UART_Data_Out.uart_debug_01;
  matlab_debug.debug02 = onboard_matlab_Y.UART_Data_Out.uart_debug_02;
  matlab_debug.debug03 = onboard_matlab_Y.UART_Data_Out.uart_debug_03;
  matlab_debug.debug04 = onboard_matlab_Y.UART_Data_Out.uart_debug_04;
  matlab_debug.debug05 = onboard_matlab_Y.UART_Data_Out.uart_debug_05;
  matlab_debug.debug06 = onboard_matlab_Y.UART_Data_Out.uart_debug_06;
  matlab_debug.debug07 = onboard_matlab_Y.UART_Data_Out.uart_debug_07;
  matlab_debug.debug08 = onboard_matlab_Y.UART_Data_Out.uart_debug_08;
  matlab_debug.debug09 = onboard_matlab_Y.UART_Data_Out.uart_debug_09;
  matlab_debug.debug10 = onboard_matlab_Y.UART_Data_Out.uart_debug_10;
  matlab_debug.debug11 = onboard_matlab_Y.UART_Data_Out.uart_debug_11;
  matlab_debug.debug12 = onboard_matlab_Y.UART_Data_Out.uart_debug_12;
  matlab_debug.debug13 = onboard_matlab_Y.UART_Data_Out.uart_debug_13;
  matlab_debug.debug14 = onboard_matlab_Y.UART_Data_Out.uart_debug_14;
  matlab_debug.debug15 = onboard_matlab_Y.UART_Data_Out.uart_debug_15;
  matlab_debug.debug16 = onboard_matlab_Y.UART_Data_Out.uart_debug_16;
  matlab_debug.debug17 = onboard_matlab_Y.UART_Data_Out.uart_debug_17;
  matlab_debug.debug18 = onboard_matlab_Y.UART_Data_Out.uart_debug_18;
  matlab_debug.debug19 = onboard_matlab_Y.UART_Data_Out.uart_debug_19;
  matlab_debug.debug20 = onboard_matlab_Y.UART_Data_Out.uart_debug_20;

  /*************** end outputs *********************/
  OverrunFlags[0]--;

  /* If task "1" is running, don't run any lower priority task */
  if (OverrunFlags[1])
    return;

  /* Step the model for subrate */
  if (eventFlags[1]) {
    OverrunFlags[1]++;

    /* Set model inputs associated with subrates here */

    /* Step the model for subrate 1 */
    onboard_matlab_step1();

    /* Get model outputs here */

    /* Get model outputs associated with subrates here */

    /* Indicate task complete for subrate */
    OverrunFlags[1]--;
    eventFlags[1]--;
  }

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
