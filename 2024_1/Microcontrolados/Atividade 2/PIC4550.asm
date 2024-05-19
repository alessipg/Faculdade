; ===========================================================================
;	=-=-=-=-=-=-=-   DISCIPLINA SISTEMAS MICROPROCESSADOS   -=-=-=-=-=-=-=-=
;	PROGRAMA-BASE PARA MICROCONTROLADOR PIC18F4520/4550
;	Cristhiane Gonçalves
;	MAR/2024
; ===========================================================================

; --- 18f4520 ---
;#INCLUDE <P18F4520.INC>
;	CONFIG OSC = HS
;	CONFIG PWRT = ON
;	CONFIG WDT = OFF
;	CONFIG MCLRE = ON
;	CONFIG LVP = ON
;	CONFIG DEBUG = OFF

; --- 18f4550 ---
#INCLUDE <P18F4550.INC>
	CONFIG FOSC = HSPLL_HS
	CONFIG LVP = OFF
	CONFIG MCLRE = ON
	CONFIG WDT = OFF
	CONFIG DEBUG = OFF
	CONFIG PWRT = ON
	CONFIG PLLDIV = 4
	CONFIG CPUDIV = OSC3_PLL4
	CONFIG USBDIV = 1

; ===========================================================================
; *                         DEFINICAO DAS VARIAVEIS
; ===========================================================================

	CBLOCK	0x20
		W_TEMP		; Temporary storage for W register
		STATUS_TEMP	; Temporary storage for STATUS register
		BSR_TEMP	; Temporary storage for BSR register
		CONT		; Your existing variable
	ENDC


; ===========================================================================
; *                   VETOR DE RESET DO MICROCONTROLADOR
; ===========================================================================

		ORG		0X0000		; ENDERECO DO VETOR DE RESET
		GOTO	INICIO		; DESVIA PARA O INICIO DO PROGRAMA

; ===========================================================================
; *                             INTERRUPCOES
; ===========================================================================

		ORG		0x0008		; VETOR DE INTERRUPCOES DE ALTA PRIORIDADE
		MOVWF	W_TEMP			; SALVAMENTO DE CONTEXTO
		MOVFF	STATUS,STATUS_TEMP
		MOVFF	BSR,BSR_TEMP
		GOTO	HIGH_PRIORITY

; ===========================================================================

		ORG		0x0018		; VETOR DE INTERRUPCOES DE BAIXA PRIORIDADE
		MOVWF	W_TEMP			; SALVAMENTO DE CONTEXTO
		MOVFF	STATUS,STATUS_TEMP
		MOVFF	BSR,BSR_TEMP
		;GOTO	LOW_PRIORITY

LOW_PRIORITY
		GOTO	FIMINT

; ---------------------------------------------------------------------------
HIGH_PRIORITY
		GOTO	FIMINT

; ---------------------------------------------------------------------------
FIMINT
		MOVFF	BSR_TEMP,BSR	; RESTAURACAO DE CONTEXTO
		MOVF	W_TEMP,W
		MOVFF	STATUS_TEMP,STATUS
		RETFIE

; ===========================================================================
;                           PROGRAMA PRINCIPAL
; ===========================================================================

INICIO
		GOTO	ITEM_A

ITEM_A
L2		MOVLW	0X09		; 9 -> W
		MOVWF	CONT		; W -> CONT
L1		DECF	CONT,F		; CONT-1 -> CONT
		MOVLW	D'0'		; CONT -> W
		SUBWF	CONT,W		; CONT-W -> W
		BTFSS	STATUS,Z	; ZERO?
		GOTO	L1			; N?O
		GOTO	L2			; SIM


; ===========================================================================
; *                            SUBROTINAS
; ===========================================================================



; ===========================================================================
; *                            FIM DO PROGRAMA
; ===========================================================================

		END				; FIM DO PROGRAMA