.data
	msgChuongTrinh: .asciiz "====Chuong trinh kiem tra so hoan thien==== \n"
	msgNhap: .asciiz "Nhap so nguyen n de kiem tra: \n"
	msgLaSoHoanThien: .asciiz "\nn la so hoan thien."
	msgKoLaSoHoanThien: .asciiz "\nn khong la so hoan thien."
.text

#Dinh nghia so hoan thien
#>0
#tong cac uoc tru chinh no bang chinh no
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
	
	#TH1 <=0
	sle $t0, $s0, 1
	beq $t0, 1, _KoLaSoHoanThien
	
	#TH2 >0
	li $s1, 0 #bien tong phu
	li $t1, 1 #bien chay
	
	_SoHoanThien.Loop:
		div $s0, $t1
		mfhi $t2
	
		beq $t2, 0, TrueCase
			j Chung
			
		TrueCase:
			add $s1, $s1, $t1
		
		Chung:
		addi $t1, $t1, 1
	
		slt $t2, $t1, $s0		
		
		beq $t2,1 _SoHoanThien.Loop
	
	beq $s1, $s0, _LaSoHoanThien
		j _KoLaSoHoanThien
		
_LaSoHoanThien:
		li $v0, 4
		la $a0, msgLaSoHoanThien
		syscall
	
		j Fin		
	
_KoLaSoHoanThien:
		li $v0, 4
		la $a0, msgKoLaSoHoanThien
		syscall
	
		j Fin	
	
Fin: 
	li $v0, 10
	syscall
	
