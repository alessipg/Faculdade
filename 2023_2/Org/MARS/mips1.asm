.data
	a: .word 40
	b: .word 8
	result: .word
	
.text
	lw $t0, a
	lw $t1, b
	div $t0, $t1
	mfhi $t3
	mflo $t2           
	add $t4, $t2, $t3
	bgt $t4, 5, IF
	add $t5,$t2,$t3
	j EXIT
	IF:
	sub $t5,$t2,$t3
	EXIT:
	li $v0, 10
	syscall