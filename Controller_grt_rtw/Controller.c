/*
 * Controller.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Controller".
 *
 * Model version              : 1.161
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Mar 20 20:01:30 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "Controller.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "Controller_private.h"
#include <emmintrin.h>
#include "rt_defines.h"

/* Block signals (default storage) */
B_Controller_T Controller_B;

/* Block states (default storage) */
DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controller_T Controller_Y;

/* Real-time model */
static RT_MODEL_Controller_T Controller_M_;
RT_MODEL_Controller_T *const Controller_M = &Controller_M_;

/* Forward declaration for local functions */
static real_T Controller_norm(const real_T x[2]);
static real_T Controller_closestPointOnLine(const real_T pt1[2], real_T pt2[2],
  const real_T refPt[2]);
static real_T Controller_norm(const real_T x[2])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  boolean_T b;
  scale = 3.3121686421112381E-170;

  /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  y = scale * sqrt(y);

  /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
  b = rtIsNaN(y);
  if (b) {
    int32_T b_k;
    b_k = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (b_k < 2) {
        if (rtIsNaN(x[b_k])) {
          exitg1 = 1;
        } else {
          b_k++;
        }
      } else {
        y = (rtInf);
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return y;
}

static real_T Controller_closestPointOnLine(const real_T pt1[2], real_T pt2[2],
  const real_T refPt[2])
{
  __m128d tmp;
  real_T refPt_0[2];
  real_T alpha;
  real_T distance;
  real_T v12;
  real_T v12_0;
  real_T v12_1;
  int32_T b_k;
  boolean_T exitg1;
  boolean_T p;
  boolean_T p_0;

  /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 2)) {
    if (!(pt1[b_k] == pt2[b_k])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (p) {
    alpha = pt1[0];
    pt2[0] = alpha;
    refPt_0[0] = refPt[0] - alpha;
    alpha = pt1[1];
    pt2[1] = alpha;
    refPt_0[1] = refPt[1] - alpha;
    distance = Controller_norm(refPt_0);
  } else {
    alpha = pt2[0];
    v12_1 = alpha - pt1[0];
    v12 = (alpha - refPt[0]) * v12_1;
    v12_0 = v12_1 * v12_1;
    alpha = pt2[1];
    v12_1 = alpha - pt1[1];
    v12 += (alpha - refPt[1]) * v12_1;
    v12_0 += v12_1 * v12_1;
    alpha = v12 / v12_0;
    if (alpha > 1.0) {
      pt2[0] = pt1[0];
      pt2[1] = pt1[1];
    } else if (!(alpha < 0.0)) {
      v12_1 = 1.0 - alpha;
      tmp = _mm_add_pd(_mm_mul_pd(_mm_set1_pd(alpha), _mm_loadu_pd(&pt1[0])),
                       _mm_mul_pd(_mm_set1_pd(v12_1), _mm_loadu_pd(&pt2[0])));
      _mm_storeu_pd(&pt2[0], tmp);
    }

    tmp = _mm_sub_pd(_mm_loadu_pd(&refPt[0]), _mm_loadu_pd(&pt2[0]));
    _mm_storeu_pd(&refPt_0[0], tmp);
    distance = Controller_norm(refPt_0);
  }

  /* End of Start for MATLABSystem: '<S1>/Pure Pursuit' */
  return distance;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void Controller_step(void)
{
  __m128d tmp_0;
  __m128d tmp_1;
  real_T waypoints_data[200];
  real_T lookaheadStartPt[2];
  real_T tmp[2];
  real_T waypoints[2];
  real_T waypoints_0[2];
  real_T dist;
  real_T lookaheadEndPt_idx_0;
  real_T lookaheadEndPt_idx_1;
  real_T lookaheadIdx;
  real_T lookaheadStartPt_tmp;
  real_T minDistance;
  int32_T b_k;
  int32_T i;
  int32_T scalarLB;
  int32_T tmp_size_idx_0;
  int32_T trueCount;
  int32_T vectorUB;
  int8_T tmp_data[100];
  boolean_T b[200];
  boolean_T nanidx_tmp[100];
  boolean_T exitg1;
  boolean_T p;
  boolean_T searchFlag;

  /* Sum: '<S2>/Subtract' incorporates:
   *  Inport: '<Root>/fb_currentPose'
   *  Inport: '<Root>/robotGoal'
   */
  minDistance = Controller_U.fb_currentPose[0] - Controller_U.robotGoal[0];
  Controller_B.Subtract[0] = minDistance;

  /* DotProduct: '<S2>/Dot Product' */
  dist = minDistance * minDistance;

  /* Sum: '<S2>/Subtract' incorporates:
   *  Inport: '<Root>/fb_currentPose'
   *  Inport: '<Root>/robotGoal'
   */
  minDistance = Controller_U.fb_currentPose[1] - Controller_U.robotGoal[1];
  Controller_B.Subtract[1] = minDistance;

  /* DotProduct: '<S2>/Dot Product' */
  dist += minDistance * minDistance;

  /* DotProduct: '<S2>/Dot Product' */
  Controller_B.DotProduct = dist;

  /* Sqrt: '<S2>/Sqrt' */
  Controller_B.Sqrt = sqrt(Controller_B.DotProduct);

  /* Outport: '<Root>/atGoal' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Less Than'
   */
  Controller_Y.atGoal = (Controller_B.Sqrt > 0.75);

  /* MATLABSystem: '<S1>/Pure Pursuit' incorporates:
   *  Inport: '<Root>/Waypints'
   */
  if (Controller_DW.obj.DesiredLinearVelocity != 2.0) {
    Controller_DW.obj.DesiredLinearVelocity = 2.0;
  }

  if (Controller_DW.obj.MaxAngularVelocity != 7.0) {
    Controller_DW.obj.MaxAngularVelocity = 7.0;
  }

  if (Controller_DW.obj.LookaheadDistance != 0.5) {
    Controller_DW.obj.LookaheadDistance = 0.5;
  }

  searchFlag = false;
  p = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 200)) {
    if ((Controller_DW.obj.WaypointsInternal[b_k] == Controller_U.planOutput[b_k])
        || (rtIsNaN(Controller_DW.obj.WaypointsInternal[b_k]) && rtIsNaN
            (Controller_U.planOutput[b_k]))) {
      b_k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (p) {
    searchFlag = true;
  }

  if (!searchFlag) {
    memcpy(&Controller_DW.obj.WaypointsInternal[0], &Controller_U.planOutput[0],
           200U * sizeof(real_T));
    Controller_DW.obj.ProjectionLineIndex = 0.0;
  }

  for (b_k = 0; b_k < 200; b_k++) {
    b[b_k] = !rtIsNaN(Controller_U.planOutput[b_k]);
  }

  trueCount = 0;
  for (b_k = 0; b_k < 100; b_k++) {
    /* MATLABSystem: '<S1>/Pure Pursuit' */
    searchFlag = (b[b_k] && b[b_k + 100]);
    nanidx_tmp[b_k] = searchFlag;

    /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
    if (searchFlag) {
      trueCount++;
    }
  }

  tmp_size_idx_0 = trueCount;
  trueCount = 0;
  for (b_k = 0; b_k < 100; b_k++) {
    /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
    if (nanidx_tmp[b_k]) {
      tmp_data[trueCount] = (int8_T)b_k;
      trueCount++;
    }
  }

  /* MATLABSystem: '<S1>/Pure Pursuit' incorporates:
   *  Inport: '<Root>/Waypints'
   *  Inport: '<Root>/fb_currentPose'
   * */
  trueCount = tmp_size_idx_0;
  for (b_k = 0; b_k < 2; b_k++) {
    scalarLB = (trueCount / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      waypoints_data[i + tmp_size_idx_0 * b_k] = Controller_U.planOutput[100 *
        b_k + tmp_data[i]];
      waypoints_data[(i + tmp_size_idx_0 * b_k) + 1] = Controller_U.planOutput
        [100 * b_k + tmp_data[i + 1]];
    }

    for (i = scalarLB; i < trueCount; i++) {
      waypoints_data[i + tmp_size_idx_0 * b_k] = Controller_U.planOutput[100 *
        b_k + tmp_data[i]];
    }
  }

  if (tmp_size_idx_0 == 0) {
    dist = 0.0;
    minDistance = 0.0;
  } else {
    searchFlag = false;
    if (Controller_DW.obj.ProjectionLineIndex == 0.0) {
      searchFlag = true;
      Controller_DW.obj.ProjectionPoint[0] = waypoints_data[0];
      Controller_DW.obj.ProjectionPoint[1] = waypoints_data[tmp_size_idx_0];
      Controller_DW.obj.ProjectionLineIndex = 1.0;
    }

    if (tmp_size_idx_0 == 1) {
      Controller_DW.obj.ProjectionPoint[0] = waypoints_data[0];
      Controller_DW.obj.ProjectionPoint[1] = waypoints_data[tmp_size_idx_0];
      lookaheadEndPt_idx_0 = waypoints_data[0];
      lookaheadEndPt_idx_1 = waypoints_data[tmp_size_idx_0];
    } else {
      b_k = (int32_T)(Controller_DW.obj.ProjectionLineIndex + 1.0);
      lookaheadStartPt_tmp = waypoints_data[b_k - 1];
      lookaheadStartPt[0] = lookaheadStartPt_tmp;
      dist = waypoints_data[(b_k + tmp_size_idx_0) - 1];
      lookaheadStartPt[1] = dist;
      minDistance = Controller_closestPointOnLine
        (Controller_DW.obj.ProjectionPoint, lookaheadStartPt,
         &Controller_U.fb_currentPose[0]);
      lookaheadIdx = lookaheadStartPt[0];
      Controller_DW.obj.ProjectionPoint[0] = lookaheadIdx;
      waypoints[0] = lookaheadIdx - lookaheadStartPt_tmp;
      lookaheadIdx = lookaheadStartPt[1];
      Controller_DW.obj.ProjectionPoint[1] = lookaheadIdx;
      waypoints[1] = lookaheadIdx - dist;
      dist = Controller_norm(waypoints);
      lookaheadIdx = Controller_DW.obj.ProjectionLineIndex + 1.0;
      b_k = (int32_T)((1.0 - (Controller_DW.obj.ProjectionLineIndex + 1.0)) +
                      ((real_T)tmp_size_idx_0 - 1.0)) - 1;
      trueCount = 0;
      exitg1 = false;
      while ((!exitg1) && (trueCount <= b_k)) {
        lookaheadStartPt_tmp = lookaheadIdx + (real_T)trueCount;
        if ((!searchFlag) && (dist > Controller_DW.obj.LookaheadDistance)) {
          exitg1 = true;
        } else {
          scalarLB = (int32_T)lookaheadStartPt_tmp;
          vectorUB = (int32_T)(lookaheadStartPt_tmp + 1.0);
          lookaheadEndPt_idx_0 = waypoints_data[vectorUB - 1];
          lookaheadEndPt_idx_1 = waypoints_data[scalarLB - 1];
          waypoints[0] = lookaheadEndPt_idx_1 - lookaheadEndPt_idx_0;
          lookaheadStartPt[0] = lookaheadEndPt_idx_0;
          waypoints_0[0] = lookaheadEndPt_idx_1;
          lookaheadEndPt_idx_0 = waypoints_data[(vectorUB + tmp_size_idx_0) - 1];
          lookaheadEndPt_idx_1 = waypoints_data[(scalarLB + tmp_size_idx_0) - 1];
          waypoints[1] = lookaheadEndPt_idx_1 - lookaheadEndPt_idx_0;
          lookaheadStartPt[1] = lookaheadEndPt_idx_0;
          waypoints_0[1] = lookaheadEndPt_idx_1;
          dist += Controller_norm(waypoints);
          lookaheadEndPt_idx_0 = Controller_closestPointOnLine(waypoints_0,
            lookaheadStartPt, &Controller_U.fb_currentPose[0]);
          if (lookaheadEndPt_idx_0 < minDistance) {
            minDistance = lookaheadEndPt_idx_0;
            Controller_DW.obj.ProjectionPoint[0] = lookaheadStartPt[0];
            Controller_DW.obj.ProjectionPoint[1] = lookaheadStartPt[1];
            Controller_DW.obj.ProjectionLineIndex = lookaheadStartPt_tmp;
          }

          trueCount++;
        }
      }

      b_k = (int32_T)(Controller_DW.obj.ProjectionLineIndex + 1.0);
      lookaheadEndPt_idx_0 = waypoints_data[b_k - 1];
      lookaheadEndPt_idx_1 = waypoints_data[(b_k + tmp_size_idx_0) - 1];
      tmp_1 = _mm_sub_pd(_mm_loadu_pd(&Controller_DW.obj.ProjectionPoint[0]),
                         _mm_set_pd(lookaheadEndPt_idx_1, lookaheadEndPt_idx_0));
      _mm_storeu_pd(&waypoints[0], tmp_1);
      dist = Controller_norm(waypoints);
      lookaheadStartPt[0] = Controller_DW.obj.ProjectionPoint[0];
      lookaheadStartPt[1] = Controller_DW.obj.ProjectionPoint[1];
      minDistance = dist - Controller_DW.obj.LookaheadDistance;
      lookaheadIdx = Controller_DW.obj.ProjectionLineIndex;
      while ((minDistance < 0.0) && (lookaheadIdx < (real_T)tmp_size_idx_0 - 1.0))
      {
        lookaheadIdx++;
        b_k = (int32_T)lookaheadIdx;
        trueCount = (int32_T)(lookaheadIdx + 1.0);
        lookaheadStartPt_tmp = waypoints_data[b_k - 1];
        lookaheadStartPt[0] = lookaheadStartPt_tmp;
        lookaheadEndPt_idx_0 = waypoints_data[trueCount - 1];
        waypoints[0] = lookaheadStartPt_tmp - lookaheadEndPt_idx_0;
        lookaheadStartPt_tmp = waypoints_data[(b_k + tmp_size_idx_0) - 1];
        lookaheadStartPt[1] = lookaheadStartPt_tmp;
        lookaheadEndPt_idx_1 = waypoints_data[(trueCount + tmp_size_idx_0) - 1];
        waypoints[1] = lookaheadStartPt_tmp - lookaheadEndPt_idx_1;
        dist += Controller_norm(waypoints);
        minDistance = dist - Controller_DW.obj.LookaheadDistance;
      }

      tmp_1 = _mm_set_pd(lookaheadEndPt_idx_1, lookaheadEndPt_idx_0);
      tmp_0 = _mm_sub_pd(_mm_loadu_pd(&lookaheadStartPt[0]), tmp_1);
      _mm_storeu_pd(&waypoints[0], tmp_0);
      dist = minDistance / Controller_norm(waypoints);
      if (dist > 0.0) {
        minDistance = 1.0 - dist;
        tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_set1_pd(dist), _mm_loadu_pd
          (&lookaheadStartPt[0])), _mm_mul_pd(_mm_set1_pd(minDistance), tmp_1));
        _mm_storeu_pd(&tmp[0], tmp_1);
        lookaheadEndPt_idx_0 = tmp[0];
        lookaheadEndPt_idx_1 = tmp[1];
      }
    }

    Controller_DW.obj.LookaheadPoint[0] = lookaheadEndPt_idx_0;
    Controller_DW.obj.LookaheadPoint[1] = lookaheadEndPt_idx_1;
    dist = rt_atan2d_snf(Controller_DW.obj.LookaheadPoint[1] -
                         Controller_U.fb_currentPose[1],
                         Controller_DW.obj.LookaheadPoint[0] -
                         Controller_U.fb_currentPose[0]) -
      Controller_U.fb_currentPose[2];
    searchFlag = !(fabs(dist) > 3.1415926535897931);
    if (!searchFlag) {
      if (rtIsNaN(dist + 3.1415926535897931) || rtIsInf(dist +
           3.1415926535897931)) {
        minDistance = (rtNaN);
      } else if (dist + 3.1415926535897931 == 0.0) {
        minDistance = 0.0;
      } else {
        minDistance = fmod(dist + 3.1415926535897931, 6.2831853071795862);
        searchFlag = (minDistance == 0.0);
        if (!searchFlag) {
          lookaheadIdx = fabs((dist + 3.1415926535897931) / 6.2831853071795862);
          searchFlag = !(fabs(lookaheadIdx - floor(lookaheadIdx + 0.5)) >
                         2.2204460492503131E-16 * lookaheadIdx);
        }

        if (searchFlag) {
          minDistance = 0.0;
        } else if (minDistance < 0.0) {
          minDistance += 6.2831853071795862;
        }
      }

      if ((minDistance == 0.0) && (dist + 3.1415926535897931 > 0.0)) {
        minDistance = 6.2831853071795862;
      }

      dist = minDistance - 3.1415926535897931;
    }

    minDistance = 2.0 * sin(dist) / Controller_DW.obj.LookaheadDistance;
    searchFlag = rtIsNaN(minDistance);
    if (searchFlag) {
      minDistance = 0.0;
    }

    if (fabs(fabs(dist) - 3.1415926535897931) < 1.4901161193847656E-8) {
      if (rtIsNaN(minDistance)) {
        minDistance = (rtNaN);
      } else if (minDistance < 0.0) {
        minDistance = -1.0;
      } else {
        minDistance = (minDistance > 0.0);
      }
    }

    if (fabs(minDistance) > Controller_DW.obj.MaxAngularVelocity) {
      if (rtIsNaN(minDistance)) {
        minDistance = (rtNaN);
      } else if (minDistance < 0.0) {
        minDistance = -1.0;
      } else {
        minDistance = (minDistance > 0.0);
      }

      minDistance *= Controller_DW.obj.MaxAngularVelocity;
    }

    dist = Controller_DW.obj.DesiredLinearVelocity;
    Controller_DW.obj.LastPose[0] = Controller_U.fb_currentPose[0];
    Controller_DW.obj.LastPose[1] = Controller_U.fb_currentPose[1];
    Controller_DW.obj.LastPose[2] = Controller_U.fb_currentPose[2];
  }

  lookaheadStartPt[0] = dist;
  lookaheadStartPt[1] = minDistance;
  dist = lookaheadStartPt[0];
  minDistance = lookaheadStartPt[1];

  /* MATLABSystem: '<S1>/Pure Pursuit' */
  Controller_B.PurePursuit_o1 = dist;

  /* MATLABSystem: '<S1>/Pure Pursuit' */
  Controller_B.PurePursuit_o2 = minDistance;

  /* Product: '<S5>/Product' incorporates:
   *  Outport: '<Root>/atGoal'
   */
  Controller_B.Product = (real_T)Controller_Y.atGoal *
    Controller_B.PurePursuit_o1;

  /* Sum: '<S4>/Sum' incorporates:
   *  Inport: '<Root>/fb_spd'
   */
  Controller_B.e_spd = Controller_B.Product - Controller_U.fb_spd_LPF;

  /* Gain: '<S103>/Proportional Gain' incorporates:
   *  Gain: '<S95>/Integral Gain'
   */
  minDistance = 0.1 * Controller_B.e_spd;

  /* Gain: '<S103>/Proportional Gain' */
  Controller_B.ProportionalGain = minDistance;

  /* DiscreteIntegrator: '<S98>/Integrator' */
  Controller_B.Integrator = Controller_DW.Integrator_DSTATE;

  /* Sum: '<S107>/Sum' */
  Controller_B.Sum = Controller_B.ProportionalGain + Controller_B.Integrator;

  /* Saturate: '<S105>/Saturation' */
  dist = Controller_B.Sum;
  if (dist > 1.0) {
    /* Outport: '<Root>/u_spd' */
    Controller_Y.u_spd = 1.0;
  } else if (dist < -1.0) {
    /* Outport: '<Root>/u_spd' */
    Controller_Y.u_spd = -1.0;
  } else {
    /* Outport: '<Root>/u_spd' */
    Controller_Y.u_spd = dist;
  }

  /* End of Saturate: '<S105>/Saturation' */

  /* Product: '<S5>/Product1' incorporates:
   *  Outport: '<Root>/atGoal'
   */
  Controller_B.Product1 = (real_T)Controller_Y.atGoal *
    Controller_B.PurePursuit_o2;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Inport: '<Root>/fb_dotw'
   */
  Controller_B.e_dotw = Controller_B.Product1 - Controller_U.fb_dotw;

  /* DiscreteIntegrator: '<S43>/Integrator' */
  Controller_B.Integrator_j = Controller_DW.Integrator_DSTATE_c;

  /* Sum: '<S52>/Sum' */
  Controller_B.Sum_g = Controller_B.e_dotw + Controller_B.Integrator_j;

  /* Saturate: '<S50>/Saturation' */
  dist = Controller_B.Sum_g;
  if (dist > 1.0) {
    /* Outport: '<Root>/u_dotw' */
    Controller_Y.u_dotw = 1.0;
  } else if (dist < -1.0) {
    /* Outport: '<Root>/u_dotw' */
    Controller_Y.u_dotw = -1.0;
  } else {
    /* Outport: '<Root>/u_dotw' */
    Controller_Y.u_dotw = dist;
  }

  /* End of Saturate: '<S50>/Saturation' */

  /* DeadZone: '<S35>/DeadZone' */
  if (Controller_B.Sum_g > 1.0) {
    /* DeadZone: '<S35>/DeadZone' */
    Controller_B.DeadZone = Controller_B.Sum_g - 1.0;
  } else if (Controller_B.Sum_g >= -1.0) {
    /* DeadZone: '<S35>/DeadZone' */
    Controller_B.DeadZone = 0.0;
  } else {
    /* DeadZone: '<S35>/DeadZone' */
    Controller_B.DeadZone = Controller_B.Sum_g - -1.0;
  }

  /* End of DeadZone: '<S35>/DeadZone' */

  /* RelationalOperator: '<S33>/Relational Operator' incorporates:
   *  Constant: '<S33>/Clamping_zero'
   */
  Controller_B.RelationalOperator = (Controller_B.DeadZone != 0.0);

  /* RelationalOperator: '<S33>/fix for DT propagation issue' incorporates:
   *  Constant: '<S33>/Clamping_zero'
   */
  Controller_B.fixforDTpropagationissue = (Controller_B.DeadZone > 0.0);

  /* Switch: '<S33>/Switch1' */
  if (Controller_B.fixforDTpropagationissue) {
    /* Switch: '<S33>/Switch1' incorporates:
     *  Constant: '<S33>/Constant'
     */
    Controller_B.Switch1 = 1;
  } else {
    /* Switch: '<S33>/Switch1' incorporates:
     *  Constant: '<S33>/Constant2'
     */
    Controller_B.Switch1 = -1;
  }

  /* End of Switch: '<S33>/Switch1' */

  /* Gain: '<S40>/Integral Gain' */
  Controller_B.IntegralGain = 0.01 * Controller_B.e_dotw;

  /* RelationalOperator: '<S33>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S33>/Clamping_zero'
   */
  Controller_B.fixforDTpropagationissue1 = (Controller_B.IntegralGain > 0.0);

  /* Switch: '<S33>/Switch2' */
  if (Controller_B.fixforDTpropagationissue1) {
    /* Switch: '<S33>/Switch2' incorporates:
     *  Constant: '<S33>/Constant3'
     */
    Controller_B.Switch2 = 1;
  } else {
    /* Switch: '<S33>/Switch2' incorporates:
     *  Constant: '<S33>/Constant4'
     */
    Controller_B.Switch2 = -1;
  }

  /* End of Switch: '<S33>/Switch2' */

  /* RelationalOperator: '<S33>/Equal1' */
  Controller_B.Equal1 = (Controller_B.Switch1 == Controller_B.Switch2);

  /* Logic: '<S33>/AND3' */
  Controller_B.AND3 = (Controller_B.RelationalOperator && Controller_B.Equal1);

  /* Switch: '<S33>/Switch' */
  if (Controller_B.AND3) {
    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S33>/Constant1'
     */
    Controller_B.Switch = 0.0;
  } else {
    /* Switch: '<S33>/Switch' */
    Controller_B.Switch = Controller_B.IntegralGain;
  }

  /* End of Switch: '<S33>/Switch' */

  /* DeadZone: '<S90>/DeadZone' */
  if (Controller_B.Sum > 1.0) {
    /* DeadZone: '<S90>/DeadZone' */
    Controller_B.DeadZone_j = Controller_B.Sum - 1.0;
  } else if (Controller_B.Sum >= -1.0) {
    /* DeadZone: '<S90>/DeadZone' */
    Controller_B.DeadZone_j = 0.0;
  } else {
    /* DeadZone: '<S90>/DeadZone' */
    Controller_B.DeadZone_j = Controller_B.Sum - -1.0;
  }

  /* End of DeadZone: '<S90>/DeadZone' */

  /* RelationalOperator: '<S88>/Relational Operator' incorporates:
   *  Constant: '<S88>/Clamping_zero'
   */
  Controller_B.RelationalOperator_k = (Controller_B.DeadZone_j != 0.0);

  /* RelationalOperator: '<S88>/fix for DT propagation issue' incorporates:
   *  Constant: '<S88>/Clamping_zero'
   */
  Controller_B.fixforDTpropagationissue_d = (Controller_B.DeadZone_j > 0.0);

  /* Switch: '<S88>/Switch1' */
  if (Controller_B.fixforDTpropagationissue_d) {
    /* Switch: '<S88>/Switch1' incorporates:
     *  Constant: '<S88>/Constant'
     */
    Controller_B.Switch1_g = 1;
  } else {
    /* Switch: '<S88>/Switch1' incorporates:
     *  Constant: '<S88>/Constant2'
     */
    Controller_B.Switch1_g = -1;
  }

  /* End of Switch: '<S88>/Switch1' */

  /* Gain: '<S95>/Integral Gain' */
  Controller_B.IntegralGain_n = minDistance;

  /* RelationalOperator: '<S88>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S88>/Clamping_zero'
   */
  Controller_B.fixforDTpropagationissue1_j = (Controller_B.IntegralGain_n > 0.0);

  /* Switch: '<S88>/Switch2' */
  if (Controller_B.fixforDTpropagationissue1_j) {
    /* Switch: '<S88>/Switch2' incorporates:
     *  Constant: '<S88>/Constant3'
     */
    Controller_B.Switch2_p = 1;
  } else {
    /* Switch: '<S88>/Switch2' incorporates:
     *  Constant: '<S88>/Constant4'
     */
    Controller_B.Switch2_p = -1;
  }

  /* End of Switch: '<S88>/Switch2' */

  /* RelationalOperator: '<S88>/Equal1' */
  Controller_B.Equal1_p = (Controller_B.Switch1_g == Controller_B.Switch2_p);

  /* Logic: '<S88>/AND3' */
  Controller_B.AND3_n = (Controller_B.RelationalOperator_k &&
    Controller_B.Equal1_p);

  /* Switch: '<S88>/Switch' */
  if (Controller_B.AND3_n) {
    /* Switch: '<S88>/Switch' incorporates:
     *  Constant: '<S88>/Constant1'
     */
    Controller_B.Switch_g = 0.0;
  } else {
    /* Switch: '<S88>/Switch' */
    Controller_B.Switch_g = Controller_B.IntegralGain_n;
  }

  /* End of Switch: '<S88>/Switch' */

  /* Update for DiscreteIntegrator: '<S98>/Integrator' */
  Controller_DW.Integrator_DSTATE += 0.01 * Controller_B.Switch_g;

  /* Update for DiscreteIntegrator: '<S43>/Integrator' */
  Controller_DW.Integrator_DSTATE_c += 0.01 * Controller_B.Switch;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Controller_M->rtwLogInfo, (&Controller_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Controller_M)!=-1) &&
        !((rtmGetTFinal(Controller_M)-Controller_M->Timing.taskTime0) >
          Controller_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Controller_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Controller_M->Timing.clockTick0)) {
    ++Controller_M->Timing.clockTickH0;
  }

  Controller_M->Timing.taskTime0 = Controller_M->Timing.clockTick0 *
    Controller_M->Timing.stepSize0 + Controller_M->Timing.clockTickH0 *
    Controller_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Controller_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Controller_M, 0,
                sizeof(RT_MODEL_Controller_T));
  rtmSetTFinal(Controller_M, 300.0);
  Controller_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Controller_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Controller_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Controller_M->rtwLogInfo, (NULL));
    rtliSetLogT(Controller_M->rtwLogInfo, "tout");
    rtliSetLogX(Controller_M->rtwLogInfo, "");
    rtliSetLogXFinal(Controller_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Controller_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Controller_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Controller_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Controller_M->rtwLogInfo, 1);
    rtliSetLogY(Controller_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Controller_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Controller_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Controller_B), 0,
                sizeof(B_Controller_T));

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  (void)memset(&Controller_Y, 0, sizeof(ExtY_Controller_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Controller_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Controller_M), Controller_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Controller_M)));

  {
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S98>/Integrator' */
    Controller_DW.Integrator_DSTATE = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S43>/Integrator' */
    Controller_DW.Integrator_DSTATE_c = 0.0;

    /* Start for MATLABSystem: '<S1>/Pure Pursuit' */
    Controller_DW.objisempty = true;
    Controller_DW.obj.DesiredLinearVelocity = 2.0;
    Controller_DW.obj.MaxAngularVelocity = 7.0;
    Controller_DW.obj.LookaheadDistance = 0.5;
    Controller_DW.obj.isInitialized = 1;
    for (i = 0; i < 200; i++) {
      Controller_DW.obj.WaypointsInternal[i] = (rtNaN);
    }

    /* InitializeConditions for MATLABSystem: '<S1>/Pure Pursuit' */
    Controller_DW.obj.LookaheadPoint[0] = 0.0;
    Controller_DW.obj.LookaheadPoint[1] = 0.0;
    Controller_DW.obj.LastPose[0] = 0.0;
    Controller_DW.obj.LastPose[1] = 0.0;
    Controller_DW.obj.LastPose[2] = 0.0;
    Controller_DW.obj.ProjectionPoint[0] = (rtNaN);
    Controller_DW.obj.ProjectionPoint[1] = (rtNaN);
    Controller_DW.obj.ProjectionLineIndex = 0.0;
  }
}

/* Model terminate function */
void Controller_terminate(void)
{
  /* (no terminate code required) */
}
