##Description
The following toy that was created by Ethan Benckwitz and has four different
options on what to do. There are four different switches next to each other,
and another switch on the side of the toy to  head back into the menu of
options.

MAIN MENU: Before choosing any switch, both LED lights will be on to indicate
that you are inside the main menu.

SWITCH1: Choosing this will blink the red LED really fast to the point
where it almost looks like it is partially dim.

SWITCH2: Choosing this will blink the red and green LED back and forth in a
quickly matter. I wrote this code in the assembly.s file and it works properly. I
make two calls in the state machine so the lights can switch back and forth
because my assembly code just switches the LED light from one to another.  

SWITCH3: Choosing this will leave both LED lights on but the buzzer will play
an ascending sound! Once it reaches the top it will go back to the very
beginning and replay the sound.

SWITCH4: Choosing this will play a little song created by Ethan and the LED
lights will match each different sound produced. Once the song is over it will
continue to replay until main menu button is pressed.

When wanting to compile it, all you have to do is type make load to activate
the toy! IMPORTANT: When toy is first compiled, it takes me a couple of
presses  or a more forced push on a button to activate the toy. After that,
pressing other buttons are not an issue.


*Once you are inside any of the switches, you cannot press any other button to
 expect an action. You must press the return to menu button which is on the
 side of the toy in order to use the other switches (Both LED lights on
 without noise indicate that you are inside the menu).
