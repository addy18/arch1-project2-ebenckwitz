#ifndef buzzer_included
#define buzzer_included

static int counter_song_one, counter_song_two;

void buzzer_init();
void song_one();
void song_two();
void reset_counters();
void buzzer_set_period(short cycles);

#endif // included
