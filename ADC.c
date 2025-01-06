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

static ADC_Status_t ADC_Context_Initialize( void );
static ADC_Status_t ADC_Context_Cycle( void );
static ADC_Status_t ADC_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static ADC_Status_t ADC_Context_Initialize( void )
{
    ADC_Status_t ADC_Status = ADC_Status_Error;
    do
    {
        ADC_Trace( "%s( void )", __FUNCTION__ );
        for ( ADC_t ADC = ADC_Null; ADC < ADC_NUMBER_OF_INSTANCES; ++ADC )
        {
            ADC_Context.Instance[ ADC ].ADC = ADC;
            if ( ( ADC_Status = ADC_Instance_Initialize( &ADC_Context.Instance[ ADC ] ) ) != ADC_Status_Success )
            {
                ADC_Warning( "ADC_%d Initialize Failed: Status %d", ADC, ADC_Status );
            }
        }
        ADC_Status = ADC_Status_Success;
    }
    while ( 0 );
    return ADC_Status;
}

static ADC_Status_t ADC_Context_Cycle( void )
{
    ADC_Status_t ADC_Status = ADC_Status_Error;
    do
    {
        ADC_Trace( "%s( void )", __FUNCTION__ );
        for ( ADC_t ADC = ADC_Null; ADC < ADC_NUMBER_OF_INSTANCES; ++ADC )
        {
            ADC_Context.Instance[ ADC ].ADC = ADC; // FIXME
            if ( ( ADC_Status = ADC_Instance_Cycle( &ADC_Context.Instance[ ADC ] ) ) != ADC_Status_Success )
            {
                ADC_Warning( "ADC_%d Cycle Failed: Status %d", ADC, ADC_Status );
            }
        }
        ADC_Status = ADC_Status_Success;
    }
    while ( 0 );
    return ADC_Status;
}

static ADC_Status_t ADC_Context_DeInitialize( void )
{
    ADC_Status_t ADC_Status = ADC_Status_Error;
    do
    {
        ADC_Trace( "%s( void )", __FUNCTION__ );
        for ( ADC_t ADC = ADC_Null; ADC < ADC_NUMBER_OF_INSTANCES; ++ADC )
        {
            ADC_Context.Instance[ ADC ].ADC = ADC; // FIXME
            if ( ( ADC_Status = ADC_Instance_DeInitialize( &ADC_Context.Instance[ ADC ] ) ) != ADC_Status_Success )
            {
                ADC_Warning( "ADC_%d DeInitialize Failed: Status %d", ADC, ADC_Status );
            }
        }
        ADC_Status = ADC_Status_Success;
    }
    while ( 0 );
    return ADC_Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

ADC_Status_t ADC_Initialize( void )
{
    ADC_Status_t ADC_Status = ADC_Status_Error;
    do
    {
        ADC_Trace( "%s( void )", __FUNCTION__ );
        ADC_Status = ADC_Context_Initialize( );
    }
    while ( 0 );
    return ADC_Status;
}

ADC_Status_t ADC_Cycle( void )
{
    ADC_Status_t ADC_Status = ADC_Status_Error;
    do
    {
        ADC_Trace( "%s( void )", __FUNCTION__ );
        ADC_Status = ADC_Context_Cycle( );
    }
    while ( 0 );
    return ADC_Status;
}

ADC_Status_t ADC_DeInitialize( void )
{
    ADC_Status_t ADC_Status = ADC_Status_Error;
    do
    {
        ADC_Trace( "%s( void )", __FUNCTION__ );
        ADC_Status = ADC_Context_DeInitialize( );
    }
    while ( 0 );
    return ADC_Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char ADC_VERSION[] = "0.0.0.v20260117-1054";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
