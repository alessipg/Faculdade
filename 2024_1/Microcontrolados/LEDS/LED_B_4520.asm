;============================================================================
;	PROGRAMA-BASE PARA MICROCONTROLADOR PIC18F4520/4550
;	Cristhiane 
;	abril/2024
; ===========================================================================

; --- 18f4520 ---
#INCLUDE <P18F4520.INC>
	CONFIG OSC = HS
	CONFIG PWRT = ON
	CONFIG WDT = OFF
	CONFIG MCLRE = ON
	CONFIG LVP = ON
	CONFIG DEBUG = OFF

; --- 18f4550 ---
;#INCLUDE <P18F4550.INC>
;	CONFIG FOSC = HSPLL_HS
;	CONFIG LVP = OFF
;	CONFIG MCLRE = ON
;	CONFIG WDT = OFF
;	CONFIG DEBUG = OFF
;	CONFIG PWRT = ON
;	CONFIG PLLDIV = 4
;	CONFIG CPUDIV = OSC3_PLL4
;	CONFIG USBDIV = 1

; ===========================================================================
; *                         DEFINI??O DAS VARI?VEIS
; ===========================================================================

;CONT   EQU   0x22
;C1     EQU   0x23
;C2     EQU   0x24
;
	CBLOCK	0x22
		CONT
		C1
		C2
	ENDC

; ===========================================================================
; *                   VETOR DE RESET DO MICROCONTROLADOR
; ===========================================================================

		ORG		0X0000		; ENDERECO DO VETOR DE RESET
		GOTO	INICIO		; DESVIA PARA O INICIO DO PROGRAMA

; ===========================================================================
;                           PROGRAMA PRINCIPAL
; ===========================================================================

INICIO	GOTO	PROGRAMA_B

PROGRAMA_A
		MOVLW	D'0'		; 0 -> W
		MOVWF	TRISD		; W -> TRISD
LA1		MOVLW	B'11111111'	; 11111111 -> W
		MOVWF	PORTD		; W -> PORTD
		CALL	T250ms
		MOVLW	B'00000000'	; 00000000 -> W
		MOVWF	PORTD		; W -> PORTD
		CALL	T250ms
		GOTO	LA1

PROGRAMA_B
		movlw	b'00000000'
		movwf	TRISD

		movlw	b'00000001'
		movwf	PORTD
LB1		call	T100ms
		rlncf	PORTD,F		; rotate left PORTD -> PORTD
		btfss	PORTD,7		; bit 7 da PORTD é igual a 1? Se sim, pula
		goto	LB1
LB2		call	T100ms
		rrncf	PORTD,F		; rotate left PORTD -> PORTD
		btfss	PORTD,0		; bit 0 da PORTD é igual a 1? Se sim, pula
		goto	LB2
		goto	LB1

; ===========================================================================
; *                            SUBROTINAS
; ===========================================================================

T100ms	MOVLW	D'2'	; 2 -> W
		MOVWF	CONT	; W -> CONT

REP3	MOVLW	D'130'	; 130 -> W
		MOVWF	C1		; W -> C1
		MOVLW	D'178'	; 178 -> W
		MOVWF	C2		; W -> C2
REP4	DECFSZ	C2,F	; C2-1 -> C2. Deu zero? Se sim, pula
		GOTO	REP4	; Se não, vai para REP
		DECFSZ	C1,F	; C1-1 -> C1. Deu zero? Se sim, pula
		GOTO	REP4	; Se não, vai para REP

		DECFSZ	CONT,F	; CONT-1 -> CONT. Deu zero? Se sim, pula
		GOTO	REP3	; Se não, vai para REPETE
		RETURN

; ---------------------------------------------------------------------------

T250ms	MOVLW	D'4'	; 4 -> W
		MOVWF	CONT	; W -> CONT

REPETE	MOVLW	D'163'	; 163 -> W
		MOVWF	C1		; W -> C1
		MOVLW	D'30'	; 30 -> W
		MOVWF	C2		; W -> C2
REP		DECFSZ	C2,F	; C2-1 -> C2. Deu zero? Se sim, pula
		GOTO	REP		; Se não, vai para REP
		DECFSZ	C1,F	; C1-1 -> C1. Deu zero? Se sim, pula
		GOTO	REP		; Se não, vai para REP

		DECFSZ	CONT,F	; CONT-1 -> CONT. Deu zero? Se sim, pula
		GOTO	REPETE	; Se não, vai para REPETE
		RETURN

; ===========================================================================
; *                            FIM DO PROGRAMA
; ===========================================================================

		END				; FIM DO PROGRAMA

