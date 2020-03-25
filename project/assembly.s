	.arch msp430g2553
	
	.text
	.global switching_leds_assembly
switching_leds_assembly:
	cmp.b #1, &green_on	; if green is on
	jmp red			; go to red
	
	mov.b #1, &green_on	; turn on green light
	mov.b #0, &red_on	; turn off red light
	call led_update		; call led_upate to use LEDs
	jmp end 		; go to red 


red:	mov.b #0, &green_on	; turn off green light
	mov.b #1, &red_on	; turn on red light
	jmp end			; go to red
/*
green:	mov.b #1, &green_on	; turn on green light
	mov.b #0, &red_on	; turn off red light
	call led_update		; call led_upate to use LEDs
	jmp red	*/		; go to red 

end:	ret			; end

