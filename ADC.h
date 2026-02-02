// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

/**
 *  @file
 *
 *  @brief Platform ADC Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_ADC ADC
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_ADC_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef ADC_H_
    #define ADC_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "ADC_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief ADC Operation Status
     *
     *  @enum ADC_Status_t
     */
    typedef enum ADC_Status
    {
        ADC_Status_Success = 0,     ///< Success
        ADC_Status_ArgumentInvalid, ///< Argument Invalid
        ADC_Status_NotSupported,    ///< Not Supported
        ADC_Status_Error,           ///< General Error
        ADC_Status_Busy,            ///< Busy
        ADC_Status_Timeout,         ///< Timeout
    } ADC_Status_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize ADC peripheral
     *
     *  @note MUST BE called before using any ADC API
     *
     *  @param[in] ADCx Peripheral
     *
     *  @return ADC_Status_t
     */
    ADC_Status_t ADC_Initialize( ADC_t ADCx );

    /**
     *  @brief Cycle ADC peripheral
     *
     *  @param[in] ADCx Peripheral
     *
     *  @return ADC_Status_t
     */
    ADC_Status_t ADC_Cycle( ADC_t ADCx );

    /**
     *  @brief De-Initialize ADC peripheral
     *
     *  @param[in] ADCx Peripheral
     *
     *  @return ADC_Status_t
     */
    ADC_Status_t ADC_DeInitialize( ADC_t ADCx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char ADC_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* ADC_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
