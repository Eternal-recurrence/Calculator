#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"


void DIO_VoidSetPinDirection (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDir){
	if(Copy_u8PinDir == 1){
		switch(Copy_u8PortID){
			case PortA_ID:		//Port A
				DDRA_REG = SetBit(DDRA_REG, Copy_u8PinID);
				break;
			case PortB_ID:		//Port B
				DDRB_REG = SetBit(DDRB_REG, Copy_u8PinID);
				break;
			case PortC_ID:		//Port C
				DDRC_REG = SetBit(DDRC_REG, Copy_u8PinID);
				break;
			case PortD_ID:		//Port D
				DDRD_REG = SetBit(DDRD_REG, Copy_u8PinID);
				break;
		}
	}
	else if(Copy_u8PinDir == 0){
		switch(Copy_u8PortID){
			case PortA_ID:		//Port A
				DDRA_REG = ClearBit(DDRA_REG, Copy_u8PinID);
				break;
			case PortB_ID:		//Port B
				DDRB_REG = ClearBit(DDRB_REG, Copy_u8PinID);
				break;
			case PortC_ID:		//Port C
				DDRC_REG = ClearBit(DDRC_REG, Copy_u8PinID);
				break;
			case PortD_ID:		//Port D
				DDRD_REG = ClearBit(DDRD_REG, Copy_u8PinID);
				break;
		}
	}	
}

void DIO_VoidSetPinValue (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue){
	if(Copy_u8PinValue == 1){
		switch(Copy_u8PortID){
			case PortA_ID:		//Port A
				PORTA_REG = SetBit(PORTA_REG, Copy_u8PinID);
				break;
			case PortB_ID:		//Port B
				PORTB_REG = SetBit(PORTB_REG, Copy_u8PinID);
				break;
			case PortC_ID:		//Port C
				PORTC_REG = SetBit(PORTC_REG, Copy_u8PinID);
				break;
			case PortD_ID:		//Port D
				PORTD_REG = SetBit(PORTD_REG, Copy_u8PinID);
				break;
		}
	}
	else if(Copy_u8PinValue == 0){
		switch(Copy_u8PortID){
			case PortA_ID:		//Port A
				PORTA_REG = ClearBit(PORTA_REG, Copy_u8PinID);
				break;
			case PortB_ID:		//Port B
				PORTB_REG = ClearBit(PORTB_REG, Copy_u8PinID);
				break;
			case PortC_ID:		//Port C
				PORTC_REG = ClearBit(PORTC_REG, Copy_u8PinID);
				break;
			case PortD_ID:		//Port D
				PORTD_REG = ClearBit(PORTD_REG, Copy_u8PinID);
				break;
		}
	}
}

void DIO_VoidSetPortDirection (u8 Copy_u8PortID, u8 Copy_u8PortDirection){
	switch(Copy_u8PortID){
		case PortA_ID:		//Port A
			DDRA_REG = Copy_u8PortDirection;
			break;
		case PortB_ID:		//Port B
			DDRB_REG = Copy_u8PortDirection;
			break;
		case PortC_ID:		//Port C
			DDRC_REG = Copy_u8PortDirection;
			break;
		case PortD_ID:		//Port D
			DDRD_REG = Copy_u8PortDirection;
			break;
	}
}

void DIO_VoidSetPortValue (u8 Copy_u8PortID, u8 Copy_u8PortValue){
	switch(Copy_u8PortID){
		case PortA_ID:		//Port A
			PORTA_REG = Copy_u8PortValue;
			break;
		case PortB_ID:		//Port B
			PORTB_REG = Copy_u8PortValue;
			break;
		case PortC_ID:		//Port C
			PORTC_REG = Copy_u8PortValue;
			break;
		case PortD_ID:		//Port D
			PORTD_REG = Copy_u8PortValue;
			break;
	}
}

u8 DIO_U8GetPinValue (u8 Copy_u8PortID, u8 Copy_u8PinID){
	u8 value;
	switch(Copy_u8PortID){
		case PortA_ID:		//Port A
			value = GetBit(PINA_REG, Copy_u8PinID);
			break;
		case PortB_ID:		//Port B
			value = GetBit(PINB_REG, Copy_u8PinID);
			break;
		case PortC_ID:		//Port C
			value = GetBit(PINC_REG, Copy_u8PinID);
			break;
		case PortD_ID:		//Port D
			value = GetBit(PIND_REG, Copy_u8PinID);
		}
	return value;
}

void DIO_VoidTogglePin (u8 Copy_u8PortID, u8 Copy_u8PinID){
	switch(Copy_u8PortID){
		case PortA_ID:		//Port A
			PORTA_REG = Toggle(PORTA_REG, Copy_u8PinID);
			break;
		case PortB_ID:		//Port B
			PORTB_REG = Toggle(PORTB_REG, Copy_u8PinID);
			break;
		case PortC_ID:		//Port C
			PORTC_REG = Toggle(PORTC_REG, Copy_u8PinID);
			break;
		case PortD_ID:		//Port D
			PORTD_REG = Toggle(PORTD_REG, Copy_u8PinID);
			break;
		}
}

