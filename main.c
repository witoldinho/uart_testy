/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.125
        Device            :  PIC32MM0256GPM028
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36B
        MPLAB 	          :  MPLAB X v5.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "opisy.h"
#include "mcc_generated_files/uart1.h"
#include <stdio.h>

uint16_t x;

#define max_kanal 512
void __attribute__((used)) delayUs(unsigned int usec);
 void __attribute__((used)) delayMs(unsigned int usec);

void delay(uint32_t t)
{
    uint32_t i;
    for(i=0;i<t;i++);
}

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    printf("\n\r START ------");
    IO_RB13_SetHigh();
    
    
    while (1)
    {
        // Add your application code
        U1STAbits.UTXINV=1;
        delayUs(80);
        U1STAbits.UTXINV=0;
        delayUs(10);
        UART1_Write(0);
        
        for(x=0;x<=max_kanal+15;x++)
        {
            UART1_Write(0xAA);
            
        }
        delayMs(20);
        printf(".");
    }
    return 1; 
}
/**
 End of File
*/

 void __attribute__((used)) delayUs(unsigned int usec)
{
    unsigned int tWait, tStart;

    tWait=(SYSTEMCLOCK/2000000)*usec; 
    tStart=_mfc0(9,0);
    while((_mfc0(9,0)-tStart)<tWait);        // wait for the time to pass
}

  void __attribute__((used)) delayMs(unsigned int usec)
{
    unsigned int tWait, tStart;

    tWait=(SYSTEMCLOCK/2000)*usec; 
    tStart=_mfc0(9,0);
    while((_mfc0(9,0)-tStart)<tWait);        // wait for the time to pass
}