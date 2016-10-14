/*================================================================================================*/
/*
 * main.c
 *
 *  Created on: 13.10.2016
 *      Author: grzegorz
 */
/*================================================================================================*/
#include "g2systemInit.h"
#include "g2systemLog.h"
/*================================================================================================*/
#define LICZBA_PROB 5
#define WYWOLANIE_DLA_SVC 2
#define WYWOLANIE_DLA_PENDSV 3
#define WYWOLANIE_DLA_HARDFAULT 4
/*================================================================================================*/
#define OS_STOS_WATEK 50
#define OS_MAX_WATKOW 5
/*================================================================================================*/
typedef struct {
	void (*uchwyt)(void*);
	unsigned int stos[OS_STOS_WATEK + sizeof(StosRejestrowPodstawowych)
	      + sizeof(StosRejestrowPozostalych)];
} Watek;
/*================================================================================================*/
struct {
	Watek watki[OS_MAX_WATKOW];
	unsigned int biezacyWatek;
} OS;
/*================================================================================================*/

/*================================================================================================*/
void przerzucLed(int numer) {
	numer &= 0xF;
	GPIOC->ODR ^= (1 << numer);
}
/*================================================================================================*/
void watek1(void* param) {
	for (;;) {
		przerzucLed(8);
		opoznienieMs(500);
	}
}
/*================================================================================================*/
void watek2(void* param) {
	for (;;) {
		przerzucLed(9);
		opoznienieMs(250);
	}
}
/*================================================================================================*/
void (*f)(void);
/*================================================================================================*/
void inicjalizuj(void) {
	info("Konfigurowanie diod LED.");
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	GPIOC->MODER &= ~(3 << (8 << 1)) | (3 << (9 << 1));
	GPIOC->MODER |= (1 << (8 << 1)) | (1 << (9 << 1));
	GPIOC->ODR = 0;
	info("Konfigurowanie kernela.");
	info("System gotowy do pracy.");
}
/*================================================================================================*/
int main(void) {
	int kodBledu = 0;
	f();
	return kodBledu;
}
/*================================================================================================*/
/*                                              EOF                                               */
/*================================================================================================*/
