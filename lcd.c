#include "lcd.h"

/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}

/* delay n microseconds (16 MHz CPU clock) */
void delayUs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3; j++)
{} /* do nothing for 1 us */
}


void lcd_init()
{
	////enable A & B
	SYSCTL_RCGCGPIO_R |= 0x03;
	while((SYSCTL_PRGPIO_R & 0x03) ==0){}
	
	//////Port A init
	//GPIO_PORTA_LOCK_R = 0x4c4f434b;
	//GPIO_PORTA_CR_R |= 0xE0;
	GPIO_PORTA_DIR_R |=0xE0;
	GPIO_PORTA_DEN_R |= 0xE0;
	GPIO_PORTA_AFSEL_R =0;
	GPIO_PORTA_AMSEL_R =0;
	GPIO_PORTA_PUR_R =0;
	GPIO_PORTA_PCTL_R =0;
	
		
	///port B init
	GPIO_PORTB_LOCK_R = 0x4c4f434b;
	GPIO_PORTB_CR_R = 0xFF;
	GPIO_PORTB_DIR_R =0xFF;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTB_AFSEL_R =0;
	GPIO_PORTB_AMSEL_R =0;
	GPIO_PORTB_PUR_R =0;
	GPIO_PORTB_PCTL_R =0;	
	
	
}


void lcd_command(char command)
{
LCD_CTRL_R_PORT&=0x1f;
LCD_DATA_R_PORT=command;
LCD_CTRL_R_PORT|=0x80;
delayMs(2);
LCD_CTRL_R_PORT&=~(0x80);
}

void print_char(char c)
{
		    LCD_CTRL_R_PORT |= 0x20;
				LCD_DATA_R_PORT = c;
				LCD_CTRL_R_PORT |=0xA0;
				delayMs(2);
				LCD_CTRL_R_PORT&=~(0x80);
}

void print_string(char *pstring)
{
		int i,j;
		i=0;
		while(pstring[i] != '\0')
		{
			print_char(pstring[i]);
			i++;
			if(i==16)
			{ 
				lcd_command(cursor_second_line);
			}
			if (i==31)
			{
				print_char('>');
				i++;
			}
			
		}
	
}

int str_len(char *s)
{
	int i=0;
	while(s[i] != '\0')
	{
		i++;
	}
	return i;
}

void print_center(char *s)
{
	int shift,i;
	int len = str_len(s);
	if(len >=16)
	{
		print_string(s);
	}
	else
	{
		shift=(16-len)/2;
		for(i=0 ; i<shift ; i++) print_char(' ');
		print_string(s);
	}
	
}

void lcd_initilization()
{
	lcd_init();
	delayMs(20);
	lcd_command(wakeup);
	delayMs(5);
	lcd_command(wakeup);
	delayUs(100);
	lcd_command(wakeup);
	delayUs(100);
	
	lcd_command(mode_8bit);
	lcd_command(increment_cursor);
	lcd_command(clear);
	lcd_command(Display_on);
	//lcd_command(cursor_blink);
}
