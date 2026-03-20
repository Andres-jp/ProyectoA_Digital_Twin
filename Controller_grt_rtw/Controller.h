/*
 * Controller.h
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

#ifndef Controller_h_
#define Controller_h_
#ifndef Controller_COMMON_INCLUDES_
#define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

#include "Controller_types.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Subtract[2];                  /* '<S2>/Subtract' */
  real_T DotProduct;                   /* '<S2>/Dot Product' */
  real_T Sqrt;                         /* '<S2>/Sqrt' */
  real_T Product;                      /* '<S5>/Product' */
  real_T e_spd;                        /* '<S4>/Sum' */
  real_T ProportionalGain;             /* '<S103>/Proportional Gain' */
  real_T Integrator;                   /* '<S98>/Integrator' */
  real_T Sum;                          /* '<S107>/Sum' */
  real_T Product1;                     /* '<S5>/Product1' */
  real_T e_dotw;                       /* '<S3>/Sum1' */
  real_T Integrator_j;                 /* '<S43>/Integrator' */
  real_T Sum_g;                        /* '<S52>/Sum' */
  real_T DeadZone;                     /* '<S35>/DeadZone' */
  real_T IntegralGain;                 /* '<S40>/Integral Gain' */
  real_T Switch;                       /* '<S33>/Switch' */
  real_T DeadZone_j;                   /* '<S90>/DeadZone' */
  real_T IntegralGain_n;               /* '<S95>/Integral Gain' */
  real_T Switch_g;                     /* '<S88>/Switch' */
  real_T PurePursuit_o1;               /* '<S1>/Pure Pursuit' */
  real_T PurePursuit_o2;               /* '<S1>/Pure Pursuit' */
  int8_T Switch1;                      /* '<S33>/Switch1' */
  int8_T Switch2;                      /* '<S33>/Switch2' */
  int8_T Switch1_g;                    /* '<S88>/Switch1' */
  int8_T Switch2_p;                    /* '<S88>/Switch2' */
  boolean_T RelationalOperator;        /* '<S33>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S33>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S33>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S33>/Equal1' */
  boolean_T AND3;                      /* '<S33>/AND3' */
  boolean_T RelationalOperator_k;      /* '<S88>/Relational Operator' */
  boolean_T fixforDTpropagationissue_d;
                                      /* '<S88>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_j;
                                     /* '<S88>/fix for DT propagation issue1' */
  boolean_T Equal1_p;                  /* '<S88>/Equal1' */
  boolean_T AND3_n;                    /* '<S88>/AND3' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  nav_slalgs_internal_PurePursu_T obj; /* '<S1>/Pure Pursuit' */
  real_T Integrator_DSTATE;            /* '<S98>/Integrator' */
  real_T Integrator_DSTATE_c;          /* '<S43>/Integrator' */
  boolean_T objisempty;                /* '<S1>/Pure Pursuit' */
} DW_Controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T robotGoal[2];                 /* '<Root>/robotGoal' */
  real_T fb_currentPose[3];            /* '<Root>/fb_currentPose' */
  real_T planOutput[200];              /* '<Root>/Waypints' */
  real_T fb_dotw;                      /* '<Root>/fb_dotw' */
  real_T fb_spd_LPF;                   /* '<Root>/fb_spd' */
} ExtU_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T atGoal;                    /* '<Root>/atGoal' */
  real_T u_spd;                        /* '<Root>/u_spd' */
  real_T u_dotw;                       /* '<Root>/u_dotw' */
} ExtY_Controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_Controller_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_Controller_T Controller_B;

/* Block states (default storage) */
extern DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Controller_T Controller_Y;

/* Model entry point functions */
extern void Controller_initialize(void);
extern void Controller_step(void);
extern void Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller_T *const Controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S48>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S3>/Zero-Order Hold1' : Eliminated since input and output rates are identical
 * Block '<S4>/Zero-Order Hold' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Cycle_model/Controller')    - opens subsystem Cycle_model/Controller
 * hilite_system('Cycle_model/Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Cycle_model'
 * '<S1>'   : 'Cycle_model/Controller'
 * '<S2>'   : 'Cycle_model/Controller/Check Distance To Goal'
 * '<S3>'   : 'Cycle_model/Controller/PI_dotw'
 * '<S4>'   : 'Cycle_model/Controller/PI_spd'
 * '<S5>'   : 'Cycle_model/Controller/Zero-Velocity At Goal'
 * '<S6>'   : 'Cycle_model/Controller/PI_dotw/PID Controller1'
 * '<S7>'   : 'Cycle_model/Controller/PI_dotw/PID Controller1/Anti-windup'
 * '<S8>'   : 'Cycle_model/Controller/PI_dotw/PID Controller1/D Gain'
 * '<S9>'   : 'Cycle_model/Controller/PI_dotw/PID Controller1/External Derivative'
 * '<S10>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Filter'
 * '<S11>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Filter ICs'
 * '<S12>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/I Gain'
 * '<S13>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Ideal P Gain'
 * '<S14>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Ideal P Gain Fdbk'
 * '<S15>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Integrator'
 * '<S16>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Integrator ICs'
 * '<S17>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/N Copy'
 * '<S18>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/N Gain'
 * '<S19>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/P Copy'
 * '<S20>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Parallel P Gain'
 * '<S21>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Reset Signal'
 * '<S22>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Saturation'
 * '<S23>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Saturation Fdbk'
 * '<S24>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Sum'
 * '<S25>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Sum Fdbk'
 * '<S26>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Tracking Mode'
 * '<S27>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Tracking Mode Sum'
 * '<S28>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Tsamp - Integral'
 * '<S29>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Tsamp - Ngain'
 * '<S30>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/postSat Signal'
 * '<S31>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/preInt Signal'
 * '<S32>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/preSat Signal'
 * '<S33>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S34>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S35>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S36>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/D Gain/Disabled'
 * '<S37>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/External Derivative/Disabled'
 * '<S38>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Filter/Disabled'
 * '<S39>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Filter ICs/Disabled'
 * '<S40>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/I Gain/Internal Parameters'
 * '<S41>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Ideal P Gain/Passthrough'
 * '<S42>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Integrator/Discrete'
 * '<S44>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Integrator ICs/Internal IC'
 * '<S45>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S46>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/N Gain/Disabled'
 * '<S47>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/P Copy/Disabled'
 * '<S48>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S49>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Reset Signal/Disabled'
 * '<S50>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Saturation/Enabled'
 * '<S51>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Saturation Fdbk/Disabled'
 * '<S52>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Sum/Sum_PI'
 * '<S53>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Sum Fdbk/Disabled'
 * '<S54>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Tracking Mode/Disabled'
 * '<S55>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S56>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S57>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S58>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/postSat Signal/Forward_Path'
 * '<S59>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/preInt Signal/Internal PreInt'
 * '<S60>'  : 'Cycle_model/Controller/PI_dotw/PID Controller1/preSat Signal/Forward_Path'
 * '<S61>'  : 'Cycle_model/Controller/PI_spd/PID Controller'
 * '<S62>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Anti-windup'
 * '<S63>'  : 'Cycle_model/Controller/PI_spd/PID Controller/D Gain'
 * '<S64>'  : 'Cycle_model/Controller/PI_spd/PID Controller/External Derivative'
 * '<S65>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Filter'
 * '<S66>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Filter ICs'
 * '<S67>'  : 'Cycle_model/Controller/PI_spd/PID Controller/I Gain'
 * '<S68>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Ideal P Gain'
 * '<S69>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Ideal P Gain Fdbk'
 * '<S70>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Integrator'
 * '<S71>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Integrator ICs'
 * '<S72>'  : 'Cycle_model/Controller/PI_spd/PID Controller/N Copy'
 * '<S73>'  : 'Cycle_model/Controller/PI_spd/PID Controller/N Gain'
 * '<S74>'  : 'Cycle_model/Controller/PI_spd/PID Controller/P Copy'
 * '<S75>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Parallel P Gain'
 * '<S76>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Reset Signal'
 * '<S77>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Saturation'
 * '<S78>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Saturation Fdbk'
 * '<S79>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Sum'
 * '<S80>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Sum Fdbk'
 * '<S81>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Tracking Mode'
 * '<S82>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Tracking Mode Sum'
 * '<S83>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Tsamp - Integral'
 * '<S84>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Tsamp - Ngain'
 * '<S85>'  : 'Cycle_model/Controller/PI_spd/PID Controller/postSat Signal'
 * '<S86>'  : 'Cycle_model/Controller/PI_spd/PID Controller/preInt Signal'
 * '<S87>'  : 'Cycle_model/Controller/PI_spd/PID Controller/preSat Signal'
 * '<S88>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S89>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S90>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S91>'  : 'Cycle_model/Controller/PI_spd/PID Controller/D Gain/Disabled'
 * '<S92>'  : 'Cycle_model/Controller/PI_spd/PID Controller/External Derivative/Disabled'
 * '<S93>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Filter/Disabled'
 * '<S94>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Filter ICs/Disabled'
 * '<S95>'  : 'Cycle_model/Controller/PI_spd/PID Controller/I Gain/Internal Parameters'
 * '<S96>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Ideal P Gain/Passthrough'
 * '<S97>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S98>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Integrator/Discrete'
 * '<S99>'  : 'Cycle_model/Controller/PI_spd/PID Controller/Integrator ICs/Internal IC'
 * '<S100>' : 'Cycle_model/Controller/PI_spd/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S101>' : 'Cycle_model/Controller/PI_spd/PID Controller/N Gain/Disabled'
 * '<S102>' : 'Cycle_model/Controller/PI_spd/PID Controller/P Copy/Disabled'
 * '<S103>' : 'Cycle_model/Controller/PI_spd/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S104>' : 'Cycle_model/Controller/PI_spd/PID Controller/Reset Signal/Disabled'
 * '<S105>' : 'Cycle_model/Controller/PI_spd/PID Controller/Saturation/Enabled'
 * '<S106>' : 'Cycle_model/Controller/PI_spd/PID Controller/Saturation Fdbk/Disabled'
 * '<S107>' : 'Cycle_model/Controller/PI_spd/PID Controller/Sum/Sum_PI'
 * '<S108>' : 'Cycle_model/Controller/PI_spd/PID Controller/Sum Fdbk/Disabled'
 * '<S109>' : 'Cycle_model/Controller/PI_spd/PID Controller/Tracking Mode/Disabled'
 * '<S110>' : 'Cycle_model/Controller/PI_spd/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S111>' : 'Cycle_model/Controller/PI_spd/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S112>' : 'Cycle_model/Controller/PI_spd/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S113>' : 'Cycle_model/Controller/PI_spd/PID Controller/postSat Signal/Forward_Path'
 * '<S114>' : 'Cycle_model/Controller/PI_spd/PID Controller/preInt Signal/Internal PreInt'
 * '<S115>' : 'Cycle_model/Controller/PI_spd/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* Controller_h_ */
