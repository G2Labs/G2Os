/*================================================================================================*/
/*
 * g2systemInit.h
 *
 *  Created on: 13.10.2016
 *      Author: grzegorz
 */
/*================================================================================================*/
#ifndef G2SYSTEMINIT_H_
#define G2SYSTEMINIT_H_
/*================================================================================================*/
#include "stm32f0xx.h"
#include <stdio.h>
#include <stdlib.h>
/*================================================================================================*/
#define SYSTICK_RATE_HZ 1000
/*================================================================================================*/
void opoznienieMs(unsigned int t);
unsigned int pobierzCzasMs(void);
int zarejestrujPrzerwanieSystemowe(int irqNumber, void (*irqHandler)(void));
int zarejestrujPrzerwanie(int irqNumber, void (*irqHandler)(void));
void wyrejestrujPrzerwanie(int irqNumber);
void wywolajKernel(unsigned int param, void* ptr);
/*================================================================================================*/
/*================================================================================================*/
#endif /* G2SYSTEMINIT_H_ */
/*================================================================================================*/
/*                                              EOF                                               */
/*================================================================================================*/
