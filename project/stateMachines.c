#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "assembly.h"

static enum{START, MENU_OPTION0, MENU_OPTION1, MENU_OPTION2, MENU_OPTION3, FLASH, assembly_help} current_state = START;
char tempo;

void state_advance()
{
  switch(current_state) { /*the toy will always begin with both led lights on */
  case START:
    red_on = 1;
    green_on = 1;
    led_update();
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
    red_on = 1, green_on = 0;
    led_update();
    current_state = FLASH;
    if(side_switch_state_down) {
       current_state = START;
     }
    break;
  case FLASH: /*this is to help MENU_OPTION0 with the flash*/
    tempo = 5;
    red_on = 0, green_on = 0;
    led_update();
    current_state = MENU_OPTION0;
    if(side_switch_state_down) {
      current_state = START;
    }
    break;
  case MENU_OPTION1: /*the MENU_OPTION1 will flash red and green back and forth pretty quickly*/
    tempo = 75;
    red_on = 1;
    green_on = 0;
    switching_leds_assembly();
    led_update();
    current_state = assembly_help;
     if(side_switch_state_down) {
	current_state = START;
      }

    break;
  case assembly_help: /*this will help the assembly code repeatedly flash the LEDs*/
    tempo = 75;
    switching_leds_assembly();
    led_update();
    current_state = assembly_help;
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

/*using this method since my assmbly won't follow as I wanted. */
void switching_leds()//this method will make it easier to switch between red and green LED
{ 
  static enum {R=0, G=1} color = G;

  switch(color) {
  case G: green_on = 1; red_on = 0; led_update(); color = R; break;
  case R: green_on = 0; red_on = 1; led_update(); color = G; break;
  }
} 
