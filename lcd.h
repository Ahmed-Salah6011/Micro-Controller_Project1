#include "stdint.h"
#include "F:/tm4c123gh6pm.h"
#define LCD_DATA_R_PORT GPIO_PORTB_DATA_R
#define LCD_CTRL_R_PORT GPIO_PORTA_DATA_R

#define return_home 0x02
#define wakeup 0x30
#define clear 0x01
#define increment_cursor 0x06
#define Display_on 0x0F
#define cursor_blink 0x80 //cursor will be in the begining of first line 
#define mode_8bit 0x38 // 8_bits mode
#define cursor_second_line 0xc0


void lcd_init();
void lcd_command(char command);
void delayUs(int n);
void delayMs(int n);
void print_string(char *pstring);
void print_char(char c);
void lcd_initilization();
int str_len(char *s);
void print_center(char *s);
