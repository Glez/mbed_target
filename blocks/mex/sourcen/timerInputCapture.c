/* Copyright 2010 The MathWorks, Inc. */
/* Copyright 2014-2017 Dr.O.Hagendorf, HS Wismar  */
/* Copyright 2016 M. Marquardt, HS Wismar  */


/*
 * Must specify the S_FUNCTION_NAME as the name of the S-function.
 */
#define S_FUNCTION_NAME                timerInputCapture
#define S_FUNCTION_LEVEL               2

/*
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"
#define EDIT_OK(S, P_IDX) \
 (!((ssGetSimMode(S)==SS_SIMMODE_SIZES_CALL_ONLY) && mxIsEmpty(ssGetSFcnParam(S, P_IDX))))
#define SAMPLE_TIME                    (ssGetSFcnParam(S, 0))

/*
 * Utility function prototypes.
 */
static bool IsRealMatrix(const mxArray * const m);

#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

/* Function: mdlCheckParameters ===========================================
 * Abstract:
 *    mdlCheckParameters verifies new parameter settings whenever parameter
 *    change or are re-evaluated during a simulation. When a simulation is
 *    running, changes to S-function parameters can occur at any time during
 *    the simulation loop.
 */
static void mdlCheckParameters(SimStruct *S)
{
  /*
   * Check the parameter 1 (sample time)
   */
  if EDIT_OK(S, 0) {
    const double * sampleTime = NULL;
    const size_t stArraySize = mxGetM(SAMPLE_TIME) * mxGetN(SAMPLE_TIME);

    /* Sample time must be a real scalar value or 2 element array. */
    if (IsRealMatrix(SAMPLE_TIME) &&
        (stArraySize == 1 || stArraySize == 2) ) {
      sampleTime = mxGetPr(SAMPLE_TIME);
    } else {
      ssSetErrorStatus(S,
                       "Invalid sample time. Sample time must be a real scalar value or an array of two real values.");
      return;
    }

    if (sampleTime[0] < 0.0 && sampleTime[0] != -1.0) {
      ssSetErrorStatus(S,
                       "Invalid sample time. Period must be non-negative or -1 (for inherited).");
      return;
    }

    if (stArraySize == 2 && sampleTime[0] > 0.0 &&
        sampleTime[1] >= sampleTime[0]) {
      ssSetErrorStatus(S,
                       "Invalid sample time. Offset must be smaller than period.");
      return;
    }

    if (stArraySize == 2 && sampleTime[0] == -1.0 && sampleTime[1] != 0.0) {
      ssSetErrorStatus(S,
                       "Invalid sample time. When period is -1, offset must be 0.");
      return;
    }

    if (stArraySize == 2 && sampleTime[0] == 0.0 &&
        !(sampleTime[1] == 1.0)) {
      ssSetErrorStatus(S,
                       "Invalid sample time. When period is 0, offset must be 1.");
      return;
    }
  }
    /*
    * Check the parameter 2 (TimerNumber)
    */
    if EDIT_OK(S, 1) {
    int_T dimsArray[2] = { 1, 1 };

    /* Check the parameter attributes */
    ssCheckSFcnParamValueAttribs(S, 1, "P1", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 3  (Frequency)
     */
    if EDIT_OK(S, 2) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 2, "P2", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 4  (Ti1Active)
     */
    if EDIT_OK(S, 3) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 3, "P3", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 5  (Ti1Port)
     */
    if EDIT_OK(S, 4) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 4, "P4", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 6  (Ti1Pin)
     */
    if EDIT_OK(S, 5) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 5, "P5", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 7  (Ti1Pupd)
     */
    if EDIT_OK(S, 6) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 6, "P6", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 8  (Ti2Active)
     */
    if EDIT_OK(S, 7) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 7, "P7", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 9  (Ti2Port)
     */
    if EDIT_OK(S, 8) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 8, "P8", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 10  (Ti2Pin)
     */
    if EDIT_OK(S, 9) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 9, "P9", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 11  (Ti2Pupd)
     */
    if EDIT_OK(S, 10) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 10, "P10", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 12  (Ti3Active)
     */
    if EDIT_OK(S, 11) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 11, "P11", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 13  (Ti3Port)
     */
    if EDIT_OK(S, 12) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 12, "P12", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 14  (Ti3Pin)
     */
    if EDIT_OK(S, 13) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 13, "P13", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 15  (Ti3Pupd)
     */
    if EDIT_OK(S, 14) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 14, "P14", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 16  (Ti4Active)
     */
    if EDIT_OK(S, 15) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 15, "P15", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 17  (Ti4Port)
     */
    if EDIT_OK(S, 16) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 16, "P16", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 18  (Ti4Pin)
     */
    if EDIT_OK(S, 17) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 17, "P17", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 19  (Ti4Pupd)
     */
    if EDIT_OK(S, 18) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 18, "P18", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }

    /*
     * Check the parameter 20  (OutputMode)
     */
    if EDIT_OK(S, 19) {
      int_T dimsArray[2] = { 1, 1 };

      /* Check the parameter attributes */
      ssCheckSFcnParamValueAttribs(S, 19, "P19", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    }
}

#endif

/* Function: mdlInitializeSizes ===========================================
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{
  int numOutput = 0;
  int i;
  /* Number of expected parameters */
  ssSetNumSFcnParams(S, 20);

#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
    /*
     * If the number of expected input parameters is not equal
     * to the number of parameters entered in the dialog box return.
     * Simulink will generate an error indicating that there is a
     * parameter mismatch.
     */
    mdlCheckParameters(S);
    if (ssGetErrorStatus(S) != NULL) {
      return;
    }
  } else {
    /* Return if number of expected != number of actual parameters */
    return;
  }

#endif

  /* Set the parameter's tunable status */
  ssSetSFcnParamTunable(S, 0, 0);  // SampleTime
  ssSetSFcnParamTunable(S, 1, 0);  // TimerNumber
  ssSetSFcnParamTunable(S, 2, 0);  // Frequency
  ssSetSFcnParamTunable(S, 3, 0);  // Ti1Active
  ssSetSFcnParamTunable(S, 4, 0);  // Ti1Port
  ssSetSFcnParamTunable(S, 5, 0);  // Ti1Pin
  ssSetSFcnParamTunable(S, 6, 0);  // Ti1Pupd
  ssSetSFcnParamTunable(S, 7, 0);  // Ti2Active
  ssSetSFcnParamTunable(S, 8, 0);
  ssSetSFcnParamTunable(S, 9, 0);
  ssSetSFcnParamTunable(S, 10, 0);
  ssSetSFcnParamTunable(S, 11, 0);  // Ti3Active
  ssSetSFcnParamTunable(S, 12, 0);
  ssSetSFcnParamTunable(S, 13, 0);
  ssSetSFcnParamTunable(S, 14, 0);
  ssSetSFcnParamTunable(S, 15, 0);  // Ti4Active
  ssSetSFcnParamTunable(S, 16, 0);
  ssSetSFcnParamTunable(S, 17, 0);
  ssSetSFcnParamTunable(S, 18, 0);
  ssSetSFcnParamTunable(S, 19, 0);  // OutputMode

  ssSetNumPWork(S, 0);

  if (!ssSetNumDWork(S, 0))
    return;

  /*
   * Set the number of input ports.
   */
  if (!ssSetNumInputPorts(S, 0))
    return;


  if(*mxGetPr(ssGetSFcnParam(S, 3)) > 1)
  numOutput++;

  if(*mxGetPr(ssGetSFcnParam(S, 7)) > 1)
  numOutput++;

  if(*mxGetPr(ssGetSFcnParam(S, 11)) > 1)
  numOutput++;

  if(*mxGetPr(ssGetSFcnParam(S, 15)) > 1)
  numOutput++;

  /*
   * Set the number of output ports.
   */
  if (!ssSetNumOutputPorts(S, numOutput))
    return;

  for(i=0; i<numOutput; i++)
  {
    /*
     * Configure the output port i
     */
    ssSetOutputPortDataType(S, i, SS_SINGLE);
    ssSetOutputPortWidth(S, i, 1);
    ssSetOutputPortComplexSignal(S, i, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, i, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, i, 1);
  }


  /*
   * This S-function can be used in referenced model simulating in normal mode.
   */
  ssSetModelReferenceNormalModeSupport(S, MDL_START_AND_MDL_PROCESS_PARAMS_OK);

  /*
   * Set the number of sample time.
   */
  ssSetNumSampleTimes(S, 1);

  /*
   * All options have the form SS_OPTION_<name> and are documented in
   * matlabroot/simulink/include/simstruc.h. The options should be
   * combined with bitwise OR as in
   *   ssSetOptions(S, (SS_OPTION_name1 | SS_OPTION_name2))
   */
  ssSetOptions(S,
               SS_OPTION_USE_TLC_WITH_ACCELERATOR |
               SS_OPTION_CAN_BE_CALLED_CONDITIONALLY |
               SS_OPTION_EXCEPTION_FREE_CODE |
               SS_OPTION_WORKS_WITH_CODE_REUSE |
               SS_OPTION_SFUNCTION_INLINED_FOR_RTW |
               SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME);
}

/* Function: mdlInitializeSampleTimes =====================================
 * Abstract:
 *    This function is used to specify the sample time(s) for your
 *    S-function. You must register the same number of sample times as
 *    specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  const double * const sampleTime = mxGetPr(SAMPLE_TIME);
  const size_t stArraySize = mxGetM(SAMPLE_TIME) * mxGetN(SAMPLE_TIME);
  ssSetSampleTime(S, 0, sampleTime[0]);
  if (stArraySize == 1) {
    ssSetOffsetTime(S, 0, (sampleTime[0] == CONTINUOUS_SAMPLE_TIME?
      FIXED_IN_MINOR_STEP_OFFSET: 0.0));
  } else {
    ssSetOffsetTime(S, 0, sampleTime[1]);
  }

#if defined(ssSetModelReferenceSampleTimeDefaultInheritance)

  ssSetModelReferenceSampleTimeDefaultInheritance(S);

#endif

}

#define MDL_SET_WORK_WIDTHS
#if defined(MDL_SET_WORK_WIDTHS) && defined(MATLAB_MEX_FILE)

/* Function: mdlSetWorkWidths =============================================
 * Abstract:
 *      The optional method, mdlSetWorkWidths is called after input port
 *      width, output port width, and sample times of the S-function have
 *      been determined to set any state and work vector sizes which are
 *      a function of the input, output, and/or sample times.
 *
 *      Run-time parameters are registered in this method using methods
 *      ssSetNumRunTimeParams, ssSetRunTimeParamInfo, and related methods.
 */
static void mdlSetWorkWidths(SimStruct *S)
{
  /* Set number of run-time parameters */
  if (!ssSetNumRunTimeParams(S, 19))
    return;

  /*
   * Register the run-time parameter 1
   */
  ssRegDlgParamAsRunTimeParam(S, 1, 0, "TimerNumber", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 2
   */
  ssRegDlgParamAsRunTimeParam(S, 2, 1, "Frequency", ssGetDataTypeId(S, "uint32"));
  /*
   * Register the run-time parameter 3
   */
  ssRegDlgParamAsRunTimeParam(S, 3, 2, "Ti1Active", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 4
   */
  ssRegDlgParamAsRunTimeParam(S, 4, 3, "Ti1Port", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 5
   */
  ssRegDlgParamAsRunTimeParam(S, 5, 4, "Ti1Pin", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 6
   */
  ssRegDlgParamAsRunTimeParam(S, 6, 5, "Ti1Pupd", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 7
   */
  ssRegDlgParamAsRunTimeParam(S, 7, 6, "Ti2Active", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 8
   */
  ssRegDlgParamAsRunTimeParam(S, 8, 7, "Ti2Port", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 1
   */
  ssRegDlgParamAsRunTimeParam(S, 9, 8, "Ti2Pin", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 2
   */
  ssRegDlgParamAsRunTimeParam(S, 10, 9, "Ti2Pupd", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 3
   */
  ssRegDlgParamAsRunTimeParam(S, 11, 10, "Ti3Active", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 4
   */
  ssRegDlgParamAsRunTimeParam(S, 12, 11, "Ti3Port", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 5
   */
  ssRegDlgParamAsRunTimeParam(S, 13, 12, "Ti3Pin", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 6
   */
  ssRegDlgParamAsRunTimeParam(S, 14, 13, "Ti3Pupd", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 7
   */
  ssRegDlgParamAsRunTimeParam(S, 15, 14, "Ti4Active", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 8
   */
  ssRegDlgParamAsRunTimeParam(S, 16, 15, "Ti4Port", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 7
   */
  ssRegDlgParamAsRunTimeParam(S, 17, 16, "Ti4Pin", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 8
   */
  ssRegDlgParamAsRunTimeParam(S, 18, 17, "Ti4Pupd", ssGetDataTypeId(S, "uint8"));
  /*
   * Register the run-time parameter 8
   */
  ssRegDlgParamAsRunTimeParam(S, 19, 18, "OutputMode", ssGetDataTypeId(S, "uint8"));
}

#endif

#define MDL_START
#if defined(MDL_START)

/* Function: mdlStart =====================================================
 * Abstract:
 *    This function is called once at start of model execution. If you
 *    have states that should be initialized once, this is the place
 *    to do it.
 */
static void mdlStart(SimStruct *S)
{
    UNUSED_PARAMETER(S);
}

#endif

/* Function: mdlOutputs ===================================================
 * Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block. Generally outputs are placed in the output vector(s),
 *    ssGetOutputPortSignal.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    UNUSED_PARAMETER(S);
    UNUSED_PARAMETER(tid);
}

/* Function: mdlTerminate =================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.
 */
static void mdlTerminate(SimStruct *S)
{
    UNUSED_PARAMETER(S);
}

#define MDL_RTW
#if defined(MATLAB_MEX_FILE) && defined(MDL_RTW)

/* Function: mdlRTW =======================================================
 * Abstract:
 *    This function is called when the Real-Time Workshop is generating
 *    the model.rtw file.
 */
static void mdlRTW(SimStruct *S)
{
    UNUSED_PARAMETER(S);
}

#endif

/* Function: IsRealMatrix =================================================
 * Abstract:
 *      Verify that the mxArray is a real (double) finite matrix
 */
static bool IsRealMatrix(const mxArray * const m)
{
  if (mxIsNumeric(m) &&
      mxIsDouble(m) &&
      !mxIsLogical(m) &&
      !mxIsComplex(m) &&
      !mxIsSparse(m) &&
      !mxIsEmpty(m) &&
      mxGetNumberOfDimensions(m) == 2) {
    const real_T * const data = mxGetPr(m);
    const size_t numEl = mxGetNumberOfElements(m);
    size_t i;
    for (i = 0; i < numEl; i++) {
      if (!mxIsFinite(data[i])) {
        return(false);
      }
    }

    return(true);
  } else {
    return(false);
  }
}

/*
 * Required S-function trailer
 */
#ifdef MATLAB_MEX_FILE
# include "simulink.c"
#else
# include "cg_sfun.h"
#endif
