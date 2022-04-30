#define __SFR_OFFSET 0
#include <avr/io.h>

.global delay

.section .text

delay:	;this is delay (function)
	lp2:
		IN r30, TIFR0 ;tifr is timer interupt flag (8 bit timer runs 256 times)
		ldi r17, 0b00000010
		AND r30, r17 ;need second bit
		BREQ delay 
		OUT TIFR0, r17	;set tifr flag high
	dec r24
	brne lp2
	ret