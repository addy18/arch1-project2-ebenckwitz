#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;    // bits attached to leds are output
}

void led_update(int red_on, int green_on)
{
    char ledFlags = 0; //by default, no LEDs on

    ledFlags |= red_on ? LED_RED : 0;
    ledFlags |= green_on ? LED_GREEN : 0;
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;     // set bit for on leds
}
