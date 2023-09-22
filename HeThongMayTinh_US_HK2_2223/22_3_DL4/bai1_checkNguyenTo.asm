.data
	msgChuongTrinh: .asciiz "====Chuong trinh kiem tra so nguyen to.===== \n"
	msgNhap: .asciiz "Nhap so nguyen n de kiem tra: \n"
	msglaNT: .asciiz "\nn la so nguyen to."
	msgkolaNT: .asciiz "\nn khong la so nguyen to."
.text
.globl main

main:
	#In ra thong bao chuong trinh
	li $v0, 4
	la $a0, msgChuongTrinh
	syscall
	
	#Thong bao nhap va lay
	li $v0, 4
	la $a0, msgNhap
	syscall
	
	#Nhap
	li $v0, 5
	syscall
	
	#Gan vao $s0
	move $s0, $v0
	
	#TH1: <=1 -> khong phai so nguyen to
	#TH2: >1 dung bien dem chay	
	
	#TH1
	sle $t0, $s0, 1
	beq $t0, 1, _KoLaNguyenTo

	#TH2
	li $s1, 0 #bien dem
	li $t1, 1 #bien chay
	
	_NguyenTo.Loop:
		div $s0, $t1
		mfhi $t2
	
		beq $t2, 0, TrueCase
			j Chung
			
		TrueCase:
			addi $s1, $s1, 1
		
		Chung:
		addi $t1, $t1, 1
	
		sle $t2, $t1, $s0		
		
		beq $t2,1 _NguyenTo.Loop
	
	beq $s1, 2, _LaNguyenTo
		j _KoLaNguyenTo
	
	_LaNguyenTo:
		li $v0, 4
		la $a0, msglaNT
		syscall
	
		j Fin
	
	_KoLaNguyenTo:
		li $v0, 4
		la $a0, msgkolaNT
		syscall
	
		j Fin

Fin:
	li $v0, 10
	syscall 
