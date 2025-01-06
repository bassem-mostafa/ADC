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

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef ADC_INTERNAL_H_
    #define ADC_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "ADC_Port.h"
    #include "driver/ADS1262/ADC_ADS1262.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef ADC_TIM
        #define ADC_TIM TIM_1
    #endif

    #ifndef ADC_LOG
        #define ADC_LOG LOG_1
    #endif

    #define ADC_NAME       "ADC"
    #define ADC_LOG_PREFIX UTIL_StringConcatenateConstant( ADC_NAME, "> " )

    #ifdef DEBUG
        #define ADC_Raw( Level, Format, ... ) ADC_LOG_Raw( Level, Format, ##__VA_ARGS__ )
        #define ADC_Trace( Format, ... )      ADC_LOG_Trace( UTIL_StringConcatenateConstant( ADC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define ADC_Debug( Format, ... )      ADC_LOG_Debug( UTIL_StringConcatenateConstant( ADC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define ADC_Info( Format, ... )       ADC_LOG_Info( UTIL_StringConcatenateConstant( ADC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define ADC_Warning( Format, ... )    ADC_LOG_Warning( UTIL_StringConcatenateConstant( ADC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define ADC_Error( Format, ... )      ADC_LOG_Error( UTIL_StringConcatenateConstant( ADC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define ADC_Fatal( Format, ... )      ADC_LOG_Fatal( UTIL_StringConcatenateConstant( ADC_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define ADC_Raw( Level, Format, ... )
        #define ADC_Trace( Format, ... )
        #define ADC_Debug( Format, ... )
        #define ADC_Info( Format, ... )
        #define ADC_Warning( Format, ... )
        #define ADC_Error( Format, ... )
        #define ADC_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct ADC_Instance_Context_t ADC_Instance_Context_t;

    typedef struct ADC_Instance
    {
        ADC_t ADC;

        union
        {
            ADC_Instance_Context_t * Context;
            ADC_ADS1262_Instance_t * ADS1262;
        };
    } ADC_Instance_t;

    typedef struct ADC_Context
    {
        ADC_Instance_t Instance[ ADC_NUMBER_OF_INSTANCES ];
    } ADC_Context_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    LOG_Status_t ADC_LOG_Raw( LOG_Level_t LOG_Level, LOG_Format_t LOG_Format, ... );
    LOG_Status_t ADC_LOG_Trace( LOG_Format_t LOG_Format, ... );
    LOG_Status_t ADC_LOG_Debug( LOG_Format_t LOG_Format, ... );
    LOG_Status_t ADC_LOG_Info( LOG_Format_t LOG_Format, ... );
    LOG_Status_t ADC_LOG_Warning( LOG_Format_t LOG_Format, ... );
    LOG_Status_t ADC_LOG_Error( LOG_Format_t LOG_Format, ... );
    LOG_Status_t ADC_LOG_Fatal( LOG_Format_t LOG_Format, ... );

    ADC_Status_t ADC_Instance_IsValid( ADC_Instance_t * ADC_Instance );

    // The following APIs MUST be provided by the port
    ADC_Status_t ADC_IsValid( ADC_t ADC );

    ADC_Status_t ADC_Instance_Initialize( ADC_Instance_t * ADC_Instance );
    ADC_Status_t ADC_Instance_Cycle( ADC_Instance_t * ADC_Instance );
    ADC_Status_t ADC_Instance_DeInitialize( ADC_Instance_t * ADC_Instance );

    // TODO Add More APIs

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    extern ADC_Context_t ADC_Context;

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* ADC_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
