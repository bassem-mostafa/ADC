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

typedef struct ADC_Context
{
    ADC_Instance_t Instance[ ADC_Count ];
} ADC_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static ADC_Status_t ADC_Context_Initialize( void );
static ADC_Status_t ADC_Context_Cycle( void );
static ADC_Status_t ADC_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static ADC_Context_t ADC_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static ADC_Status_t ADC_Context_Initialize( void )
{
    ADC_Status_t Status = ADC_Status_Success;

    do
    {
        ADC_Trace( "%s( void )", __FUNCTION__ );

        for ( ADC_t ADC_x = ADC_Null; ADC_x < ADC_Count; ++ADC_x )
        {
            ADC_Context.Instance[ ADC_x ].ADCx = ADC_x;
        }
    }
    while ( 0 );

    return Status;
}

static ADC_Status_t ADC_Context_Cycle( void )
{
    ADC_Status_t Status = ADC_Status_Success;

    do
    {
        ADC_Trace( "%s( void )", __FUNCTION__ );
    }
    while ( 0 );

    return Status;
}

static ADC_Status_t ADC_Context_DeInitialize( void )
{
    ADC_Status_t Status = ADC_Status_Success;

    do
    {
        ADC_Trace( "%s( void )", __FUNCTION__ );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

ADC_Status_t ADC_Initialize( ADC_t ADCx )
{
    ADC_Status_t Status = ADC_Status_Success;
    ADC_Status_t ADC_Status = ADC_Status_Success;

    do
    {
        ADC_Trace( "%s( ADCx=%d )", __FUNCTION__, ADCx );

        if ( ( Status = ADC_IsValid( ADCx ) ) != ADC_Status_Success )
        {
            break;
        }

        if ( ( Status = ADC_Context_Initialize( ) ) != ADC_Status_Success )
        {
            break;
        }

        for ( ADC_t ADC_x = ADC_Null; ADC_x < ADC_Count; ++ADC_x )
        {
            if ( ADCx != ADC_All && ADCx != ADC_x )
            {
                continue;
            }

            if ( ( ADC_Status = ADC_Instance_Initialize( &ADC_Context.Instance[ ADC_x ] ) ) != ADC_Status_Success )
            {
                Status = ADC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

ADC_Status_t ADC_Cycle( ADC_t ADCx )
{
    ADC_Status_t Status = ADC_Status_Success;
    ADC_Status_t ADC_Status = ADC_Status_Success;

    do
    {
        ADC_Trace( "%s( ADCx=%d )", __FUNCTION__, ADCx );

        if ( ( Status = ADC_IsValid( ADCx ) ) != ADC_Status_Success )
        {
            break;
        }

        if ( ( Status = ADC_Context_Cycle( ) ) != ADC_Status_Success )
        {
            break;
        }

        for ( ADC_t ADC_x = ADC_Null; ADC_x < ADC_Count; ++ADC_x )
        {
            if ( ADCx != ADC_All && ADCx != ADC_x )
            {
                continue;
            }

            if ( ( ADC_Status = ADC_Instance_Cycle( &ADC_Context.Instance[ ADC_x ] ) ) != ADC_Status_Success )
            {
                Status = ADC_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

ADC_Status_t ADC_DeInitialize( ADC_t ADCx )
{
    ADC_Status_t Status = ADC_Status_Success;
    ADC_Status_t ADC_Status = ADC_Status_Success;

    do
    {
        ADC_Trace( "%s( ADCx=%d )", __FUNCTION__, ADCx );

        if ( ( Status = ADC_IsValid( ADCx ) ) != ADC_Status_Success )
        {
            break;
        }

        for ( ADC_t ADC_x = ADC_Null; ADC_x < ADC_Count; ++ADC_x )
        {
            if ( ADCx != ADC_All && ADCx != ADC_x )
            {
                continue;
            }

            if ( ( ADC_Status = ADC_Instance_DeInitialize( &ADC_Context.Instance[ ADC_x ] ) ) != ADC_Status_Success )
            {
                Status = ADC_Status;
            }
        }

        Status = ADC_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char ADC_VERSION[] = "0.0.0.v20260412-1852";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
