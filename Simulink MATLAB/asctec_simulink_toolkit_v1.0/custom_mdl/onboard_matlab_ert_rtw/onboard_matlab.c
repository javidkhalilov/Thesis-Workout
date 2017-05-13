/*
 * File: onboard_matlab.c
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
#include "onboard_matlab_private.h"

/* Block states (auto storage) */
D_Work_onboard_matlab onboard_matlab_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_onboard_matlab onboard_matlab_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_onboard_matlab onboard_matlab_Y;
int32_T div_nzp_s32_ceiling(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) == (denominator < 0)) && (numerator % denominator) ?
          1 : 0) + numerator / denominator;
}

void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn;
  uint32_T absIn_0;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn = (uint32_T)(in0 < 0 ? -in0 : in0);
  absIn_0 = (uint32_T)(in1 < 0 ? -in1 : in1);
  in0Hi = absIn >> 16U;
  in0Lo = absIn & 65535U;
  in1Hi = absIn_0 >> 16U;
  absIn = absIn_0 & 65535U;
  productHiLo = in0Hi * absIn;
  productLoHi = in0Lo * in1Hi;
  absIn *= in0Lo;
  absIn_0 = 0U;
  in0Lo = (productLoHi << 16U) + absIn;
  if (in0Lo < absIn) {
    absIn_0 = 1U;
  }

  absIn = in0Lo;
  in0Lo += productHiLo << 16U;
  if (in0Lo < absIn) {
    absIn_0++;
  }

  absIn = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn_0;
  if (!((in0 == 0) || ((in1 == 0) || ((in0 > 0) == (in1 > 0))))) {
    absIn = ~absIn;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn++;
    }
  }

  *ptrOutBitsHi = absIn;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_s32_s32_sr30(int32_T a, int32_T b)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << 2U | u32_clo >> 30U;
  return (int32_T)u32_clo;
}

int32_T mul_s32_s32_s32_sr32(int32_T a, int32_T b)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  return (int32_T)u32_chi;
}

int32_T mul_s32_s32_s32_sr28_sat_zero(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  boolean_T roundup;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  roundup = (((uint32_T)((int32_T)u32_chi < 0)) && (u32_clo & 268435455U));
  u32_clo = (u32_chi << 4U | u32_clo >> 28U) + roundup;
  u32_chi = (uint32_T)(roundup && (u32_clo == 0U)) + ((int32_T)u32_chi >> 28);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

int32_T mul_s32_s32_s32_sr30_sat_zero(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  boolean_T roundup;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  roundup = (((uint32_T)((int32_T)u32_chi < 0)) && (u32_clo & 1073741823U));
  u32_clo = (u32_chi << 2U | u32_clo >> 30U) + roundup;
  u32_chi = (uint32_T)(roundup && (u32_clo == 0U)) + ((int32_T)u32_chi >> 30);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

int32_T mul_s32_s32_s32_sr31_sat_zero(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  boolean_T roundup;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  roundup = (((uint32_T)((int32_T)u32_chi < 0)) && (u32_clo & 2147483647U));
  u32_clo = (u32_chi << 1U | u32_clo >> 31U) + roundup;
  u32_chi = (uint32_T)(roundup && (u32_clo == 0U)) + ((int32_T)u32_chi >> 31);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

void sMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T nb;
  int32_T i;
  uint32_T ys;
  uint32_T yi;
  uint32_T u1i;
  int32_T nc;
  uint32_T nr;
  uint32_T nl;
  int32_T i1;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > (uint32_T)0) {
      nl = 32U - nr;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << nl | yi;
        i++;
      }

      yi = u1i >> nr;
      u1i = nc < n1 ? u1[nc] : ys;
      y[i] = u1i << nl | yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void ssuMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
                     int32_T n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a;
  uint32_T a_0;
  uint32_T b;
  uint32_T w;
  uint32_T w_0;
  uint32_T cb;
  boolean_T isNegative;
  uint32_T cb_0;
  isNegative = ((u1[n1 - 1] & 2147483648U) != 0U);
  cb_0 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative) {
      u1i = ~u1i + cb_0;
      cb_0 = u1i < cb_0 ? 1U : 0U;
    }

    a = u1i >> 16U;
    a_0 = u1i & 65535U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      b = u1i >> 16U;
      u1i &= 65535U;
      w = a * u1i;
      w_0 = a_0 * b;
      yk += cb;
      cb = yk < cb ? 1U : 0U;
      u1i *= a_0;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      u1i = w << 16U;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      u1i = w_0 << 16U;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      y[k] = yk;
      cb += w >> 16U;
      cb += w_0 >> 16U;
      cb += a * b;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = yk < cb ? 1U : 0U;
    }
  }
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a;
  uint32_T a_0;
  uint32_T b;
  uint32_T w;
  uint32_T w_0;
  uint32_T cb;
  boolean_T isNegative;
  boolean_T isNegative_0;
  uint32_T cb_0;
  uint32_T cb_1;
  isNegative = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative_0 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb_0 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative) {
      u1i = ~u1i + cb_0;
      cb_0 = u1i < cb_0 ? 1U : 0U;
    }

    a = u1i >> 16U;
    a_0 = u1i & 65535U;
    cb_1 = 1U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative_0) {
        u1i = ~u1i + cb_1;
        cb_1 = u1i < cb_1 ? 1U : 0U;
      }

      b = u1i >> 16U;
      u1i &= 65535U;
      w = a * u1i;
      w_0 = a_0 * b;
      yk += cb;
      cb = yk < cb ? 1U : 0U;
      u1i *= a_0;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      u1i = w << 16U;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      u1i = w_0 << 16U;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      y[k] = yk;
      cb += w >> 16U;
      cb += w_0 >> 16U;
      cb += a * b;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative != isNegative_0) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = yk < cb ? 1U : 0U;
    }
  }
}

void sMultiWord2sMultiWordSat(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n)
{
  int32_T nm;
  uint32_T ys;
  int32_T n1m1;
  boolean_T doSaturation = FALSE;
  nm = n - 1;
  n1m1 = n1 - 1;
  ys = (u1[n1m1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (n1 > n) {
    doSaturation = (((u1[n1m1] ^ u1[nm]) & 2147483648U) != 0U);
    while ((!doSaturation) && (n1m1 >= n)) {
      doSaturation = (u1[n1m1] != ys);
      n1m1--;
    }
  }

  if (doSaturation) {
    ys = ~ys;
    for (n1m1 = 0; n1m1 < nm; n1m1++) {
      y[n1m1] = ys;
    }

    y[n1m1] = ys ^ 2147483648U;
  } else {
    nm = n1 < n ? n1 : n;
    for (n1m1 = 0; n1m1 < nm; n1m1++) {
      y[n1m1] = u1[n1m1];
    }

    while (n1m1 < n) {
      y[n1m1] = ys;
      n1m1++;
    }
  }
}

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  uint32_T yi;
  uint32_T u1i;
  uint32_T carry = 0U;
  int32_T i;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0U ? yi <= u1i ? 1U : 0U : yi < u1i ? 1U : 0U;
  }
}

void sMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[], int32_T
  n)
{
  uint32_T u1i;
  int32_T nm;
  int32_T i;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    u1i = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
    for (i = nm; i < n; i++) {
      y[i] = u1i;
    }
  }
}

void sMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T nb;
  int32_T nc;
  int32_T i;
  uint32_T ys;
  uint32_T u1i;
  uint32_T yi;
  uint32_T nr;
  uint32_T nl;
  nb = (int32_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  nc = nb > n ? n : nb;
  u1i = 0U;
  for (i = 0; i < nc; i++) {
    y[i] = 0U;
  }

  if (nb < n) {
    nl = n2 - ((uint32_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      nr = 32U - nl;
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> nr;
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> nr | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sLong2MultiWord(int32_T u, uint32_T y[], int32_T n)
{
  uint32_T yi;
  int32_T i;
  y[0] = (uint32_T)u;
  yi = u < 0 ? MAX_uint32_T : 0U;
  for (i = 1; i < n; i++) {
    y[i] = yi;
  }
}

boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) >= 0 ? (int32_T)TRUE : (int32_T)FALSE;
}

int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  uint32_T su;
  uint32_T su_0;
  int32_T i;
  int32_T cmp;
  su = u1[n - 1] & 2147483648U;
  su_0 = u2[n - 1] & 2147483648U;
  if ((su ^ su_0) != 0U) {
    cmp = su != 0U ? -1 : 1;
  } else {
    cmp = 0;
    i = n;
    while ((cmp == 0) && (i > 0)) {
      i--;
      su = u1[i];
      su_0 = u2[i];
      if (su != su_0) {
        cmp = su > su_0 ? 1 : -1;
      }
    }
  }

  return cmp;
}

boolean_T sMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) <= 0 ? (int32_T)TRUE : (int32_T)FALSE;
}

void sMultiWordShrZero(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
  int32_T n)
{
  uint32_T ys;
  boolean_T doRounding = FALSE;
  int32_T nb;
  int32_T i;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (ys != 0U) {
    ys = n2 - 1U;
    nb = (int32_T)(ys >> 5);
    if (nb < n1) {
      doRounding = ((((2U << (ys - (nb << 5))) - 1U) & u1[nb]) != 0U);
    } else {
      nb = n1;
    }

    i = 0;
    while ((!doRounding) && (i < nb)) {
      doRounding = (u1[i] != 0U);
      i++;
    }
  }

  sMultiWordShr(u1, n1, n2, y, n);
  nb = 0;
  while (doRounding && (nb < n)) {
    y[nb]++;
    if (y[nb] != 0U) {
      doRounding = FALSE;
    }

    nb++;
  }
}

/* Model step function for TID0 */
void onboard_matlab_step0(void)        /* Sample time: [0.001s, 0.0s] */
{
  /* local block i/o variables */
  int32_T rtb_Sum3_h;
  int8_T rtb_Sum2;
  boolean_T negate;
  int32_T yn;
  int32_T xtmp;
  int32_T ytmp;
  int32_T rtb_angle_roll;
  int16_T rtb_DataTypeConversion;
  int16_T rtb_Gain10;
  int16_T rtb_Gain14;
  int16_T rtb_Gain15;
  int16_T rtb_Gain16;
  int16_T rtb_Gain17;
  int64m_T rtb_Sum3;
  static const int32_T cordicLUT_n11_s32En[11] = { 843314857, 497837829,
    263043837, 133525159, 67021687, 33543516, 16775851, 8388437, 4194283,
    2097149, 1048576 };

  uint8_T tmp;
  int32_T rtb_IndexVector_idx;
  int16_T rtb_MultiportSwitch_idx;
  int16_T rtb_MultiportSwitch_idx_0;
  int16_T rtb_MultiportSwitch_idx_1;
  int16_T rtb_MultiportSwitch_idx_2;
  int16_T rtb_Saturation4_idx;
  int16_T rtb_Saturation4_idx_0;
  int16_T rtb_Saturation4_idx_1;
  int8_T tmp_0;
  int64m_T tmp_1;
  int64m_T tmp_2;
  uint32_T tmp_3;
  uint32_T tmp_4;
  int224m_T tmp_5;
  int224m_T tmp_6;
  int128m_T tmp_7;
  int128m_T tmp_8;
  int96m_T tmp_9;
  int96m_T tmp_a;
  int64m_T tmp_b;
  int96m_T tmp_c;
  int64m_T tmp_d;
  int64m_T tmp_e;
  int64m_T tmp_f;

  /* Switch: '<S9>/ 2' incorporates:
   *  BusSelector: '<S4>/Bus Selector1'
   *  Constant: '<S9>/   1'
   *  Constant: '<S9>/   2'
   *  Gain: '<S9>/Gain6'
   *  Inport: '<Root>/RC_Data_In'
   */
  if ((onboard_matlab_U.RC_Data_In.CMD_3 << 2) >= 0) {
    rtb_angle_roll = 65536;
  } else {
    rtb_angle_roll = 0;
  }

  /* End of Switch: '<S9>/ 2' */

  /* Sum: '<S9>/Sum3' */
  rtb_Sum3_h = rtb_angle_roll - 65536;

  /* Sum: '<S11>/Sum2' incorporates:
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  Sum: '<S11>/Sum4'
   */
  rtb_IndexVector_idx = rtb_Sum3_h >> 16;
  if (rtb_IndexVector_idx > 127) {
    rtb_IndexVector_idx = 127;
  } else {
    if (rtb_IndexVector_idx < -128) {
      rtb_IndexVector_idx = -128;
    }
  }

  rtb_IndexVector_idx += (onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE >=
    1686629713) + (onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE <=
                   -1686629713);
  if (rtb_IndexVector_idx > 127) {
    rtb_IndexVector_idx = 127;
  }

  rtb_Sum2 = (int8_T)rtb_IndexVector_idx;

  /* End of Sum: '<S11>/Sum2' */

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  if ((rtb_Sum2 != 0) || (onboard_matlab_DWork.DiscreteTimeIntegrator1_PrevRes
                          != 0)) {
    onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE = 0;
  }

  if (onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE >= 1686629713) {
    onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE = 1686629713;
  } else {
    if (onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE <= -1686629713) {
      onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE = -1686629713;
    }
  }

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator2' */
  if ((rtb_Sum3_h != 0) || (onboard_matlab_DWork.DiscreteTimeIntegrator2_PrevRes
       != 0)) {
    onboard_matlab_DWork.DiscreteTimeIntegrator2_DSTATE = 0;
  }

  /* Saturate: '<S9>/Saturation4' incorporates:
   *  BusSelector: '<S7>/Bus Selector'
   *  Inport: '<Root>/UART_Data_In'
   */
  if (onboard_matlab_U.UART_Data_In.uart_ctrl_11 >= 2048) {
    tmp = 2U;
  } else if (onboard_matlab_U.UART_Data_In.uart_ctrl_11 <= 0) {
    tmp = 0U;
  } else {
    tmp = (uint8_T)((int16_T)((onboard_matlab_U.UART_Data_In.uart_ctrl_11 < 0 ?
      1023 : 0) + onboard_matlab_U.UART_Data_In.uart_ctrl_11) >> 10);
  }

  /* End of Saturate: '<S9>/Saturation4' */

  /* Product: '<S9>/Product' */
  tmp_3 = (uint32_T)rtb_angle_roll;
  tmp_4 = tmp;
  ssuMultiWordMul(&tmp_3, 1, &tmp_4, 1, &tmp_2.chunks[0U], 2);

  /* MultiPortSwitch: '<S9>/Index Vector' incorporates:
   *  BusSelector: '<S7>/Bus Selector'
   *  Constant: '<S11>/Amplitude5'
   *  Constant: '<S11>/Amplitude6'
   *  Constant: '<S11>/Amplitude7'
   *  Constant: '<S9>/   '
   *  Gain: '<S11>/Gain9'
   *  Gain: '<S9>/Gain4'
   *  Inport: '<Root>/UART_Data_In'
   */
  sMultiWordShr(&tmp_2.chunks[0U], 2, 16U, &tmp_1.chunks[0U], 2);
  switch (MultiWord2sLong(&tmp_1.chunks[0U])) {
   case 0:
    rtb_angle_roll = 0;
    rtb_IndexVector_idx = 0;
    xtmp = 0;
    ytmp = 0;
    break;

   case 1:
    rtb_angle_roll = 1280 * onboard_matlab_U.UART_Data_In.uart_ctrl_02;
    rtb_IndexVector_idx = 1280 * onboard_matlab_U.UART_Data_In.uart_ctrl_03;
    xtmp = 1280 * onboard_matlab_U.UART_Data_In.uart_ctrl_04;
    ytmp = 1280 * onboard_matlab_U.UART_Data_In.uart_ctrl_05;
    break;

   default:
    /* Trigonometry: '<S11>/Trigonometric Function1' incorporates:
     *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator1'
     */
    if (onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE > 421657428) {
      if (onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE - 843314857 <=
          421657428) {
        rtb_angle_roll = onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE -
          843314857;
        negate = TRUE;
      } else {
        rtb_angle_roll = onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE -
          1686629713;
        negate = FALSE;
      }
    } else if (onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE < -421657428)
    {
      if (onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE + 843314857 >=
          -421657428) {
        rtb_angle_roll = onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE +
          843314857;
        negate = TRUE;
      } else {
        rtb_angle_roll = onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE +
          1686629713;
        negate = FALSE;
      }
    } else {
      rtb_angle_roll = onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE;
      negate = FALSE;
    }

    rtb_angle_roll <<= 2;
    yn = 0;
    rtb_IndexVector_idx = 652032978;
    xtmp = 652032978;
    ytmp = 0;
    for (rtb_Gain10 = 0; rtb_Gain10 < 11; rtb_Gain10++) {
      if (rtb_angle_roll < 0) {
        rtb_angle_roll += cordicLUT_n11_s32En[rtb_Gain10];
        rtb_IndexVector_idx += ytmp;
        yn -= xtmp;
      } else {
        rtb_angle_roll -= cordicLUT_n11_s32En[rtb_Gain10];
        rtb_IndexVector_idx -= ytmp;
        yn += xtmp;
      }

      xtmp = rtb_IndexVector_idx >> (rtb_Gain10 + 1);
      ytmp = yn >> (rtb_Gain10 + 1);
    }

    if (negate) {
      yn = -yn;
    }

    /* RelationalOperator: '<S11>/Relational Operator' incorporates:
     *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator2'
     */
    rtb_IndexVector_idx = onboard_matlab_DWork.DiscreteTimeIntegrator2_DSTATE;

    /* Sum: '<S11>/Sum5' */
    rtb_angle_roll = 65536 + rtb_Sum3_h;
    if ((rtb_Sum3_h > 0) && (rtb_angle_roll <= 0)) {
      rtb_angle_roll = MAX_int32_T;
    }

    /* Gain: '<S11>/Gain9' */
    tmp_7 = onboard_matlab_ConstP.Gain9_Gain;

    /* Product: '<S11>/Product1' incorporates:
     *  Trigonometry: '<S11>/Trigonometric Function1'
     */
    tmp_3 = 29491U;
    tmp_4 = (uint32_T)yn;
    sMultiWordMul(&tmp_3, 1, &tmp_4, 1, &tmp_b.chunks[0U], 2);

    /* Sum: '<S11>/Sum1' incorporates:
     *  Constant: '<S11>/Amplitude2'
     */
    sMultiWord2MultiWord(&tmp_b.chunks[0U], 2, &tmp_a.chunks[0U], 3);
    sLong2MultiWord(uart_up_p_11, &tmp_d.chunks[0U], 2);
    sMultiWordShl(&tmp_d.chunks[0U], 2, 30U, &tmp_b.chunks[0U], 2);
    sMultiWord2MultiWord(&tmp_b.chunks[0U], 2, &tmp_c.chunks[0U], 3);
    MultiWordAdd(&tmp_a.chunks[0U], &tmp_c.chunks[0U], &tmp_9.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&tmp_9.chunks[0U], 3, &tmp_2.chunks[0U], 2);

    /* Product: '<S11>/Product2' incorporates:
     *  Constant: '<S11>/Sweep sinyal suresi'
     *  RelationalOperator: '<S11>/Relational Operator'
     *  Sum: '<S11>/Sum5'
     */
    tmp_3 = (uint32_T)(((rtb_IndexVector_idx & 16) != 0) + (rtb_IndexVector_idx >>
      5) <= uart_up_p_14);
    tmp_4 = (uint32_T)rtb_angle_roll;
    sMultiWordMul(&tmp_3, 1, &tmp_4, 1, &tmp_b.chunks[0U], 2);

    /* Product: '<S11>/Product3' */
    sMultiWordMul(&tmp_2.chunks[0U], 2, &tmp_b.chunks[0U], 2, &tmp_8.chunks[0U],
                  4);

    /* Gain: '<S11>/Gain9' */
    sMultiWordMul(&tmp_7.chunks[0U], 4, &tmp_8.chunks[0U], 4, &tmp_6.chunks[0U],
                  7);
    sMultiWordShr(&tmp_6.chunks[0U], 7, 150U, &tmp_5.chunks[0U], 7);
    rtb_angle_roll = MultiWord2sLong(&tmp_5.chunks[0U]);
    rtb_IndexVector_idx = 0;
    xtmp = 0;
    ytmp = 3276800;
    break;
  }

  /* End of MultiPortSwitch: '<S9>/Index Vector' */

  /* Saturate: '<S2>/Saturation4' */
  if (rtb_angle_roll >= 13107200) {
    rtb_Saturation4_idx = 200;
  } else if (rtb_angle_roll <= 65536) {
    rtb_Saturation4_idx = 1;
  } else {
    rtb_Saturation4_idx = (int16_T)(rtb_angle_roll >> 16);
  }

  if (xtmp >= 13107200) {
    rtb_Saturation4_idx_0 = 200;
  } else if (xtmp <= 65536) {
    rtb_Saturation4_idx_0 = 1;
  } else {
    rtb_Saturation4_idx_0 = (int16_T)(xtmp >> 16);
  }

  if (ytmp >= 13107200) {
    rtb_Saturation4_idx_1 = 200;
  } else if (ytmp <= 65536) {
    rtb_Saturation4_idx_1 = 1;
  } else {
    rtb_Saturation4_idx_1 = (int16_T)(ytmp >> 16);
  }

  if (rtb_IndexVector_idx >= 13107200) {
    rtb_Gain10 = 200;
  } else if (rtb_IndexVector_idx <= 65536) {
    rtb_Gain10 = 1;
  } else {
    rtb_Gain10 = (int16_T)(rtb_IndexVector_idx >> 16);
  }

  /* End of Saturate: '<S2>/Saturation4' */

  /* Outport: '<Root>/LL_CMD_Out' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_LL_CMD_Out_at_inport_0'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant10'
   *  Constant: '<S2>/Constant11'
   *  Constant: '<S2>/Constant12'
   *  Constant: '<S2>/Constant5'
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/Constant7'
   *  Constant: '<S2>/Constant8'
   *  Constant: '<S2>/Constant9'
   */
  onboard_matlab_Y.LL_CMD_Out.motor_rpm_1 = rtb_Saturation4_idx;
  onboard_matlab_Y.LL_CMD_Out.motor_rpm_2 = rtb_Saturation4_idx_0;
  onboard_matlab_Y.LL_CMD_Out.motor_rpm_3 = rtb_Saturation4_idx_1;
  onboard_matlab_Y.LL_CMD_Out.motor_rpm_4 = rtb_Gain10;
  onboard_matlab_Y.LL_CMD_Out.motor_rpm_5 = 0;
  onboard_matlab_Y.LL_CMD_Out.motor_rpm_6 = 0;
  onboard_matlab_Y.LL_CMD_Out.motor_mapped_roll = 100;
  onboard_matlab_Y.LL_CMD_Out.motor_mapped_pitch = 100;
  onboard_matlab_Y.LL_CMD_Out.motor_mapped_yaw = 100;
  onboard_matlab_Y.LL_CMD_Out.motor_mapped_thrust = 0;
  onboard_matlab_Y.LL_CMD_Out.att_cmd_roll = 0;
  onboard_matlab_Y.LL_CMD_Out.att_cmd_pitch = 0;
  onboard_matlab_Y.LL_CMD_Out.att_cmd_yaw = 0;
  onboard_matlab_Y.LL_CMD_Out.att_cmd_thrust = 0;

  /* Outport: '<Root>/CTRL_mode' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_CTRL_mode_at_inport_0'
   *  Constant: '<S2>/Constant13'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   */
  onboard_matlab_Y.CTRL_mode.ctrl_mode = 0U;
  onboard_matlab_Y.CTRL_mode.ctrl_enabled = 1U;
  onboard_matlab_Y.CTRL_mode.disable_motor_onoff_by_stick = 0U;
  onboard_matlab_Y.CTRL_mode.flight_mode = 31;

  /* Gain: '<S11>/Gain' incorporates:
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator2'
   */
  tmp_3 = 1700807049U;
  tmp_4 = (uint32_T)onboard_matlab_DWork.DiscreteTimeIntegrator2_DSTATE;
  sMultiWordMul(&tmp_3, 1, &tmp_4, 1, &tmp_b.chunks[0U], 2);

  /* Sum: '<S11>/Sum3' incorporates:
   *  Constant: '<S11>/Amplitude1'
   */
  sMultiWordShr(&tmp_b.chunks[0U], 2, 6U, &tmp_2.chunks[0U], 2);
  sMultiWord2MultiWord(&tmp_2.chunks[0U], 2, &tmp_a.chunks[0U], 3);
  sLong2MultiWord(uart_up_p_12, &tmp_b.chunks[0U], 2);
  sMultiWordShl(&tmp_b.chunks[0U], 2, 32U, &tmp_2.chunks[0U], 2);
  sMultiWord2MultiWord(&tmp_2.chunks[0U], 2, &tmp_c.chunks[0U], 3);
  MultiWordAdd(&tmp_a.chunks[0U], &tmp_c.chunks[0U], &tmp_9.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&tmp_9.chunks[0U], 3, &rtb_Sum3.chunks[0U], 2);

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  BusSelector: '<S7>/Bus Selector'
   *  Inport: '<Root>/UART_Data_In'
   */
  rtb_DataTypeConversion = (int16_T)(onboard_matlab_U.UART_Data_In.uart_ctrl_12 >>
    10);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S14>/Constant4'
   *  MultiPortSwitch: '<S14>/Index Vector'
   *  Product: '<S14>/Divide'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  if (rtb_DataTypeConversion == 0) {
    rtb_DataTypeConversion = onboard_matlab_ConstP.Constant4_Value[(int16_T)
      div_nzp_s32_ceiling(onboard_matlab_DWork.UnitDelay_DSTATE, 20) - 1];
  }

  /* End of Switch: '<S3>/Switch' */

  /* Gain: '<S3>/Gain10' incorporates:
   *  BusSelector: '<S4>/Bus Selector1'
   *  Inport: '<Root>/RC_Data_In'
   */
  rtb_Gain10 = (int16_T)(onboard_matlab_U.RC_Data_In.CMD_2 >> 5);

  /* Gain: '<S3>/Gain11' incorporates:
   *  BusSelector: '<S4>/Bus Selector1'
   *  Inport: '<Root>/RC_Data_In'
   */
  rtb_Saturation4_idx = (int16_T)(onboard_matlab_U.RC_Data_In.CMD_1 >> 5);

  /* Gain: '<S3>/Gain12' incorporates:
   *  BusSelector: '<S4>/Bus Selector1'
   *  Inport: '<Root>/RC_Data_In'
   */
  rtb_Saturation4_idx_0 = (int16_T)(onboard_matlab_U.RC_Data_In.CMD_4 >> 5);

  /* Gain: '<S3>/Gain13' incorporates:
   *  BusSelector: '<S4>/Bus Selector1'
   *  Inport: '<Root>/RC_Data_In'
   */
  rtb_Saturation4_idx_1 = (int16_T)(onboard_matlab_U.RC_Data_In.CMD_3 >> 5);

  /* Gain: '<S3>/Gain14' incorporates:
   *  BusSelector: '<S4>/Bus Selector1'
   *  Inport: '<Root>/RC_Data_In'
   */
  rtb_Gain14 = (int16_T)(onboard_matlab_U.RC_Data_In.CMD_5 >> 5);

  /* Gain: '<S3>/Gain15' incorporates:
   *  BusSelector: '<S4>/Bus Selector1'
   *  Inport: '<Root>/RC_Data_In'
   */
  rtb_Gain15 = (int16_T)(onboard_matlab_U.RC_Data_In.CMD_6 >> 5);

  /* Gain: '<S3>/Gain16' incorporates:
   *  BusSelector: '<S4>/Bus Selector1'
   *  Inport: '<Root>/RC_Data_In'
   */
  rtb_Gain16 = (int16_T)(onboard_matlab_U.RC_Data_In.CMD_7 >> 5);

  /* Gain: '<S3>/Gain17' incorporates:
   *  BusSelector: '<S4>/Bus Selector1'
   *  Inport: '<Root>/RC_Data_In'
   */
  rtb_Gain17 = (int16_T)(onboard_matlab_U.RC_Data_In.CMD_8 >> 5);

  /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
   *  BusSelector: '<S7>/Bus Selector'
   *  DataTypeConversion: '<S17>/Extract Desired Bits'
   *  Gain: '<S3>/Gain20'
   *  Gain: '<S3>/Gain21'
   *  Gain: '<S3>/Gain22'
   *  Gain: '<S3>/Gain23'
   *  Gain: '<S3>/Gain24'
   *  Gain: '<S3>/Gain25'
   *  Gain: '<S3>/Gain26'
   *  Gain: '<S3>/Gain29'
   *  Gain: '<S3>/Gain30'
   *  Gain: '<S3>/Gain31'
   *  Gain: '<S3>/Gain32'
   *  Gain: '<S3>/Gain33'
   *  Gain: '<S3>/Gain34'
   *  Gain: '<S3>/Gain35'
   *  Gain: '<S3>/Gain36'
   *  Gain: '<S3>/Gain38'
   *  Gain: '<S3>/Gain39'
   *  Gain: '<S3>/Gain40'
   *  Gain: '<S3>/Gain41'
   *  Gain: '<S3>/Gain42'
   *  Gain: '<S3>/Gain48'
   *  Gain: '<S3>/Gain9'
   *  Inport: '<Root>/UART_Data_In'
   */
  switch (rtb_DataTypeConversion) {
   case 1:
    rtb_MultiportSwitch_idx = rtb_Gain10;
    rtb_MultiportSwitch_idx_0 = rtb_Saturation4_idx;
    rtb_MultiportSwitch_idx_1 = rtb_Saturation4_idx_0;
    rtb_MultiportSwitch_idx_2 = rtb_Saturation4_idx_1;
    rtb_Saturation4_idx = onboard_matlab_ConstB.Gain18;
    rtb_Saturation4_idx_0 = onboard_matlab_ConstB.Gain19;
    break;

   case 2:
    /* Gain: '<S8>/Gain' incorporates:
     *  Inport: '<Root>/MOTOR_Data_In'
     */
    rtb_Gain10 = (int16_T)(82U * onboard_matlab_U.MOTOR_Data_In.m1);

    /* Gain: '<S8>/Gain2' incorporates:
     *  Inport: '<Root>/MOTOR_Data_In'
     */
    rtb_Saturation4_idx = (int16_T)(82U * onboard_matlab_U.MOTOR_Data_In.m2);

    /* Gain: '<S8>/Gain1' incorporates:
     *  Inport: '<Root>/MOTOR_Data_In'
     */
    rtb_Saturation4_idx_0 = (int16_T)(82U * onboard_matlab_U.MOTOR_Data_In.m3);

    /* Gain: '<S8>/Gain3' incorporates:
     *  Inport: '<Root>/MOTOR_Data_In'
     */
    rtb_Saturation4_idx_1 = (int16_T)(82U * onboard_matlab_U.MOTOR_Data_In.m4);
    rtb_MultiportSwitch_idx = (int16_T)(rtb_Gain10 >> 5);
    rtb_MultiportSwitch_idx_0 = (int16_T)(rtb_Saturation4_idx >> 5);
    rtb_MultiportSwitch_idx_1 = (int16_T)(rtb_Saturation4_idx_0 >> 5);
    rtb_MultiportSwitch_idx_2 = (int16_T)(rtb_Saturation4_idx_1 >> 5);
    rtb_Gain14 = (int16_T)(rtb_Gain10 >> 5);
    rtb_Gain15 = (int16_T)(rtb_Saturation4_idx >> 5);
    rtb_Gain16 = (int16_T)(rtb_Saturation4_idx_0 >> 5);
    rtb_Gain17 = (int16_T)(rtb_Saturation4_idx_1 >> 5);
    rtb_Saturation4_idx = onboard_matlab_ConstB.Gain27;
    rtb_Saturation4_idx_0 = onboard_matlab_ConstB.Gain28;
    break;

   case 3:
    /* Gain: '<S3>/Gain38' incorporates:
     *  Gain: '<S5>/Gain1'
     *  Inport: '<Root>/GPS_Data_In'
     */
    rtb_IndexVector_idx = mul_s32_s32_s32_sr31_sat_zero(1801439851,
      onboard_matlab_U.GPS_Data_In.gps_longitude) >> 14;
    if (rtb_IndexVector_idx > 32767) {
      rtb_IndexVector_idx = 32767;
    } else {
      if (rtb_IndexVector_idx < -32768) {
        rtb_IndexVector_idx = -32768;
      }
    }

    rtb_MultiportSwitch_idx = (int16_T)rtb_IndexVector_idx;

    /* Gain: '<S3>/Gain29' incorporates:
     *  Gain: '<S3>/Gain38'
     *  Gain: '<S5>/Gain'
     *  Inport: '<Root>/GPS_Data_In'
     */
    rtb_IndexVector_idx = mul_s32_s32_s32_sr30_sat_zero(1801439851,
      onboard_matlab_U.GPS_Data_In.gps_latitude) >> 15;
    if (rtb_IndexVector_idx > 32767) {
      rtb_IndexVector_idx = 32767;
    } else {
      if (rtb_IndexVector_idx < -32768) {
        rtb_IndexVector_idx = -32768;
      }
    }

    rtb_MultiportSwitch_idx_0 = (int16_T)rtb_IndexVector_idx;

    /* Gain: '<S3>/Gain30' incorporates:
     *  Gain: '<S3>/Gain29'
     *  Gain: '<S5>/Gain3'
     *  Inport: '<Root>/GPS_Data_In'
     */
    rtb_IndexVector_idx = mul_s32_s32_s32_sr28_sat_zero(274877907,
      onboard_matlab_U.GPS_Data_In.gps_speed_EW) >> 1;
    if (rtb_IndexVector_idx > 32767) {
      rtb_IndexVector_idx = 32767;
    } else {
      if (rtb_IndexVector_idx < -32768) {
        rtb_IndexVector_idx = -32768;
      }
    }

    rtb_MultiportSwitch_idx_1 = (int16_T)rtb_IndexVector_idx;

    /* Gain: '<S3>/Gain31' incorporates:
     *  Gain: '<S3>/Gain30'
     *  Gain: '<S5>/Gain4'
     *  Inport: '<Root>/GPS_Data_In'
     */
    rtb_IndexVector_idx = mul_s32_s32_s32_sr28_sat_zero(274877907,
      onboard_matlab_U.GPS_Data_In.gps_speed_NS) >> 1;
    if (rtb_IndexVector_idx > 32767) {
      rtb_IndexVector_idx = 32767;
    } else {
      if (rtb_IndexVector_idx < -32768) {
        rtb_IndexVector_idx = -32768;
      }
    }

    rtb_MultiportSwitch_idx_2 = (int16_T)rtb_IndexVector_idx;

    /* DataTypeConversion: '<S17>/Extract Desired Bits' incorporates:
     *  Gain: '<S3>/Gain31'
     *  Inport: '<Root>/GPS_Data_In'
     */
    tmp_0 = (int8_T)onboard_matlab_U.GPS_Data_In.gps_status;
    rtb_Gain14 = (int16_T)((int16_T)((int8_T)(tmp_0 & 2) != 0 ? (int32_T)(int8_T)
                            (tmp_0 | -2) : (int32_T)(int8_T)(tmp_0 & 1)) << 9);
    rtb_Gain15 = (int16_T)(onboard_matlab_U.UART_Data_In.uart_ctrl_06 >> 1);
    rtb_Gain16 = (int16_T)(onboard_matlab_U.UART_Data_In.uart_ctrl_07 >> 1);
    rtb_Gain17 = (int16_T)(onboard_matlab_U.UART_Data_In.uart_ctrl_08 >> 1);
    rtb_Saturation4_idx = (int16_T)(onboard_matlab_U.UART_Data_In.uart_ctrl_09 >>
      1);
    rtb_Saturation4_idx_0 = onboard_matlab_ConstB.Gain37;
    break;

   case 4:
    /* Gain: '<S3>/Gain48' incorporates:
     *  Constant: '<S3>/Constant10'
     */
    rtb_IndexVector_idx = uart_up_p_10 >> 7;
    if (rtb_IndexVector_idx > 32767) {
      rtb_IndexVector_idx = 32767;
    } else {
      if (rtb_IndexVector_idx < -32768) {
        rtb_IndexVector_idx = -32768;
      }
    }

    rtb_MultiportSwitch_idx = (int16_T)rtb_IndexVector_idx;

    /* Gain: '<S3>/Gain39' incorporates:
     *  BusSelector: '<S7>/Bus Selector'
     *  Gain: '<S3>/Gain48'
     *  Gain: '<S3>/Gain59'
     *  Inport: '<Root>/UART_Data_In'
     */
    rtb_IndexVector_idx = 1280 * onboard_matlab_U.UART_Data_In.uart_ctrl_02 >> 7;
    if (rtb_IndexVector_idx > 32767) {
      rtb_IndexVector_idx = 32767;
    } else {
      if (rtb_IndexVector_idx < -32768) {
        rtb_IndexVector_idx = -32768;
      }
    }

    rtb_MultiportSwitch_idx_0 = (int16_T)rtb_IndexVector_idx;

    /* Gain: '<S3>/Gain40' incorporates:
     *  BusSelector: '<S7>/Bus Selector'
     *  Gain: '<S3>/Gain39'
     *  Gain: '<S3>/Gain60'
     *  Inport: '<Root>/UART_Data_In'
     */
    rtb_IndexVector_idx = 1280 * onboard_matlab_U.UART_Data_In.uart_ctrl_03 >> 7;
    if (rtb_IndexVector_idx > 32767) {
      rtb_IndexVector_idx = 32767;
    } else {
      if (rtb_IndexVector_idx < -32768) {
        rtb_IndexVector_idx = -32768;
      }
    }

    rtb_MultiportSwitch_idx_1 = (int16_T)rtb_IndexVector_idx;
    rtb_MultiportSwitch_idx_2 = (int16_T)
      (onboard_matlab_U.UART_Data_In.uart_ctrl_04 >> 1);
    rtb_Gain14 = (int16_T)(onboard_matlab_U.UART_Data_In.uart_ctrl_05 >> 1);
    rtb_Gain15 = onboard_matlab_ConstB.Gain43;
    rtb_Gain16 = onboard_matlab_ConstB.Gain44;
    rtb_Gain17 = onboard_matlab_ConstB.Gain45;
    rtb_Saturation4_idx = onboard_matlab_ConstB.Gain46;
    rtb_Saturation4_idx_0 = onboard_matlab_ConstB.Gain47;
    break;

   case 5:
    rtb_MultiportSwitch_idx = onboard_matlab_ConstB.Gain58;
    rtb_MultiportSwitch_idx_0 = onboard_matlab_ConstB.Gain49;
    rtb_MultiportSwitch_idx_1 = onboard_matlab_ConstB.Gain50;
    rtb_MultiportSwitch_idx_2 = onboard_matlab_ConstB.Gain51;
    rtb_Gain14 = onboard_matlab_ConstB.Gain52;
    rtb_Gain15 = onboard_matlab_ConstB.Gain53;
    rtb_Gain16 = onboard_matlab_ConstB.Gain54;
    rtb_Gain17 = onboard_matlab_ConstB.Gain55;
    rtb_Saturation4_idx = onboard_matlab_ConstB.Gain56;
    rtb_Saturation4_idx_0 = onboard_matlab_ConstB.Gain57;
    break;

   default:
    rtb_MultiportSwitch_idx = rtb_Gain10;
    rtb_MultiportSwitch_idx_0 = rtb_Saturation4_idx;
    rtb_MultiportSwitch_idx_1 = rtb_Saturation4_idx_0;
    rtb_MultiportSwitch_idx_2 = rtb_Saturation4_idx_1;
    rtb_Saturation4_idx = onboard_matlab_ConstB.Gain18;
    rtb_Saturation4_idx_0 = onboard_matlab_ConstB.Gain19;
    break;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

  /* Outport: '<Root>/UART_Data_Out' incorporates:
   *  BusCreator: '<Root>/BusConversion_InsertedFor_UART_Data_Out_at_inport_0'
   *  BusSelector: '<S6>/Bus Selector'
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain1'
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain3'
   *  Gain: '<S3>/Gain4'
   *  Gain: '<S3>/Gain5'
   *  Gain: '<S3>/Gain6'
   *  Gain: '<S3>/Gain7'
   *  Gain: '<S3>/Gain8'
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Gain: '<S6>/Gain2'
   *  Gain: '<S6>/Gain3'
   *  Gain: '<S6>/Gain4'
   *  Gain: '<S6>/Gain5'
   *  Gain: '<S6>/Gain6'
   *  Gain: '<S6>/Gain7'
   *  Gain: '<S6>/Gain8'
   *  Inport: '<Root>/IMU_Data_In'
   */
  onboard_matlab_Y.UART_Data_Out.uart_debug_01 = (int16_T)((int16_T)
    mul_s32_s32_s32_sr30(307041569, onboard_matlab_U.IMU_Data_In.angle_roll) >>
    5);
  onboard_matlab_Y.UART_Data_Out.uart_debug_02 = (int16_T)((int16_T)
    mul_s32_s32_s32_sr30(307041569, onboard_matlab_U.IMU_Data_In.angle_pitch) >>
    5);
  onboard_matlab_Y.UART_Data_Out.uart_debug_03 = (int16_T)((int16_T)
    mul_s32_s32_s32_sr32(307041569, onboard_matlab_U.IMU_Data_In.angle_yaw) >> 3);
  onboard_matlab_Y.UART_Data_Out.uart_debug_04 = (int16_T)((int16_T)
    mul_s32_s32_s32_sr30(1184573955, onboard_matlab_U.IMU_Data_In.angvel_roll) >>
    3);
  onboard_matlab_Y.UART_Data_Out.uart_debug_05 = (int16_T)((int16_T)
    mul_s32_s32_s32_sr30(1184573955, onboard_matlab_U.IMU_Data_In.angvel_pitch) >>
    3);
  onboard_matlab_Y.UART_Data_Out.uart_debug_06 = (int16_T)((int16_T)
    mul_s32_s32_s32_sr30(1184573955, onboard_matlab_U.IMU_Data_In.angvel_yaw) >>
    3);
  onboard_matlab_Y.UART_Data_Out.uart_debug_07 = (int16_T)((int16_T)(16777 *
    onboard_matlab_U.IMU_Data_In.acc_x >> 14) >> 1);
  onboard_matlab_Y.UART_Data_Out.uart_debug_08 = (int16_T)((int16_T)(16777 *
    onboard_matlab_U.IMU_Data_In.acc_y >> 14) >> 1);
  onboard_matlab_Y.UART_Data_Out.uart_debug_09 = (int16_T)((int16_T)(16777 *
    onboard_matlab_U.IMU_Data_In.acc_z >> 14) >> 1);
  onboard_matlab_Y.UART_Data_Out.uart_debug_10 = rtb_DataTypeConversion;
  onboard_matlab_Y.UART_Data_Out.uart_debug_11 = rtb_MultiportSwitch_idx;
  onboard_matlab_Y.UART_Data_Out.uart_debug_12 = rtb_MultiportSwitch_idx_0;
  onboard_matlab_Y.UART_Data_Out.uart_debug_13 = rtb_MultiportSwitch_idx_1;
  onboard_matlab_Y.UART_Data_Out.uart_debug_14 = rtb_MultiportSwitch_idx_2;
  onboard_matlab_Y.UART_Data_Out.uart_debug_15 = rtb_Gain14;
  onboard_matlab_Y.UART_Data_Out.uart_debug_16 = rtb_Gain15;
  onboard_matlab_Y.UART_Data_Out.uart_debug_17 = rtb_Gain16;
  onboard_matlab_Y.UART_Data_Out.uart_debug_18 = rtb_Gain17;
  onboard_matlab_Y.UART_Data_Out.uart_debug_19 = rtb_Saturation4_idx;
  onboard_matlab_Y.UART_Data_Out.uart_debug_20 = rtb_Saturation4_idx_0;

  /* Sum: '<S14>/Sum' incorporates:
   *  UnitDelay: '<S14>/Unit Delay'
   */
  rtb_Gain10 = (int16_T)(onboard_matlab_DWork.UnitDelay_DSTATE + 1);

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
  if (rtb_Sum2 == 0) {
    /* Saturate: '<S11>/Saturation4' */
    sLong2MultiWord(32767, &tmp_a.chunks[0U], 3);
    sMultiWordShl(&tmp_a.chunks[0U], 3, 38U, &tmp_9.chunks[0U], 3);
    sMultiWord2MultiWord(&tmp_9.chunks[0U], 3, &tmp_2.chunks[0U], 2);
    if (sMultiWordGe(&rtb_Sum3.chunks[0U], &tmp_2.chunks[0U], 2)) {
      rtb_Saturation4_idx = MAX_int16_T;
    } else {
      sLong2MultiWord(0, &tmp_a.chunks[0U], 3);
      sMultiWordShl(&tmp_a.chunks[0U], 3, 38U, &tmp_9.chunks[0U], 3);
      sMultiWord2MultiWord(&tmp_9.chunks[0U], 3, &tmp_b.chunks[0U], 2);
      if (sMultiWordLe(&rtb_Sum3.chunks[0U], &tmp_b.chunks[0U], 2)) {
        rtb_Saturation4_idx = 0;
      } else {
        sMultiWordShrZero(&rtb_Sum3.chunks[0U], 2, 38U, &tmp_d.chunks[0U], 2);
        rtb_Saturation4_idx = (int16_T)MultiWord2sLong(&tmp_d.chunks[0U]);
      }
    }

    /* End of Saturate: '<S11>/Saturation4' */
    tmp_2 = onboard_matlab_ConstP.DiscreteTimeIntegrator1_ga;

    /* Product: '<S11>/Product' incorporates:
     *  Gain: '<S11>/Gain1'
     */
    sLong2MultiWord(25736 * rtb_Saturation4_idx, &tmp_f.chunks[0U], 2);
    sMultiWordShl(&tmp_f.chunks[0U], 2, 8U, &tmp_e.chunks[0U], 2);
    sMultiWordMul(&tmp_2.chunks[0U], 2, &tmp_e.chunks[0U], 2, &tmp_8.chunks[0U],
                  4);
    sMultiWordShrZero(&tmp_8.chunks[0U], 4, 62U, &tmp_7.chunks[0U], 4);
    onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE += MultiWord2sLong
      (&tmp_7.chunks[0U]);
    if (onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE >= 1686629713) {
      onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE = 1686629713;
    } else {
      if (onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE <= -1686629713) {
        onboard_matlab_DWork.DiscreteTimeIntegrator1_DSTATE = -1686629713;
      }
    }
  }

  if (rtb_Sum2 > 0) {
    onboard_matlab_DWork.DiscreteTimeIntegrator1_PrevRes = 1;
  } else if (rtb_Sum2 < 0) {
    onboard_matlab_DWork.DiscreteTimeIntegrator1_PrevRes = -1;
  } else {
    onboard_matlab_DWork.DiscreteTimeIntegrator1_PrevRes = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator2' */
  if (rtb_Sum3_h == 0) {
    onboard_matlab_DWork.DiscreteTimeIntegrator2_DSTATE += 2097;
  }

  if (rtb_Sum3_h > 0) {
    onboard_matlab_DWork.DiscreteTimeIntegrator2_PrevRes = 1;
  } else if (rtb_Sum3_h < 0) {
    onboard_matlab_DWork.DiscreteTimeIntegrator2_PrevRes = -1;
  } else {
    onboard_matlab_DWork.DiscreteTimeIntegrator2_PrevRes = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator2' */

  /* Switch: '<S14>/FixPt Switch' */
  if (rtb_Gain10 > 100) {
    /* Update for UnitDelay: '<S14>/Unit Delay' incorporates:
     *  Constant: '<S14>/Constant1'
     */
    onboard_matlab_DWork.UnitDelay_DSTATE = 1;
  } else {
    /* Update for UnitDelay: '<S14>/Unit Delay' */
    onboard_matlab_DWork.UnitDelay_DSTATE = rtb_Gain10;
  }

  /* End of Switch: '<S14>/FixPt Switch' */
}

/* Model step function for TID1 */
void onboard_matlab_step1(void)        /* Sample time: [0.002s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void onboard_matlab_initialize(void)
{
  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
  onboard_matlab_DWork.UnitDelay_DSTATE = 1;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
