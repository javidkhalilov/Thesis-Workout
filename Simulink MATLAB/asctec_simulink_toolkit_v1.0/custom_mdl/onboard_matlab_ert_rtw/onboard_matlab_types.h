/*
 * File: onboard_matlab_types.h
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

#ifndef RTW_HEADER_onboard_matlab_types_h_
#define RTW_HEADER_onboard_matlab_types_h_
#include "rtwtypes.h"
#ifndef SS_LONG
#define SS_LONG                        63
#endif

#ifndef SS_ULONG
#define SS_ULONG                       64
#endif

#ifndef _DEFINED_TYPEDEF_FOR_IMU_DATA_IN_
#define _DEFINED_TYPEDEF_FOR_IMU_DATA_IN_

typedef struct {
  int32_T angle_roll;
  int32_T angle_pitch;
  int32_T angle_yaw;
  int32_T angvel_roll;
  int32_T angvel_pitch;
  int32_T angvel_yaw;
  int16_T acc_x;
  int16_T acc_y;
  int16_T acc_z;
  int32_T Hx;
  int32_T Hy;
  int32_T Hz;
  int32_T height_data_fusion;
  int32_T dheight_data_fusion;
  int16_T data_fusion_speed_EW;
  int16_T data_fusion_speed_NS;
  int32_T gps_latitude_data_fusion;
  int32_T gps_longitude_data_fusion;
} IMU_DATA_IN;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_GPS_DATA_IN_
#define _DEFINED_TYPEDEF_FOR_GPS_DATA_IN_

typedef struct {
  int32_T gps_latitude;
  int32_T gps_longitude;
  int32_T gps_height;
  int32_T gps_speed_EW;
  int32_T gps_speed_NS;
  int32_T gps_heading;
  uint32_T gps_position_acc;
  uint32_T gps_height_acc;
  uint32_T gps_speed_acc;
  uint32_T gps_num_sat;
  int32_T gps_status;
  uint32_T gps_time_of_week;
  uint16_T gps_time_week;
} GPS_DATA_IN;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_RC_DATA_IN_
#define _DEFINED_TYPEDEF_FOR_RC_DATA_IN_

typedef struct {
  int16_T CMD_1;
  int16_T CMD_2;
  int16_T CMD_3;
  int16_T CMD_4;
  int16_T CMD_5;
  int16_T CMD_6;
  int16_T CMD_7;
  int16_T CMD_8;
} RC_DATA_IN;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_UART_DATA_IN_
#define _DEFINED_TYPEDEF_FOR_UART_DATA_IN_

typedef struct {
  int16_T uart_ctrl_01;
  int16_T uart_ctrl_02;
  int16_T uart_ctrl_03;
  int16_T uart_ctrl_04;
  int16_T uart_ctrl_05;
  int16_T uart_ctrl_06;
  int16_T uart_ctrl_07;
  int16_T uart_ctrl_08;
  int16_T uart_ctrl_09;
  int16_T uart_ctrl_10;
  int16_T uart_ctrl_11;
  int16_T uart_ctrl_12;
} UART_DATA_IN;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_MOTOR_DATA_IN_
#define _DEFINED_TYPEDEF_FOR_MOTOR_DATA_IN_

typedef struct {
  uint8_T m1;
  uint8_T m2;
  uint8_T m3;
  uint8_T m4;
  uint8_T m5;
  uint8_T m6;
} MOTOR_DATA_IN;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_LL_CMD_OUT_
#define _DEFINED_TYPEDEF_FOR_LL_CMD_OUT_

typedef struct {
  int16_T motor_rpm_1;
  int16_T motor_rpm_2;
  int16_T motor_rpm_3;
  int16_T motor_rpm_4;
  int16_T motor_rpm_5;
  int16_T motor_rpm_6;
  int16_T motor_mapped_roll;
  int16_T motor_mapped_pitch;
  int16_T motor_mapped_yaw;
  int16_T motor_mapped_thrust;
  int16_T att_cmd_roll;
  int16_T att_cmd_pitch;
  int16_T att_cmd_yaw;
  int16_T att_cmd_thrust;
} LL_CMD_OUT;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_CTRL_MODE_
#define _DEFINED_TYPEDEF_FOR_CTRL_MODE_

typedef struct {
  uint8_T ctrl_mode;
  uint8_T ctrl_enabled;
  uint8_T disable_motor_onoff_by_stick;
  int16_T flight_mode;
} CTRL_MODE;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_UART_DATA_OUT_
#define _DEFINED_TYPEDEF_FOR_UART_DATA_OUT_

typedef struct {
  int16_T uart_debug_01;
  int16_T uart_debug_02;
  int16_T uart_debug_03;
  int16_T uart_debug_04;
  int16_T uart_debug_05;
  int16_T uart_debug_06;
  int16_T uart_debug_07;
  int16_T uart_debug_08;
  int16_T uart_debug_09;
  int16_T uart_debug_10;
  int16_T uart_debug_11;
  int16_T uart_debug_12;
  int16_T uart_debug_13;
  int16_T uart_debug_14;
  int16_T uart_debug_15;
  int16_T uart_debug_16;
  int16_T uart_debug_17;
  int16_T uart_debug_18;
  int16_T uart_debug_19;
  int16_T uart_debug_20;
} UART_DATA_OUT;

#endif
#endif                                 /* RTW_HEADER_onboard_matlab_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
