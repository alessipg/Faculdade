; PROGRAM BASE FOR MICROCONTROLLER PIC18F4520/4550
; Cristhiane
; April 2024
; ===========================================================================

; --- 18f4520 ---
#INCLUDE <P18F4520.INC>
    CONFIG OSC = HS
    CONFIG PWRT = ON
    CONFIG WDT = OFF
    CONFIG MCLRE = ON
    CONFIG LVP = ON
    CONFIG DEBUG = OFF

; ===========================================================================
; * DEFINITION OF VARIABLES
; ===========================================================================

    CBLOCK  0x22
        CONT
        C1
        C2
		TEMP
    ENDC

; ===========================================================================
; * MICROCONTROLLER RESET VECTOR
; ===========================================================================

        ORG     0X0000      ; RESET VECTOR ADDRESS
        GOTO    INICIO      ; JUMP TO PROGRAM START

; ===========================================================================
; MAIN PROGRAM
; ===========================================================================

INICIO  GOTO    PROGRAMA_A

; Add your program logic here

PROGRAMA_A:
    ; Increment CT (you can replace this with your own logic)
    INCF    CONT, F     ; Increment CT

    ; Call the decoding subroutine to convert CT value to LED patterns
    CALL    DECODE_CT   ; Subroutine to decode CT value

    ; Your other program logic goes here

    ; End of program
    SLEEP               ; Put the microcontroller to sleep (optional)
    GOTO    PROGRAMA_A  ; Loop back to the beginning

; Subroutine to decode CT value and display on 7-segment display
DECODE_CT:
    ; Get the lower nibble of CT (0 to F)
    ANDLW   H'0F'       ; Mask out upper nibble
    ADDLW   LOW TABELA  ; Add offset to TABELA address
    MOVWF   TEMP        ; Store result in TEMP

    ; Set PCLATH based on carry bit (if needed)
    MOVLW   HIGH TABELA
    BTFSC   STATUS, C
    ADDLW   0X01
    MOVWF   PCLATH

    ; Load RETLW value from TABELA
    MOVF    TEMP, W
    MOVWF   PCL

    RETURN

; TABELA: Lookup table for 7-segment display patterns
TABELA
    RETLW   B'00111111' ; 0
    RETLW   B'00000110' ; 1
    RETLW   B'01011011' ; 2
    RETLW   B'01001111' ; 3
    RETLW   B'01100110' ; 4
    RETLW   B'01101101' ; 5
    RETLW   B'01111101' ; 6
    RETLW   B'00100111' ; 7
    RETLW   B'01111111' ; 8
    RETLW   B'01101111' ; 9
    RETLW   B'01110111' ; A
    RETLW   B'01111100' ; B
    RETLW   B'00111001' ; C
    RETLW   B'01011110' ; D
    RETLW   B'01111001' ; E
    RETLW   B'01110001' ; F

END