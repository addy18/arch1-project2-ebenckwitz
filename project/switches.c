#include <msp430.h>
#include "switches.h"
#include "led.h"

char side_switch_state_down, switch1_state_down, switch2_state_down, switch3_state_down, switch4_state_down, switch_state_changed;

static char
switch_update_interrupt_sense_p1()
{
  char p1val = P1IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);    /* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);   /* if switch down, sense up */
  return p1val;
}

static char
switch_update_interrupt_sense_p2()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);    /* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);   /* if switch down, sense up */
  return p2val;
}

void
switch_init()     /* setup switch */
{
  /*this is for the side switch on the toy */
  P1REN |= SIDE_SWITCHES;/* enables resistors for switches */
  P1IE = SIDE_SWITCHES;/* enable interrupts from switches */
  P1OUT |= SIDE_SWITCHES;/* pull-ups for switches */
  P1DIR &= ~SIDE_SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense_p1();

  /*this is for the four switches on the toy */
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE = SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense_p2();

  switch_interrupt_handler();
}

void
switch_interrupt_handler()
{
  /*this is for the side switch*/
  char p1val = switch_update_interrupt_sense_p1();
  side_switch_state_down = (p1val & SIDE_SW1) ? 0 : 1;
  
  /*for the four switches on the toy */
  char p2val = switch_update_interrupt_sense_p2();
  switch1_state_down = (p2val & SW1) ? 0 : 1;   /* 0 when SW1 is up */
  switch2_state_down = (p2val & SW2) ? 0 : 1;
  switch3_state_down = (p2val & SW3) ? 0 : 1;
  switch4_state_down = (p2val & SW4) ? 0 : 1;
  
  switch_state_changed = 1;
}
