.data
    questao:
        .align 2
        .word 1, 2, 1, 3, 4, 2, 2, 4, 4, 3, 3, 4, 2, 4, 1, 1, 1, 1, 1
    gabarito:
        .align 2
        .word 2, 1, 1, 3, 4
    resultado:
        .align 2
        .space 16
.text
    # Inicialização de registradores
    move $t0, $zero # Contagem de alunos com 5 acertos
    move $t1, $zero # Contagem de alunos com 1 a 4 acertos
    move $t2, $zero # Contagem de alunos que erraram tudo
    move $t3, $zero # Índice das respostas do aluno
    move $t4, $zero # Índice das respostas do gabarito
    move $t5, $zero # Resposta do aluno
    move $t6, $zero # Resposta do gabarito
    move $t7, $zero # Contagem de acertos do aluno

LOOP_ALUNO:
    beq $t0, 4, FIM
    move $t1, $zero
    move $t7, $zero
    move $t4, $zero
    LOOP_CORRECAO:
        beq $t1, 5, PROXIMO_ALUNO
        lw $t5, questao($t3)
        lw $t6, gabarito($t4)
        bne $t5, $t6, NPONTUAR
        addi $t7, $t7, 1
        NPONTUAR:
            addi $t3, $t3, 4
            addi $t4, $t4, 4
            addi $t1, $t1, 1
        j LOOP_CORRECAO
    PROXIMO_ALUNO:
        sw $t7, resultado($t0) # Grava o resultado do aluno na posição correta
        addi $t0, $t0, 4
        addi $t3, $t3, 0 # Redefine o índice das respostas do aluno
        j LOOP_ALUNO
    FIM:
        move $t0, $zero
        move $t1, $zero
        move $t2, $zero
        move $t3, $zero
        move $t4, $zero
        LOOP_FIM:
            lw $t3, resultado($t0)
            bne $t3, 5, ELSE1
            addi $t0, $t0, 4
            j CONTINUAR
            ELSE1:
            beqz $t3, ELSE2
            addi $t1, $t1, 1
            ELSE2:
            addi $t2, $t2, 1
            CONTINUAR:
            addi $t0, $t0, 4
            bgt $t0, 16, FIM_EXECUCAO
        j LOOP_FIM
    FIM_EXECUCAO:
        # Aqui você pode usar os valores de t0 (alunos com 5 acertos), t1 (alunos com 1 a 4 acertos) e t2 (alunos que erraram tudo) conforme necessário.
        li $v0, 10
        syscall
