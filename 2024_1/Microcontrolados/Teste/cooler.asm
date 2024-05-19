;============================================================================
;	PROGRAMA PARA CONTROLAR UMA VENTOINHA COM PIC18F4520
;	Cristhiane 
;	abril/2024
; ===========================================================================

; --- Configurações ---
#INCLUDE <P18F4520.INC>
	CONFIG OSC = HS
	CONFIG PWRT = ON
	CONFIG WDT = OFF
	CONFIG MCLRE = ON
	CONFIG LVP = ON
	CONFIG DEBUG = OFF

; --- Variáveis ---
	CBLOCK	0x20
		; Declare quaisquer variáveis necessárias aqui
	ENDC

; ===========================================================================
; *                   VETOR DE RESET DO MICROCONTROLADOR
; ===========================================================================

		ORG		0X0000		; ENDEREÇO DO VETOR DE RESET
		GOTO	INICIO		; DESVIA PARA O INÍCIO DO PROGRAMA

; ===========================================================================
;                           PROGRAMA PRINCIPAL
; ===========================================================================

INICIO	
	; Configurar o pino RC2 como saída
    BCF     TRISC, 2       ; RC2 como saída
    
    ; Loop principal
LOOP    
    ; Ligar a ventoinha
    BSF     PORTC, 2       ; RC2 = 1 (ligado)
    
    ; Aguardar um tempo (por exemplo, 5 segundos)
    CALL    T5000ms
    
    ; Desligar a ventoinha
    BCF     PORTC, 2       ; RC2 = 0 (desligado)
    
    ; Aguardar um tempo (por exemplo, 5 segundos)
    CALL    T5000ms
    
    ; Repetir o loop
    GOTO    LOOP

; ===========================================================================
; *                            SUBROTINAS
; ===========================================================================

T5000ms	; Sub-rotina para aguardar 5 segundos
    MOVLW   D'50'      ;Carregar W com um valor apropriado para contar 5 segundos
    CALL    T100ms     ; Chamada da sub-rotina de 100ms (50x para 5 segundos)
    RETURN

T100ms	; Sub-rotina para aguardar 100ms
	; Esta sub-rotina já foi fornecida no seu código original
    ; Implementação da sub-rotina T100ms
    ; ...
    RETURN

; ===========================================================================
; *                            FIM DO PROGRAMA
; ===========================================================================

		END				; FIM DO PROGRAMA
