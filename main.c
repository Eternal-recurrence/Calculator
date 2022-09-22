/*
 * main.c
 *
 *  Created on: Aug 13, 2022
 *      Author: noure
 */
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "util/delay.h"
#include "KP_Interface.h"
#include "Calc_Interface.h"

int main(){
	DIO_VoidSetPortDirection(PortC_ID, 0xf0);
	DIO_VoidSetPortValue(PortC_ID, 0xFF);

	LCD_VoidInit();
	Calculator();

	return 0;
}

