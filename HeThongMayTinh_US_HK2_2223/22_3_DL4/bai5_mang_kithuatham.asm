.data

	Menu: .asciiz "=========Menu bai5==========\nNhap phim theo cac yeu cau sau: \n1.Nhap mang 1 chieu n phan tu so nguyen.\n2.Xuat mang.\n3.Liet ke cac so nguyen to.\n4.Gia tri lon nhat trong mang.\n5.Tinh trung binh mang.\n0.Thoat\n"
	tb1: .asciiz "Nhap n: "
	tb2: .asciiz "a["
	tb3: .asciiz "]: "
	tb4: .asciiz "Mang vua nhap la: "
	
	tb5: .asciiz "\nChon cau: "
	tbNhapSai: .asciiz "\nNhap sai, nhap lai."
	tbNhapMang: .asciiz "\nNhap mang. \n"
	tbXuatMang: .asciiz "\nXuatMang. \n"
	tbNguyenTo: .asciiz "\nCac so nguyen to. \n"
	tbTimMax: .asciiz "\nMax in array. \n"
	tbTimTrungBinh: .asciiz "\nAVG in array. \n"
	
	
	n: .word 0
	arr: .space 100
.text
main:

	#In menu
	li $v0, 4
	la $a0, Menu
	syscall
	
	li $a1,0
	
Menu.Lap:
	li $v0, 4
	la $a0, tb5
	syscall
	
	li $v0, 5
	syscall
	
	move $s0, $v0
	
	li $t0, 0
    beq $s0,$t0, Case0

    li $t0, 1
    beq $s0,$t0, Case1

    li $t0, 2
    beq $s0,$t0, Case2

    li $t0, 3
    beq $s0,$t0, Case3

    li $t0, 4
    beq $s0,$t0, Case4

    li $t0, 5
    beq $s0,$t0, Case5
	
	j OutRange
	
	Case0:
		j Fin
	Case1:
		li $v0, 4
		la $a0, tbNhapMang
		syscall
		jal _Cau1_NhapMang
		j Menu.Lap
	Case2:
		li $v0, 4
		la $a0, tbXuatMang
		syscall
		jal _Cau2_XuatMang
		j Menu.Lap
	Case3:
		li $v0, 4
		la $a0, tbNguyenTo
		syscall
		jal _Cau3_Cacsonguyento
		j Menu.Lap
	Case4:
		li $v0, 4
		la $a0, tbTimMax
		syscall
		jal _Cau4_TimMax
		move $a0, $v0
		li $v0, 1
		syscall
		j Menu.Lap
	Case5:
		li $v0, 4
		la $a0, tbTimTrungBinh
		syscall
		jal _Cau5_TinhTrungBinhMang
		move $a0, $v0
		li $v0, 1
		syscall
		j Menu.Lap
	OutRange:
		li $v0, 4
		la $a0, tbNhapSai
		syscall
		j Menu.Lap
		
	
	
	j Fin
	
# ==============Start Cau 1==============
	
_Cau1_NhapMang:
	#Truyen tham so
	la $a0, arr
	la $a1,n
	#khai bao stack
	addi $sp,$sp,-16
	#backup thanh ghi
	sw $ra,($sp)
	sw $s0,4($sp)
	sw $s1,8($sp)
	sw $t0,12($sp)
#Than thu tuc:
	#Lay dia chi mang
	move $s0,$a0
	#xuat tb1
	li $v0,4
	la $a0,tb1
	syscall
	
	#Nhap so nguyen 
	li $v0,5
	syscall

	#Luu vao n
	sw $v0,($a1)
	
	#Khoi tao vong lap
	lw $s1,($a1) # s1 = n
	li $t0,0 # i = 0
NhapMang.Lap:
	#xuat tb2
	li $v0,4
	la $a0,tb2
	syscall

	#xuat i
	li $v0,1
	move $a0,$t0
	syscall

	#Xuat tb3
	li $v0,4
	la $a0,tb3
	syscall
	
	#nhap so nguyen 
	li $v0,5
	syscall

	#Luu vao a[i]
	sw $v0,($s0)

	#Tang dia chi mang
	addi $s0,$s0,4
	#Tang i
	addi $t0,$t0,1
	#Kiem tra i < n
	blt $t0,$s1,NhapMang.Lap

#Cuoi thu tuc
	#Restore thanh ghi
	lw $ra,($sp)
	lw $s0,4($sp)
	lw $s1,8($sp)
	lw $t0,12($sp)

	#xoa stack
	addi $sp,$sp,16
	#Tra ve
	jr $ra

#======End Cau 1============


#=============Start cau 2===============
_Cau2_XuatMang:
	beq $a1,0,Fin
	#Truyen tham so
	la $a0, arr
	lw $a1,n
	#Khai bao stack
	addi $sp,$sp,-12
	sw $ra,($sp)
	sw $s0,4($sp)
	sw $t0,8($sp)

	#Than thu tuc
	#khoi tao vong lap
	move $s0,$a0 # s0 = arr
	li $t0,0 # i = 0
XuatMang.Lap:
	#xuat a[i]
	li $v0,1
	lw $a0,($s0)
	syscall

	#xuat khoang trang
	li $v0,11
	li $a0,' '
	syscall

	#Tang dia chi mang
	addi $s0,$s0,4
	#Tang i
	addi $t0,$t0,1
	#Kiem tra i < n
	blt $t0,$a1,XuatMang.Lap

#Cuoi thu tuc	
	#restore thanh ghi
	lw $ra,($sp)
	lw $s0,4($sp)
	lw $t0,8($sp)
	#xoa stack
	addi $sp,$sp,12
	#tra ve
	jr $ra
	
#=============End Cau 2=================

#=============Start cau 3==============
_Cau3_Cacsonguyento:
	beq $a1,0,Fin
	#Truyen tham so
	la $a0, arr
	lw $a1,n
	#Khai bao stack
	addi $sp,$sp,-12
	sw $ra,($sp)
	sw $s0,4($sp)
	sw $t0,8($sp)

	#Than thu tuc
	#khoi tao vong lap
	move $s0,$a0 # s0 = arr
	li $t0,0 # i = 0
XuatMangNguyenTo.Lap:
	lw $a2, ($s0)
	jal _Cau3_LaNguyenTo
	beq $v0, 1, Xuat
		j ChungNguyenTo
	Xuat:
	#xuat a[i]
	li $v0,1
	lw $a0,($s0)
	syscall

	#xuat khoang trang
	li $v0,11
	li $a0,' '
	syscall
	
	j ChungNguyenTo
	
	ChungNguyenTo:

	#Tang dia chi mang
	addi $s0,$s0,4
	#Tang i
	addi $t0,$t0,1
	#Kiem tra i < n
	blt $t0,$a1,XuatMangNguyenTo.Lap

#Cuoi thu tuc	
	#restore thanh ghi
	lw $ra,($sp)
	lw $s0,4($sp)
	lw $t0,8($sp)
	#xoa stack
	addi $sp,$sp,12
	#tra ve
	jr $ra

_Cau3_LaNguyenTo:
	#Khai bao stack
	addi $sp, $sp, -16
	#backupthanhghi
	sw $ra, ($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	sw $t1, 12($sp)
	
	ble $a2,1,_Cau3_Fin_KoLaNguyenTo
	
	move $s0, $a2
	li $s1, 0 #bien dem
	li $t1, 1 #bien chay
	
	_NguyenTo.Loop:
		div $s0, $t1
		mfhi $t2
	
		beq $t2, 0, TrueCase
			j ChungLaNguyenTo
			
		TrueCase:
			addi $s1, $s1, 1
		
		ChungLaNguyenTo:
		addi $t1, $t1, 1
	
		sle $t2, $t1, $s0		
		
		beq $t2,1, _NguyenTo.Loop
		
		beq $s1, 2, _Cau3_Fin_LaNguyenTo
		j _Cau3_Fin_KoLaNguyenTo
	
	_Cau3_Fin_LaNguyenTo:
		li $v0, 1
		#restore thanh ghi
		lw $ra, ($sp)
		lw $s0, 4($sp)
		lw $s1, 8($sp)
		lw $t1, 12($sp)
		#Back stack
		addi $sp, $sp, 16
		#return
		jr $ra
	_Cau3_Fin_KoLaNguyenTo:
		li $v0, 0
		#restore thanh ghi
		lw $ra, ($sp)
		lw $s0, 4($sp)
		lw $s1, 8($sp)
		lw $t1, 12($sp)
		
		#Back stack
		addi $sp, $sp, 16
		#return
		jr $ra
#=============End cau 3================
	
#============Start cau 4============
_Cau4_TimMax:
	beq $a1,0,Fin
	#Truyen tham so
	la $a0, arr
	lw $a1,n
	#Khai bao stack
	addi $sp,$sp,-20
	sw $ra,($sp)
	sw $s0,4($sp)
	sw $t0,8($sp)#i
	sw $t1, 12($sp)#bien tam
	sw $s1, 16($sp)#bien max

	#Than thu tuc
	#khoi tao vong lap
	move $s0,$a0 # s0 = arr
	li $t0,0 # i = 0
	lw $s1,($s0)
TimMax.Lap:
	#Lay gia tri a[i]
	lw $t1,($s0)
	
	bgt $t1, $s1,ChangeMax
		j Chung_TimMax
	ChangeMax:
		move $s1, $t1
	Chung_TimMax:
	#Tang dia chi mang
	addi $s0,$s0,4
	#Tang i
	addi $t0,$t0,1
	#Kiem tra i < n
	blt $t0,$a1,TimMax.Lap

#Cuoi thu tuc	
	move $v0, $s1
	#restore thanh ghi
	lw $ra,($sp)
	lw $s0,4($sp)
	lw $t0,8($sp)
	lw $t1, 12($sp)#bien tam
	lw $s1, 16($sp)#bien max
	#xoa stack
	addi $sp,$sp,20
	#tra ve
	jr $ra

#=============End Cau 4=============

#============Start cau 5============
_Cau5_TinhTrungBinhMang:
	beq $a1,0,Fin
	#Truyen tham so
	la $a0, arr
	lw $a1,n
	#Khai bao stack
	addi $sp,$sp,-20
	sw $ra,($sp)
	sw $s0,4($sp)
	sw $t0,8($sp)#i
	sw $t1, 12($sp)#bien tam
	sw $s1, 16($sp)#bien max

	#Than thu tuc
	#khoi tao vong lap
	move $s0,$a0 # s0 = arr
	li $t0,0 # i = 0
	li $s1,0
TrungBinhMang.Lap:
	#Lay gia tri a[i]
	lw $t1,($s0)
	
	add $s1, $s1, $t1
	
	#Tang dia chi mang
	addi $s0,$s0,4
	#Tang i
	addi $t0,$t0,1
	#Kiem tra i < n
	blt $t0,$a1,TrungBinhMang.Lap

#Cuoi thu tuc	
	div $s1,$a1
	mflo $s1
	move $v0, $s1
	#restore thanh ghi
	lw $ra,($sp)
	lw $s0,4($sp)
	lw $t0,8($sp)
	lw $t1, 12($sp)#bien tam
	lw $s1, 16($sp)#bien max
	#xoa stack
	addi $sp,$sp,20
	#tra ve
	jr $ra

#=============End Cau 5=============

Fin: 
	li $v0, 10
	syscall