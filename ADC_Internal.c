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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "ADC.h"
#include "ADC_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

LOG_Status_t ADC_LOG_Raw( LOG_Level_t LOG_Level, LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_RawWithArgs( ADC_LOG, LOG_Level, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t ADC_LOG_Trace( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_TraceWithArgs( ADC_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t ADC_LOG_Debug( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_DebugWithArgs( ADC_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t ADC_LOG_Info( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_InfoWithArgs( ADC_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t ADC_LOG_Warning( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_WarningWithArgs( ADC_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t ADC_LOG_Error( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_ErrorWithArgs( ADC_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

LOG_Status_t ADC_LOG_Fatal( LOG_Format_t LOG_Format, ... )
{
    LOG_Status_t LOG_Status = LOG_Status_Success;
    va_list args;
    va_start( args, LOG_Format );
    LOG_Status = LOG_FatalWithArgs( ADC_LOG, LOG_Format, args );
    va_end( args );
    return LOG_Status;
}

ADC_Status_t ADC_Instance_IsValid( ADC_Instance_t * ADC_Instance )
{
    ADC_Status_t ADC_Status = ADC_Status_Error;
    do
    {
        ADC_Trace( "%s( Instance=%p )", __FUNCTION__, ADC_Instance );
        if ( ADC_Instance == NULL )
        {
            ADC_Error( "Invalid Argument" );
            ADC_Status = ADC_Status_ArgumentInvalid;
            break;
        }
        ADC_Status = ADC_Status_Error;
        for ( ADC_t ADC = ADC_Null; ADC < ADC_NUMBER_OF_INSTANCES; ++ADC )
        {
            if ( ADC_Instance == &ADC_Context.Instance[ ADC ] )
            {
                ADC_Status = ADC_Status_Success;
                break;
            }
        }
        if ( ADC_Status != ADC_Status_Success )
        {
            ADC_Error( "Invalid Reference" );
            ADC_Status = ADC_Status_Error;
            break;
        }
        ADC_Status = ADC_Status_Success;
    }
    while ( 0 );
    return ADC_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

ADC_Context_t ADC_Context;

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
