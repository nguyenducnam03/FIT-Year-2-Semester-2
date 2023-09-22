;Tinh tong 1 den n
%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "%d la so nguyen to.",0
    tb3 db "%d khong la so nguyen to.",0
    fmt db "%d",0
section .bss
    n resd 1
    kq resd 1
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ;write your code here
    ;xuat tb1
    push tb1
    call _printf
    add esp,4
    
    ;nhap n
    push n
    push fmt
    call _scanf
    add esp,8
    
    ;khoi tao
    mov ecx,0 ; dem = 0
    mov esi,1 ; i = 1
    
Lap:
    xor edx,edx
    mov eax,[n] ; gia tri n
    div esi
    cmp edx,0
    je KTNT.TangDem
    jmp KTNT.Tangi
    
    KTNT.TangDem:
        inc ecx
        
    KTNT.Tangi:        
        inc esi
        ;kiem tra i <= n thi Lap
        cmp esi,[n]
        jle Lap
    
    ; Kiem tra dem = 2
    
    cmp ecx,2
    je LaNguyenTo
    jmp KhongLaNguyenTo
    
LaNguyenTo:
    push dword[n]
    push tb2
    call _printf
    add esp, 8
    jmp Fin

KhongLaNguyenTo:
    push dword[n]
    push tb3
    call _printf
    add esp,8   
 
Fin:         

    call _getch
    xor eax, eax
    ret