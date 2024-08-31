/*
 * Electronic_voting_machine.c
 *
 * Created: 8/27/2024 5:19:26 PM
 *  Author: elsawah
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "button.h"
#include "LCD.h"

unsigned char counter1=0;
unsigned char counter2=0;
unsigned char counter3=0;
unsigned char counter4=0;
int main(void)
{
	LCD_init();
	button_init('D',0);
	button_init('D',1);
	button_init('D',2);
	button_init('D',3);
	button_init('D',4);
	LCD_SEND_STRING("A=0");
	LCD_MOVE_CURSOR(1,12);
	LCD_SEND_STRING("B=0");
	LCD_MOVE_CURSOR(2,1);
	LCD_SEND_STRING("C=0");
	LCD_MOVE_CURSOR(2,12);
	LCD_SEND_STRING("D=0");

    while(1)
    {
		if(button_read('D',0)==1)
		{
			counter1++;
			LCD_MOVE_CURSOR(1,3);
			if(counter1<10)
			{
				LCD_SEND_CHAR(counter1+48);
			}
			else if(counter1<100)
			{
				LCD_SEND_CHAR(counter1/10+48);
				LCD_SEND_CHAR(counter1%10+48);
			}
			
		}	
		else if(button_read('D',1)==1)
		{
			counter2++;
			LCD_MOVE_CURSOR(1,14);
			if(counter2<10)
			{
				LCD_SEND_CHAR(counter2+48);
			}
			else if(counter1<100)
			{
				LCD_SEND_CHAR(counter2/10+48);
				LCD_SEND_CHAR(counter2%10+48);
			}
		}
		else if(button_read('D',2)==1)
		{
			counter3++;
			LCD_MOVE_CURSOR(2,3);
			if(counter3<10)
			{
				LCD_SEND_CHAR(counter3+48);
			}
			else if(counter3<100)
			{
				LCD_SEND_CHAR(counter3/10+48);
				LCD_SEND_CHAR(counter3%10+48);
			}
		}
		else if(button_read('D',3)==1)
		{
			counter4++;
			LCD_MOVE_CURSOR(2,14);
			if(counter4<10)
			{
				LCD_SEND_CHAR(counter4+48);
			}
			else if(counter4<100)
			{
				LCD_SEND_CHAR(counter4/10+48);
				LCD_SEND_CHAR(counter4%10+48);
			}
		}
		else if(button_read('D',4)==1)
		{
			counter1=counter2=counter3=counter4=0;
			LCD_MOVE_CURSOR(1,1);
			LCD_SEND_STRING("A=0");
			LCD_MOVE_CURSOR(1,12);
			LCD_SEND_STRING("B=0");
			LCD_MOVE_CURSOR(2,1);
			LCD_SEND_STRING("C=0");
			LCD_MOVE_CURSOR(2,12);
			LCD_SEND_STRING("D=0");
		}
		_delay_ms(300);
    }
}