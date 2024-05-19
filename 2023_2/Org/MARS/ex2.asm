#NOME: GABRIEL ALESSI POSONSKI
#RA: 2259583

.data
	questao:
		.align 2
		.word 1,2,1,3,4, 2,2,4,4,3, 3,4,2,4,1 ,1,1,1,1,1
	gabarito:
		.align 2
		.word 2,1,1,3,4
	resultado:
		.align 2
		.space 16
.text
	#afim de utilizar somente os registradores 't', acabei armazenando valores temporários nos registradores das respostas antes de finalizar o programa
	move $t0, $zero
	move $t1, $zero
	move $t2, $zero
	move $t3, $zero
	move $t4, $zero
	move $t5, $zero
	move $t6, $zero
	move $t7, $zero
	#travessia normal nos 2 vetores
	LOOP_ALUNO:
		beq $t0, 4, FIM
		move $t1, $zero
		move $t7, $zero
		move $t4, $zero
	LOOP_CORRECAO:
		beq $t1, 5, PROXIMO_ALUNO			
		lw $t5, questao($t3)
		lw $t6, gabarito($t4)
		bne $t5, $t6, NPONTUAR		#compara a resposta com o gabarito, caso incorreto, não pontua
		addi $t7, $t7, 1
		NPONTUAR:
			addi $t3, $t3, 4
			addi $t4, $t4, 4
			addi $t1, $t1, 1
		j LOOP_CORRECAO
	PROXIMO_ALUNO:
		sw $t7, resultado($t2)		#armazena o resultado(nota) no vetor resultado
		addi $t2, $t2, 4
		addi $t0, $t0, 1
		j LOOP_ALUNO
	FIM:
		move $t0, $zero
		move $t1, $zero
		move $t2, $zero
		move $t3, $zero
		move $t4, $zero
		LOOP_FIM:
			lw $t3, resultado($t4)
			bne $t3, 5, ELSE1	#if else if para definir os valores finais de t0,t1 e t2
			addi $t0, $t0, 1
			j FIM_ELSE2
			ELSE1:
			beqz $t3, ELSE2
			addi $t1, $t1, 1
			j FIM_ELSE2
			ELSE2:
			addi $t2, $t2, 1
			FIM_ELSE2:
			addi $t4, $t4, 4
			blt  $t4, 16, LOOP_FIM			
		li $v0, 10
		syscall
	
