#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H


void LCD_VoidWriteCommand(u8 CopyU8Command);

void LCD_VoidWriteData(u8 CopyU8Data);

void LCD_VoidInit();

void LCD_VoidGoToXY(u8 Copyu8x, u8 Copyu8y);

void LCD_VoidDisplayStr (u8 *string);

void LCD_VoidDisplayNum (u32 CopyNumber);

void LCD_VoidClrDisp ();

void LCD_VoidCustomCharacter (u8 *Pattern, u8 location);

void LCD_MoveStr (u8 *string);
#endif
