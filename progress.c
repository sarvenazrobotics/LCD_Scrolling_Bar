#include <mega328p.h>
#include <alcd.h>
#include <delay.h>
char i;
void main(void)
{
  #pragma optsize-
  CLKPR=(1<<CLKPCE);
  CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
  #ifdef _OPTIMIZE_SIZE_
  #pragma optsize+
  #endif

  lcd_init(16);

  while (1)
  {
    lcd_gotoxy(0,0);
    lcd_putchar(0x3E);
    for(i=1;i<16;i++)
    {
        lcd_gotoxy(i,0);
        lcd_putchar(0xFF);
        delay_ms(500);
    }
    delay_ms(1000);
    lcd_gotoxy(0,0);
    lcd_puts("                ");
  }
}
