.data
	msgChuongTrinh: .asciiz "====Chuong trinh kiem tra so doi xung.==== \n"
	msgNhap: .asciiz "Nhap so nguyen n de kiem tra: \n"
	msgLaSoDoiXung: .asciiz "\nn la so doi xung."
	msgKoLaSoDoiXung: .asciiz "\nn khong la so doi xung."
.text

#Dinh nghia so doi xung
#>=0 <10 va cac so doc tu trai qua phai hay phai qua trai deu bang nhau
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
	
	#TH1: <0 -> khong phai so nguyen to
	#TH2: >9 dung bien dem chay (0->9 la so doi xung)
	
	#TH1 <0
	sle $t0, $s0, -1
	beq $t0, 1, _KoLaSoDoiXung
	
	sle $t0, $s0, 9
	beq $t0, 1, _LaSoDoiXung
	
	#TH2 >9
	#Tao them so s1 = s0, s2 se la so nghich dao cua s0
	move $s1, $s0
	li $s2, 0
	li $t5, 10
	_SoDoiXung.Loop:
		div $s1, $t5
		mfhi $t1 #phan du
		
		mult $s2, $t5
		mflo $s2
		
		add $s2, $s2, $t1
		
		div $s1, $t5
		mflo $s1
		
		sle $t2, $s1, 0 
		beq $t2, 1, _Xuly
			j _SoDoiXung.Loop	
			
	_Xuly:
		beq $s0, $s2, _LaSoDoiXung
			j _KoLaSoDoiXung
	_LaSoDoiXung:
		li $v0, 4
		la $a0, msgLaSoDoiXung
		syscall
	
		j Fin		
	
	_KoLaSoDoiXung:
		li $v0, 4
		la $a0, msgKoLaSoDoiXung
		syscall
	
		j Fin	
	
	Fin: 
		li $v0, 10
		syscall
	
