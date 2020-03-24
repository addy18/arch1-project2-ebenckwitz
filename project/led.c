#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_on = 0, green_on = 0;
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS; // bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update()
{
    char ledFlags = redVal[red_on] | greenVal[green_on]; //by default, no LEDs on

    //ledFlags |= red_on ? LED_RED : 0;
    //ledFlags |= green_on ? LED_GREEN : 0;
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;     // set bit for on leds
    switch_state_changed = 0;
}