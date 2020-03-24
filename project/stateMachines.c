#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

static enum{START, MENU_OPTION0, MENU_OPTION1, MENU_OPTION2, MENU_OPTION3, FLASH} current_state = START;
char tempo;

void state_advance()
{
  switch(current_state) { /*the toy will always begin with both led lights on */
  case START:
    led_update(1, 1);
    if(switch1_state_down) { /*this will allow the user to choose betwween the four switches*/
      current_state = MENU_OPTION0;
    }else if(switch2_state_down) {
      current_state = MENU_OPTION1;
    }else if(switch3_state_down) {
      current_state = MENU_OPTION2;
    }else if(switch4_state_down) {
      current_state = MENU_OPTION3;
    }
    break;
  case MENU_OPTION0:/*MENU_OPTION0 is just flashing the red led light very quickly to make it dim*/
    tempo = 5;
    led_update(0,1);
    current_state = FLASH;
    if(side_switch_state_down) {
       current_state = START;
     }
    break;
  case FLASH: /*this is to help MENU_OPTION0 with the flash*/
    tempo = 5;
    led_update(0,0);
    current_state = MENU_OPTION0;
    if(side_switch_state_down) {
      current_state = START;
    }
    break;
  case MENU_OPTION1: /*the MENU_OPTION1 will flash red and green back and forth pretty quickly*/
    tempo = 75;
    switching_leds();
    if(side_switch_state_down) {
      current_state = START;
    }
    break;
  case MENU_OPTION2:/*the MENU_OPTION2 will play a sound that will slowly go higher then restart*/
    tempo = 50;
    song_one();
    if(side_switch_state_down) {
      current_state = START;
      buzzer_set_period(-1);
      reset_counters();
    }
    break;
  case MENU_OPTION3:/*the MENU_OPTION3 will play a song and the LED will flash with it*/
    tempo = 125;
    song_two();
    if(side_switch_state_down) {
      current_state = START;
      buzzer_set_period(-1);
      reset_counters();
    }
  }
}

void switching_leds()/*this method will make it easier to switch between red and green LED*/
{
  char changed = 0;
  static enum {R=0, G=1} color = G;
  switch(color) {
  case G: led_update(1,0); color = R; break;
  case R: led_update(0,1); color = G; break;
  }
}
