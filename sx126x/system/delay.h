/*!
 * \file      delay.h
 *
 * \brief     Delay implementation
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 */
#ifndef __DELAY_H__
#define __DELAY_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "msp430G2553.h"
#define CPU_F                               ((double)8000000) 
#define delay_us(x)                       __delay_cycles((long)(CPU_F*(double)x/1000000.0)) 
#define delay_ms(x)                      __delay_cycles((long)(CPU_F*(double)x/1000.0)) 
#define DelayMs  delay_ms


// /*! 
//  * Blocking delay of "s" seconds
//  */
// void Delay( int s );

// /*! 
//  * Blocking delay of "ms" milliseconds
//  */
// void DelayMs( uint32_t ms );

#ifdef __cplusplus
}
#endif

#endif // __DELAY_H__

