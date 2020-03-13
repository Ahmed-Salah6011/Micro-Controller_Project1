#include "stdint.h"
#include "F:/tm4c123gh6pm.h"
#include "lcd.h"

//void SystemInit() {}



int main()
{
	
	//lcd_init();
	lcd_initilization();
	lcd_command(clear); /* clear display */
	lcd_command(cursor_blink); /* LCD cursor location */
	delayMs(500);
	
	print_char('h');
	//print_center("Please Enter");
	//lcd_command(cursor_second_line);
	//print_center("Password");
	
		
	delayMs(500);
	
	while(1)
	{
		
	}
	
	return 0;
}