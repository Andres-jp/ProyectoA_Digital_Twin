/*
 * Controller_types.h
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

#ifndef Controller_types_h_
#define Controller_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_Controller_T
#define typedef_cell_wrap_Controller_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_Controller_T;

#endif                                 /* typedef_cell_wrap_Controller_T */

#ifndef struct_tag_XFVCXjcZYsy1a59pMLsVsG
#define struct_tag_XFVCXjcZYsy1a59pMLsVsG

struct tag_XFVCXjcZYsy1a59pMLsVsG
{
  int32_T isInitialized;
  cell_wrap_Controller_T inputVarSize[2];
  real_T MaxAngularVelocity;
  real_T LookaheadDistance;
  real_T DesiredLinearVelocity;
  real_T ProjectionPoint[2];
  real_T ProjectionLineIndex;
  real_T LookaheadPoint[2];
  real_T LastPose[3];
  real_T WaypointsInternal[200];
};

#endif                                 /* struct_tag_XFVCXjcZYsy1a59pMLsVsG */

#ifndef typedef_nav_slalgs_internal_PurePursu_T
#define typedef_nav_slalgs_internal_PurePursu_T

typedef struct tag_XFVCXjcZYsy1a59pMLsVsG nav_slalgs_internal_PurePursu_T;

#endif                             /* typedef_nav_slalgs_internal_PurePursu_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_Controller_T RT_MODEL_Controller_T;

#endif                                 /* Controller_types_h_ */
