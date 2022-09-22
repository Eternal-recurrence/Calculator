/*
 * KP_Program.c
 *
 *  Created on: Aug 15, 2022
 *      Author: noure
 */
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "KP_Config.h"
#include "util/delay.h"


u8 KP_Switches (){

	u8 LocalKetstat = 0xff, KeyChk = 1, KeyPos = 0;

	/*write them in a separate function: initiate
	  DIO_VoidSetPortDirection(KP_PRORT, 0x0F);
	  DIO_VoidSetPortValue(KP_PRORT, 0xFF);
	*/
	for (int col = 0; col < 4; col++){
		DIO_VoidSetPinValue(KP_PRORT, col + 4, Low);

		for (int row = 0; row < 4; row++){
			KeyChk = DIO_U8GetPinValue(KP_PRORT, row);

			if (KeyChk == 0){
				//return 5;
				KeyPos = row*4 + col + 1;
				while(DIO_U8GetPinValue(KP_PRORT, row) == 0);
				_delay_ms(50);
				DIO_VoidSetPinValue(KP_PRORT, col + 4, High);
				return KeyPos;
			}
		}
		DIO_VoidSetPinValue(KP_PRORT, col + 4, High);
	}
	return KeyPos;
}
