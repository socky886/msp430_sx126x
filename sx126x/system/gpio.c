/*!
 * \file      gpio.c
 *
 * \brief     GPIO driver implementation
 *
 * \remark: Relies on the specific board GPIO implementation as well as on
 *          IO expander driver implementation if one is available on the target
 *          board.
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
#include "gpio-board.h"
#include "board-config.h"
// #include "stm32l4xx_hal.h"
#include "msp430G2553.h"
#include <stdio.h>

void GpioInit( Gpio_t *obj, PinNames pin, PinModes mode,  PinConfigs config, PinTypes type, uint32_t value )
{
    // GpioMcuInit( obj, pin, mode, config, type, value );
    obj->pin=pin;
    if(mode==PIN_OUTPUT)
    {
        GpioWrite(obj,value);
    }
    else
    {
        printf("PinName is %d,PinModes is %d\n",pin,mode);
    }

}

void GpioSetContext( Gpio_t *obj, void* context )
{
    GpioMcuSetContext( obj, context );
}

void GpioSetInterrupt( Gpio_t *obj, IrqModes irqMode, IrqPriorities irqPriority, GpioIrqHandler *irqHandler )
{
    // GpioMcuSetInterrupt( obj, irqMode, irqPriority, irqHandler );
}

void GpioRemoveInterrupt( Gpio_t *obj )
{
    GpioMcuRemoveInterrupt( obj );
}

void GpioWrite( Gpio_t *obj, uint32_t value )
{
    // GpioMcuWrite( obj, value );
    if(obj->pin==LED_1)
    {
        // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1 , ( GPIO_PinState )value );
        if(value==0)
            P1OUT&=~BIT6;
        else
            P1OUT|=BIT6;
    }
    else if(obj->pin==LED_2)
    {
        // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 , ( GPIO_PinState )value );
        if(value==0)
            P1OUT&=~BIT6;
        else
            P1OUT|=BIT6;
    }
    else if(obj->pin==RADIO_RESET) // reset
    {
        // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 , ( GPIO_PinState )value );
        if(value==0)
            P2OUT&=~BIT1;
        else
            P2OUT|=BIT1;
    }
    else if(obj->pin==RADIO_NSS)// spi_nss
    {
        // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 , ( GPIO_PinState )value );
        if(value==0)
            P2OUT&=~BIT0;
        else
            P2OUT|=BIT0;
    }
     else if(obj->pin==RADIO_MOSI)// spi_mosi
    {
        // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7 , ( GPIO_PinState )value );
        if(value==0)
            P1OUT&=~BIT4;
        else
            P1OUT|=BIT4;
    }
     else if(obj->pin==RADIO_MISO)// spi_miso
    {
        // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6 , ( GPIO_PinState )value );
        if(value==0)
            P1OUT&=~BIT5;
        else
            P1OUT|=BIT5;
    }
     else if(obj->pin==RADIO_SCLK)// spi_sck
    {
        // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5 , ( GPIO_PinState )value );
        if(value==0)
            P1OUT&=~BIT0;
        else
            P1OUT|=BIT0;
    }
    else if(obj->pin==RADIO_ANT_SWITCH_POWER)// RADIO_ANT_SWITCH_POWER
    {
        // HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5 , ( GPIO_PinState )value );
        if(value==0)
            P2OUT&=~BIT4;
        else
            P2OUT|=BIT4;
    }
    else  //
    {
        printf("the pinname is %d\n",obj->pin);
        printf("gpio write\n");
        ;
    }
}

void GpioToggle( Gpio_t *obj )
{
    uint16_t value;
    // GpioMcuToggle( obj );
    if(obj->pin==LED_1)
    {
        value=P1OUT&BIT6;

         if(value==0)
            P1OUT&=~BIT6;
        else
            P1OUT|=BIT6;
    }
    else if(obj->pin==LED_2)
    {
        value=P1OUT&BIT6;
         if(value==0)
            P1OUT&=~BIT6;
        else
            P1OUT|=BIT6;
    }
    // else if(obj->pin==RADIO_RESET) // reset
    // {
    //     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 , ( GPIO_PinState )value );
    // }
    // else if(obj->pin==RADIO_NSS)// spi_nss
    // {
    //     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 , ( GPIO_PinState )value );
    // }
    // else if(obj->pin==LED_2)
    // {
    //     HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 , ( GPIO_PinState )value );
    // }
    // else if(obj->pin==LED_2)
    // {
    //     HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 , ( GPIO_PinState )value );
    // }
    else
    {
        printf("the pinname is %d\n",obj->pin);
        printf("gpio toggle\n");
        ;
    }
}

uint8_t GpioRead( Gpio_t *obj )
{
     uint8_t value;
    // return GpioMcuRead( obj );
    if(obj->pin==RADIO_BUSY) //busy
    {
        // printf("read busy line\n");
        // return 0x00;
       

        value=P2IN&BIT2;
        if(value==0)
            return 0x00;
        else
            return 0x01;
        // return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
    }
    else if(obj->pin==RADIO_MISO)
    {
        // HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 , ( GPIO_PinState )value );

        value = P1IN & BIT5;
        if (value == 0)
            return 0x00;
        else
            return 0x01;
    }
    // else if(obj->pin==RADIO_RESET) // reset
    // {
    //     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 , ( GPIO_PinState )value );
    // }
    // else if(obj->pin==RADIO_NSS)// spi_nss
    // {
    //     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 , ( GPIO_PinState )value );
    // }
    else
    {
        printf("the pinname is %d\n",obj->pin);
        printf("gpio read\n");
        return 0x00;
    }
}
