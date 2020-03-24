#ifndef switches_included
#define switches_included

#define SIDE_SW1 BIT3 /*switch is p1.3*/
#define SIDE_SWITCHES SIDE_SW1

#define SW1 BIT0          /* switch1 is p2.0 */
#define SW2 BIT1          /* switch2 is p2.1 */
#define SW3 BIT2          /* switch3 is p2.2 */
#define SW4 BIT3          /* switch4 is p2.3 */
#define SWITCHES (SW1 | SW2 | SW3 | SW4)      /* The four switches will be used */

void switch_init();
void switch_interrupt_handler();

extern char side_switch_state_down, switch1_state_down, switch2_state_down ,switch3_state_down, switch4_state_down;
#endif // included
