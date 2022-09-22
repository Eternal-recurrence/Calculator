#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

#define Input 0
#define Output 1

#define High 1
#define Low 0

#define PortA_ID 0
#define PortB_ID 1
#define PortC_ID 2
#define PortD_ID 3

#define PIN_ID0 0X00
#define PIN_ID1 0X01
#define PIN_ID2 0X02
#define PIN_ID3 0X03
#define PIN_ID4 0X04
#define PIN_ID5 0X05
#define PIN_ID6 0X06
#define PIN_ID7 0X07

		/*Prototypes*/
void DIO_VoidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDir);

void DIO_VoidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue);

void DIO_VoidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDirection);

void DIO_VoidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue);

u8 DIO_U8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);

void DIO_VoidTogglePin(u8 Copy_u8PortID, u8 Copy_u8PinID);

#endif
