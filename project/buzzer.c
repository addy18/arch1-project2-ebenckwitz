#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
  /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
  */
  timerAUpmode();      /* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;        /* enable output to speaker (P2.6) */
}

static int counter_song_one = 0;
void song_one()
{
  switch(counter_song_one) {
  case 0: buzzer_set_period(200); counter_song_one++; break;
  case 1: buzzer_set_period(250); counter_song_one++; break;
  case 2: buzzer_set_period(300); counter_song_one++; break;
  case 3: buzzer_set_period(350); counter_song_one++; break;
  case 4: buzzer_set_period(400); counter_song_one++; break;
  case 5: buzzer_set_period(450); counter_song_one++; break;
  case 6: buzzer_set_period(500); counter_song_one++; break;
  case 7: buzzer_set_period(550); counter_song_one++; break;
  case 8: buzzer_set_period(600); counter_song_one++; break;
  case 9: buzzer_set_period(650); counter_song_one++; break;
  case 10: buzzer_set_period(700); counter_song_one++; break;
  case 11: buzzer_set_period(750); counter_song_one++; break;
  case 12: buzzer_set_period(800); counter_song_one++; break;
  case 13: buzzer_set_period(850); counter_song_one++; break;
  case 14: buzzer_set_period(900); counter_song_one++; break;
  case 15: buzzer_set_period(950); counter_song_one++; break;
  case 16:
    buzzer_set_period(1000);
    if(counter_song_one==16){
      counter_song_one = 0;
    } else{
      counter_song_one++;
    }
    break;
  }
}

static int counter_song_two = 0;
void song_two()
{
  switch(counter_song_two) {
  case 0: 
  case 6: 
  case 19: buzzer_set_period(800); counter_song_two++; led_update(0,1); break; 
  case 1:
  case 7: 
  case 20: buzzer_set_period(750); counter_song_two++; led_update(1,0); break;
  case 2:
  case 8: 
  case 21: buzzer_set_period(600); counter_song_two++; led_update(1,1); break;
  case 3:
  case 9: 
  case 22: buzzer_set_period(650); counter_song_two++; led_update(0,1); break; 
  case 4:
  case 10: 
  case 23: buzzer_set_period(500); counter_song_two++; led_update(1,0); break;
  case 5:
  case 11: 
  case 24:
    buzzer_set_period(550);
    led_update(1,1);
    if(counter_song_two== 24) {
      counter_song_two = 0;
    }else{
      counter_song_two++;
    }
    break;
  case 12: buzzer_set_period(1000); counter_song_two++; led_update(1,0); break;
  case 13: buzzer_set_period(1050); counter_song_two++; led_update(0,1); break;
  case 14: buzzer_set_period(900); counter_song_two++; led_update(1,1); break;
  case 15: buzzer_set_period(950); counter_song_two++; led_update(1,0); break;
  case 16: buzzer_set_period(1500); counter_song_two++; led_update(0,1); break;
  case 17: buzzer_set_period(800); counter_song_two++; led_update(1,1); break;
  case 18: buzzer_set_period(850); counter_song_two++; led_update(0,0); break;
  }
}

void reset_counters()/*this will reset the counters. Songs will restart when switch is pressed*/
{
  counter_song_one = 0;
  counter_song_two = 0;
}

void buzzer_set_period(short cycles)/* buzzer clock = 2MHz. (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;  /* one half cycle */
}
