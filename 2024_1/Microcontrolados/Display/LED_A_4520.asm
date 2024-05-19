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
;	;CONFIG PLLDIV = 4
;	;CONFIG CPUDIV = OSC3_PLL4
;	;CONFIG USBDIV = 1

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
		TEMP
		TENS
		UNITS
	ENDC

; ===========================================================================
; *                   VETOR DE RESET DO MICROCONTROLADOR
; ===========================================================================

		ORG		0X0000		; ENDERECO DO VETOR DE RESET
		GOTO	INICIO		; DESVIA PARA O INICIO DO PROGRAMA

; ===========================================================================
;                           PROGRAMA PRINCIPAL
; ===========================================================================

INICIO	
		CLRF 	TRISB
		MOVLW	0x06
		MOVWF   ADCON1
		CLRF	TRISA
		
		CLRF	TENS
		CLRF	UNITS
		CLRF	PORTA
		MOVLW D'0'
		MOVWF TRISD
		GOTO	PROGRAMA_A

PROGRAMA_A
    BSF PORTA, 2 ; Desliga RA2 (display 1)
    BSF PORTA, 3 ; Desliga RA3 (display 2)
	BSF PORTA, 4 ; Liga RA4 (display 3)
    BSF PORTA, 5 ; Desliga RA5 (display 4)
	MOVLW D'0'
CONTADOR
    MOVWF TEMP ; Armazena o valor atual de W em TEMP
    CALL TABELA
    MOVWF PORTD ; Move o valor da tabela para PORTD
	CALL T250ms
	CALL T250ms
    MOVF TEMP,W ; Restaura o valor original de W a partir de TEMP
    ADDLW 0X02
    GOTO CONTADOR ; Loop de volta para o contador

    
		
TABELA
		ADDWF	PCL
		RETLW 	B'00111111' ;0
		RETLW 	B'00000110' ;1
		RETLW 	B'01011011' ;2
		RETLW 	B'01001111' ;3
		RETLW 	B'01100110' ;4
		RETLW 	B'01101101' ;5
		RETLW 	B'01111101' ;6
		RETLW 	B'00100111' ;7
		RETLW 	B'01111111' ;8
		RETLW 	B'01101111' ;9
		RETLW 	B'01110111' ;A
		RETLW 	B'01111100' ;B
		RETLW 	B'00111001' ;C
		RETLW 	B'01011110' ;D
		RETLW 	B'01111001' ;E
		RETLW 	B'01110001' ;F

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