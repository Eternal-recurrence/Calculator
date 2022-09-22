#include "STD_TYPES.h"
#include "util/delay.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"



void LCD_VoidWriteCommand(u8 CopyU8Command){
	
	DIO_VoidSetPinValue (PortB_ID, PIN_ID0, Low);	//RS == 0
	
	DIO_VoidSetPinValue (PortB_ID, PIN_ID1, Low);	//RW == 0
	
	DIO_VoidSetPortValue (PortA_ID, CopyU8Command);
	

	DIO_VoidSetPinValue (PortB_ID, PIN_ID2, High);
	_delay_ms(2);
	DIO_VoidSetPinValue (PortB_ID, PIN_ID2, Low);
	//_delay_ms(5);
}

void LCD_VoidWriteData(u8 CopyU8Data){
	
	DIO_VoidSetPinValue (PortB_ID, PIN_ID0, High); 	//RS == 1
	
	DIO_VoidSetPinValue (PortB_ID, PIN_ID1, Low);	//RW == 0
	
	
	DIO_VoidSetPortValue (PortA_ID, CopyU8Data);
	
	DIO_VoidSetPinValue (PortB_ID, PIN_ID2, High);
	_delay_ms(2);
	DIO_VoidSetPinValue (PortB_ID, PIN_ID2, Low);
	//_delay_ms(5);
}

void LCD_VoidInit(void){
	DIO_VoidSetPinDirection(PortB_ID, PIN_ID0, Output);
	DIO_VoidSetPinDirection(PortB_ID, PIN_ID1, Output);
	DIO_VoidSetPinDirection(PortB_ID, PIN_ID2, Output);
	
	//Set portA direction
	DIO_VoidSetPortDirection(PortA_ID, 0xff);
	
	_delay_ms(30);
	
	LCD_VoidWriteCommand(0b00111000);		//2 lines, 5x8 matrix, 8-bit mode
	_delay_ms(2);
	
	LCD_VoidWriteCommand(0b00001100);		//Display on with no cursor
	_delay_ms(2);
	
	LCD_VoidWriteCommand(0b00000001);		//clears display
}


void LCD_VoidGoToXY(u8 Copyu8x, u8 Copyu8y){
	//u8 LOC_Default = 128;
	if(Copyu8x == 0){		//line 1
		//LOC_Default += Copy_u8y;
		LCD_VoidWriteCommand(128 + Copyu8y);
	}

	else if(Copyu8x == 1){
		//LOC_Default =LOC_Default + 0x40;
		//LOC_Default += Copy_u8y;

		LCD_VoidWriteCommand(128 + 0x40 + Copyu8y);

	}

	//LCD_VoidWriteCommand(LOC_Default);
}

void LCD_VoidDisplayStr (u8 *string){
	u8 i = 0;		//counter
	while (string[i] != '\0'){
		LCD_VoidWriteData(string[i]);
		i++;
	}
}

void LCD_VoidDisplayNum (u32 CopyNumber){
		u8 arr[11], c = 0;

		arr[c] = CopyNumber%10;
		//LCD_VoidWriteData(arr[c] + 48);

		CopyNumber /= 10;

		while(CopyNumber!=0){
			c++;
			arr[c] = CopyNumber%10;
			//LCD_VoidWriteData(arr[c] + 48);
			CopyNumber /= 10;
			//LCD_VoidWriteData(digit + 48);
		}
		//LCD_VoidWriteData(c + 48);

		for (int i = c; i >= 0; i--){
			LCD_VoidWriteData(arr[i] + 48);
		}
}


void LCD_VoidCustomCharacter (u8 *Pattern, u8 location){

	LCD_VoidWriteCommand(0x40 + location*8);

	for (int i  = 0; i < 8; i++){
		LCD_VoidWriteData(Pattern[i]);
	}
	//LCD_VoidGoToXY(0,5);

}

void LCD_VoidClrDisp (){
	LCD_VoidWriteCommand(0x01);
}

void LCD_MoveStr (u8 *string){
	for (int i = 0; i < 16; i++){
		LCD_VoidGoToXY(0, i);
		LCD_VoidDisplayStr (string);
		LCD_VoidClrDisp ();

	}
}


