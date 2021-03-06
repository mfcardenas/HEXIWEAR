// File: HTU_driver.h

// Declarations of main functionalities in the HTU sensor module.

#ifndef _HTU_driver_h_
#define _HTU_driver_h_

/******************************************************************************
 * Header file inclusions.                                                    *
 ******************************************************************************/

#include "HTU_info.h"
#include "HTU_types.h"

/******************************************************************************
 * Global function declarations.                                              *
 ******************************************************************************/
 
// Initialises the HTU sensor.
void HTU_Init();

// Resets the sensor.
void HTU_SoftReset();

// Configures the measurement resolution.
void HTU_SetUserRegister();

// Retrieves temperature data.
void HTU_GetTemp ( int16_t* tempData );

// Retrieves humidity data.
void HTU_GetHum( int16_t* humData );

// Retrieves temperature and humidity data.
void HTU_ReadRawData( int16_t* temperature, int16_t* humidity );

// Formats raw humidity data to float.
float HTU_HumFormatFloat( uint16_t input );

// Formats raw humidity data to int.
int16_t HTU_HumFormatInt( uint16_t input );

// Formats raw temperature data to int.
float HTU_TempFormatFloat( uint16_t input );

// Formats raw temperature data to int.
int16_t HTU_TempFormatInt( uint16_t input );

#endif