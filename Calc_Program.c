/*
 * Calc_Program.c
 *
 *  Created on: Aug 15, 2022
 *      Author: noure
 */
#include "STD_TYPES.h"
#include "KP_Interface.h"
#include "Calc_Private.h"
#include "LCD_Interface.h"
#include "Calc_Interface.h"

void ComputeNumber(u32 *operand1,u32 *operand2, u8 input, u8 tracker, s8 Bias){
	LCD_VoidWriteData(input - Bias + 48);	//Display the input digit
	switch(tracker){
		case  OPRAND1:
			*operand1 = *operand1*10 + input - Bias;
			break;
		case  OPRAND2:
			*operand2 = (*operand2)*10 + input - Bias;
	}
}

void PlaceOperator(u8 input, u8 *operator, u8 *tracker){
	if (input != CLEAR){
		LCD_VoidWriteData(*operator);
		switch(input){
			case ADD:
				*operator = '+';
				break;
			case SUBTRACT:
				*operator = '-';
				break;
			case MULTIPLY:
				*operator = '*';
				break;
			case DIVIDE:
				*operator = '/';
				break;
		}
	}
	else{
		LCD_VoidClrDisp();
		*tracker = OPRAND1;
	}
}

void Operation(u32 op1, u32 op2, u8 operator){
	LCD_VoidGoToXY(1,0);
	LCD_VoidWriteData('=');
	u32  res;

	switch (operator){
		case '+':
			res = op1 + op2;
			LCD_VoidDisplayNum(res);
			break;
		case '-':
			res = op1 - op2;
			LCD_VoidDisplayNum(res);
			break;
		case '*':
			res =op1 * op2;
			LCD_VoidDisplayNum(res);
			break;
		case '/':
			res =op1 / op2;
			LCD_VoidDisplayNum(res);
			break;
	}
}


void Calculator(){
	u8 input, operator, tracker = OPRAND1;
	u32 op1 = 0, op2 = 0;

	while(1){
		input = KP_Switches ();

		if (input >= one && input <= three){
			ComputeNumber(&op1, &op2, input, tracker, Bias1);
		}
		else if (input >= four && input <= six){
			ComputeNumber(&op1, &op2, input, tracker, Bias2);
		}
		else if (input >= seven && input <= nine){
			ComputeNumber(&op1, &op2, input, tracker, Bias3);
		}
		else if (input == zero){
			ComputeNumber(&op1, &op2, 0, tracker, 0);
		}
		else if (input != 0){
			if (input != EQUAL){
				tracker = OPRAND2;
				PlaceOperator(input, &operator, &tracker);
				if (input == CLEAR){
					op1 = 0;
					op2 = 0;
				}
			}
			else{
				tracker = OPRAND1;
				Operation(op1, op2, operator);
				op1 = 0;
				op2 = 0;
			}
		}
	}
}
