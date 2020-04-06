#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "assembly.h"

/*using this method since my assmbly won't follow as I wanted. */
void switching_leds()//this method will make it easier to switch between red and green LED
{ 
  static enum {R=0, G=1} color = G;

  switch(color) {
  case G: green_on = 1; red_on = 0; led_update(); color = R; break;
  case R: green_on = 0; red_on = 1; led_update(); color = G; break;
  }
