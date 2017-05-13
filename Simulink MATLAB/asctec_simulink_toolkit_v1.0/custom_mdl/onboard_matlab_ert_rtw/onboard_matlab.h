/*
 * File: onboard_matlab.h
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

#ifndef RTW_HEADER_onboard_matlab_h_
#define RTW_HEADER_onboard_matlab_h_
#ifndef onboard_matlab_COMMON_INCLUDES_
# define onboard_matlab_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* onboard_matlab_COMMON_INCLUDES_ */

#include "onboard_matlab_types.h"

/* Macros for accessing real-time model data structure */

/* user code (top of header file) */
#undef a
#undef b

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T DiscreteTimeIntegrator1_DSTATE;/* '<S11>/Discrete-Time Integrator1' */
  int32_T DiscreteTimeIntegrator2_DSTATE;/* '<S11>/Discrete-Time Integrator2' */
  int16_T UnitDelay_DSTATE;            /* '<S14>/Unit Delay' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S11>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator2_PrevRes;/* '<S11>/Discrete-Time Integrator2' */
} D_Work_onboard_matlab;

/* Invariant block signals (auto storage) */
typedef struct {
  const int16_T Gain18;                /* '<S3>/Gain18' */
  const int16_T Gain19;                /* '<S3>/Gain19' */
  const int16_T Gain27;                /* '<S3>/Gain27' */
  const int16_T Gain28;                /* '<S3>/Gain28' */
  const int16_T Gain37;                /* '<S3>/Gain37' */
  const int16_T Gain43;                /* '<S3>/Gain43' */
  const int16_T Gain44;                /* '<S3>/Gain44' */
  const int16_T Gain45;                /* '<S3>/Gain45' */
  const int16_T Gain46;                /* '<S3>/Gain46' */
  const int16_T Gain47;                /* '<S3>/Gain47' */
  const int16_T Gain58;                /* '<S3>/Gain58' */
  const int16_T Gain49;                /* '<S3>/Gain49' */
  const int16_T Gain50;                /* '<S3>/Gain50' */
  const int16_T Gain51;                /* '<S3>/Gain51' */
  const int16_T Gain52;                /* '<S3>/Gain52' */
  const int16_T Gain53;                /* '<S3>/Gain53' */
  const int16_T Gain54;                /* '<S3>/Gain54' */
  const int16_T Gain55;                /* '<S3>/Gain55' */
  const int16_T Gain56;                /* '<S3>/Gain56' */
  const int16_T Gain57;                /* '<S3>/Gain57' */
} ConstBlockIO_onboard_matlab;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Gain9_Gain
   * Referenced by: '<S11>/Gain9'
   */
  int128m_T Gain9_Gain;

  /* Computed Parameter: DiscreteTimeIntegrator1_ga
   * Referenced by: '<S11>/Discrete-Time Integrator1'
   */
  int64m_T DiscreteTimeIntegrator1_ga;

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S14>/Constant4'
   */
  int16_T Constant4_Value[5];
} ConstParam_onboard_matlab;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  IMU_DATA_IN IMU_Data_In;             /* '<Root>/IMU_Data_In' */
  GPS_DATA_IN GPS_Data_In;             /* '<Root>/GPS_Data_In' */
  RC_DATA_IN RC_Data_In;               /* '<Root>/RC_Data_In' */
  UART_DATA_IN UART_Data_In;           /* '<Root>/UART_Data_In' */
  MOTOR_DATA_IN MOTOR_Data_In;         /* '<Root>/MOTOR_Data_In' */
} ExternalInputs_onboard_matlab;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  LL_CMD_OUT LL_CMD_Out;               /* '<Root>/LL_CMD_Out' */
  CTRL_MODE CTRL_mode;                 /* '<Root>/CTRL_mode' */
  UART_DATA_OUT UART_Data_Out;         /* '<Root>/UART_Data_Out' */
} ExternalOutputs_onboard_matlab;

/* Block states (auto storage) */
extern D_Work_onboard_matlab onboard_matlab_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_onboard_matlab onboard_matlab_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_onboard_matlab onboard_matlab_Y;
extern const ConstBlockIO_onboard_matlab onboard_matlab_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstParam_onboard_matlab onboard_matlab_ConstP;

/* Model entry point functions */
extern void onboard_matlab_initialize(void);
extern void onboard_matlab_step0(void);
extern void onboard_matlab_step1(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'onboard_matlab'
 * '<S1>'   : 'onboard_matlab/Onboard_Matlab_Controller'
 * '<S2>'   : 'onboard_matlab/Output_Mapping_CMD'
 * '<S3>'   : 'onboard_matlab/Output_Mapping_Debug'
 * '<S4>'   : 'onboard_matlab/Signal_Mapping_CMDs'
 * '<S5>'   : 'onboard_matlab/Signal_Mapping_GPS'
 * '<S6>'   : 'onboard_matlab/Signal_Mapping_IMU'
 * '<S7>'   : 'onboard_matlab/Signal_Mapping_UART'
 * '<S8>'   : 'onboard_matlab/Signal_mapping_Motor_Feedback'
 * '<S9>'   : 'onboard_matlab/Onboard_Matlab_Controller/Control Allocation'
 * '<S10>'  : 'onboard_matlab/Onboard_Matlab_Controller/Debug -> to ground ctrl'
 * '<S11>'  : 'onboard_matlab/Onboard_Matlab_Controller/Control Allocation/Sine sweep'
 * '<S12>'  : 'onboard_matlab/Onboard_Matlab_Controller/Control Allocation/Sine sweep/Compare To Constant3'
 * '<S13>'  : 'onboard_matlab/Onboard_Matlab_Controller/Control Allocation/Sine sweep/Compare To Constant4'
 * '<S14>'  : 'onboard_matlab/Output_Mapping_Debug/List_Iterator'
 * '<S15>'  : 'onboard_matlab/Signal_Mapping_GPS/Extract Bits'
 * '<S16>'  : 'onboard_matlab/Signal_Mapping_GPS/Extract Bits1'
 * '<S17>'  : 'onboard_matlab/Signal_Mapping_GPS/Extract Bits2'
 */
#endif                                 /* RTW_HEADER_onboard_matlab_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
