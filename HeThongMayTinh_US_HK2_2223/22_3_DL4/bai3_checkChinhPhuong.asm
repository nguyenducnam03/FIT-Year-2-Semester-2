.data
	msgChuongTrinh: .asciiz "====Chuong trinh kiem tra so chinh phuong.===== \n"
	msgNhap: .asciiz "Nhap so nguyen n de kiem tra: \n"
	msgLaSoChinhPhuong: .asciiz "\nn la so chinh phuong."
	msgKoLaSoChinhPhuong: .asciiz "\nn khong la so chinh phuong."
.text

#Dinh nghia so chinh phuong
#>=0
#co mot so binh phuong bang no
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
	
	#TH1: <0 -> khong phai so chinh phuong
	#TH2: >1 dung bien dem chay	(0,1 la so chinh phuong)
	
	#TH1 <=0
	sle $t0, $s0, -1
	beq $t0, 1, _KoLaSoChinhPhuong
	
	##0,1 la so chinh phuong
	sle $t0, $s0, 1
	beq $t0, 1, _LaSoChinhPhuong
	
	#TH2 >=2
	li $t1, 1 #bien chay
	
	_SoChinhPhuong.Loop:
		div $s0, $t1
		mfhi $t2 #phan du
		mflo $t3 #phan nguyen
	
		#phan du = 0, #phan nguyen = t1 --> Chinh phuong
		beq $t2, 0, TrueCase
			j FalseCase
						
		TrueCase:
			beq $t3, $t1, _LaSoChinhPhuong
				j FalseCase
		
		FalseCase:
		addi $t1, $t1, 1
	
		slt $t2, $t1, $s0		
		
		beq $t2,1, _SoChinhPhuong.Loop
		
	j _KoLaSoChinhPhuong
		
	_LaSoChinhPhuong:
		li $v0, 4
		la $a0, msgLaSoChinhPhuong
		syscall
	
			j Fin		
	
	_KoLaSoChinhPhuong:
		li $v0, 4
		la $a0, msgKoLaSoChinhPhuong
		syscall
	
		j Fin	
	
Fin: 
	li $v0, 10
	syscall
	
