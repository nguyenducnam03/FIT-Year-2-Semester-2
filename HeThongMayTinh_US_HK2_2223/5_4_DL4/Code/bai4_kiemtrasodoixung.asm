;Tinh tong 1 den n
%include "io.inc"
extern _getch
section .data
    tb1 db "Nhap n: ",0
    tb2 db "%d la so doi xung.",0
    tb3 db "%d khong la so doi xung.",0
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
    
    ;Truong hop so <0 khong la so doi xung
    mov eax,[n]
    cmp eax,0
    jl KhongLaSoDoiXung
    
    ;Truong hop so >=0 <=9 thi la so doi xung
    cmp eax,9
    jl LaSoDoiXung
    
    ;khoi tao
    mov ecx,[n] ; temp1 = n
    mov esi,0 ; temp2 = 0
Lap:
    mov edi, 10
    xor edx,edx
    mov eax,ecx ; gia tri n
    div edi
    
    ;temp1 = temp1/10
    mov ecx, eax
    
    ;temp2 = temp2 *10 + phandu
    mov eax, esi
    mov esi, edx
    mul edi
    add eax, esi
    mov esi, eax    
    
    cmp ecx,0
    jg Lap
    
    ; Kiem tra temp1 = n
    cmp esi,[n]
    je LaSoDoiXung
    jmp KhongLaSoDoiXung
    
LaSoDoiXung:
    push dword[n]
    push tb2
    call _printf
    add esp, 8
    jmp Fin

KhongLaSoDoiXung:
    push dword[n]
    push tb3
    call _printf
    add esp,8   
 
Fin:         

    call _getch
    xor eax, eax
    ret