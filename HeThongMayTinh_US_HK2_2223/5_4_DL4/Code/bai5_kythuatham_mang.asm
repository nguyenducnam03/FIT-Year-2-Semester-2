%include "io.inc"
extern _getch

section .data
    tb1 db "Nhap n: ",0
    tb2 db "a[%d]: ",0
    tb3 db "Mang vua nhap la: ",0
    tb4 db "Xuat = %d",10,0
    tb5 db "Cac so nguyen to: ",0
    tb6 db "Max cua ham nay la: %d",0
    tb7 db "Trung binh cua ham nay la: %d",0
    tbEndl db "", 0Ah,0
    fmt1 db "%d",0
    fmt2 db "%d ",0
    
section .bss
    arr resd 100
    n resd 1
    
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    ;Cau1 Nhap mang
    push n
    push arr
    call _NhapMang    
    add esp,8
    
    push tb3
    call _printf
    add esp,4
    
    push n
    push arr
    call _XuatMang    
    add esp,8
    
    ;2 Xuong hang
    push tbEndl
    call _printf
    add esp,4
    
    push tb5
    call _printf
    add esp,4
    
    ;Cau3 Liet ke cac so nguyen to
    push n
    push arr
    call _LietKeNT
    add esp,8
    
    ;Xuong hang
    push tbEndl
    call _printf
    add esp,4
    
    ; 4 In max
    push n
    push arr
    call _timMax
    add esp,8   
    
    push eax
    push tb6
    call _printf
    add esp,8
    
    ;Xuong hang
    push tbEndl
    call _printf
    add esp,4
    
    ;5 Tim trung binh
    push n
    push arr
    call _timTrungBinh
    add esp,8 
    
    push eax
    push tb7
    call _printf
    add esp,8
       
    ;return
    call _getch
    xor eax, eax
    ret
    
; Viet ham Nhap Mang==============
;dau thu tuc
global _NhapMang
_NhapMang:
    ; backup ebp
    push ebp
    mov ebp,esp
    ;khai bao stack
    sub esp,32
    ;backup thanh ghi neu can
    push esi
    push ecx
    push ebx
    ;tham so 1 : n = [ebp + 12]
    ;tham so 2: arr = [ebp + 8]
    
    ;;ebp+8
     
; than thu tuc
    ;khoi tao
    ;Cc tham so
    
    
    ;Nhap n
    ;xuat tb1
    push tb1
    call _printf
    add esp,4
    ;lea eax,n
    
    mov eax, [ebp+12]
    ;Nhap n
    push eax
    push fmt1
    call _scanf
    add esp,8
    
    ;Nhap mang
    ;Khoi tao
    mov ecx,[ebp+12]
    mov ecx, [ecx] ; ecx = n          
    mov ebx, [ebp+8] ; ebx = dia chi arr
    mov esi,0; i = 0
    
LapNhap:
    ;xuat tb2
    push ecx; backup ecx
    push esi
    push tb2
    call _printf
    add esp,8
    
    ;nhap a[i]
    push ebx
    push fmt1
    call _scanf
    add esp,8
    
    pop ecx; restore
    ;Tang chi so
    add ebx,4
    inc esi
    Loop LapNhap
                      
_NhapMang.KetThuc:
    ;cuoi thu tuc
    ;restor thanh ghi
    pop esi
    pop ecx
    pop ebx
    ;xoa stack
    add esp,32
    ;phuc hoi ebp
    pop ebp
    ret
    
;====End Nhap Mang
; Viet ham Xuat Mang==============
;dau thu tuc
global _XuatMang
_XuatMang:
    ; backup ebp
    push ebp
    mov ebp,esp
    ;khai bao stack
    sub esp,32
    ;backup thanh ghi neu can
    push esi
    push ecx
    push ebx
    ;tham so 1 : n = [ebp + 12]
    ;tham so 2: arr = [ebp + 8]
    
    ;;ebp+8
     
; than thu tuc
   ;Cc tham so
   ;khoi tao
    mov ebx,[ebp+8] ;ebx=arr
    mov ecx,[ebp+12]
    mov ecx, [ecx] ; ecx = n
    mov esi,0
      
LapXuat:    
    push ecx
    ;xuat a[i]
    push dword[ebx]
    push fmt2
    call _printf
    add esp, 8
    
        
    ;tang chi so
    add ebx,4
    pop ecx
    
    inc esi
    ;kiem tra i < n thi lap
    cmp esi,ecx
    jl LapXuat
                      
__XuatMang.KetThuc:
    ;cuoi thu tuc
    ;restor thanh ghi
    pop esi
    pop ecx
    pop ebx
    ;xoa stack
    add esp,32
    ;phuc hoi ebp
    pop ebp
    ret
    
;====End Xuat Mang

;;=====Ham Kiem tra nguyen to
;==start ham kiem tra nguyen to
global _KTNT
_KTNT:
        ; backup ebp
        push ebp
        mov ebp,esp
        ;khai bao stack
        sub esp,32
        ;backup thanh ghi neu can
        push esi
        ;tham so 1 : n = [ebp + 8]
     
; than thu tuc
        ;khoi tao
        
        mov ecx,0 ; dem = 0
        mov esi,1; i = 1
        
        mov eax,[ebp + 8]
        cmp eax, 1
        jg _KTNT.Lap
        mov eax,0
        jmp _KTNT.KetThuc
_KTNT.Lap:
        xor edx,edx
        mov eax,[ebp + 8]
        div esi
        
        cmp edx,0
        je _KTNT.TangDem
        jmp _KTNT.Tangi
_KTNT.TangDem:
        inc ecx
_KTNT.Tangi:        
        inc esi
        ;kiem tra i <= n thi Lap
        cmp esi, [ebp + 8]
        jle _KTNT.Lap
        ; Kiem tra dem = 2 return 1
        cmp ecx,2
        je _KTNT.Return1
        mov eax,0
        jmp _KTNT.KetThuc
_KTNT.Return1:
        mov eax,1
_KTNT.KetThuc:
;cuoi thu tuc
        ;restor thanh ghi
        pop esi
        ;xoa stack
        add esp,32
        ;phuc hoi ebp
        pop ebp
        ret
;;==End ham kiem tra nguyen to

;;==Ham Liet ke cac so nguyen to
;;==Start ham liet ke
global _LietKeNT
_LietKeNT:
    ; backup ebp
    push ebp
    mov ebp,esp
    ;khai bao stack
    sub esp,32
    ;backup thanh ghi neu can
    push esi
    push ecx
    push ebx
    ;tham so 1 : n = [ebp + 12]
    ;tham so 2: arr = [ebp + 8]
    
    ;;ebp+8
     
; than thu tuc
   ;Cc tham so
   ;khoi tao
    mov ebx,[ebp+8] ;ebx=arr
    mov ecx,[ebp+12]
    mov ecx, [ecx] ; ecx = n
    mov esi,0
      
LapXuatNT:    
    push ecx
        
    ;Neu la nguyen to thi xuat
    push dword[ebx]
    call _KTNT
    add esp,4
    
    cmp eax,1
    je LaNT
    jmp Chung
LaNT:
    ;xuat a[i]
    push dword[ebx]
    push fmt2
    call _printf
    add esp, 8
Chung:  
    ;tang chi so
    add ebx,4
    pop ecx
    
    inc esi
    ;kiem tra i < n thi lap
    cmp esi,ecx
    jl LapXuatNT
                      
_LietKeNT.KetThuc:
    ;cuoi thu tuc
    ;restor thanh ghi
    pop esi
    pop ecx
    pop ebx
    ;xoa stack
    add esp,32
    ;phuc hoi ebp
    pop ebp
    ret
;;==End ham liet ke nguyen to


; Viet ham tim Max==============
;dau thu tuc
global _timMax
_timMax:
    ; backup ebp
    push ebp
    mov ebp,esp
    ;khai bao stack
    sub esp,32
    ;backup thanh ghi neu can
    push esi
    ;tham so 1 : n = [ebp + 12]
    ;tham so 2: arr = [ebp + 8]
     
; than thu tuc
   ;Cc tham so
   ;khoi tao
    mov ebx,[ebp+8] ;ebx=arr
    mov ecx,[ebp+12]
    mov ecx, [ecx] ; ecx = n
    mov esi,0
    mov eax, [ebx]
      
LapMax:    
    push ecx
    
    cmp eax, [ebx]
    jl newMax
    jmp MaxChung
    
newMax:
    mov eax, [ebx]
    
MaxChung:
    ;tang chi so
    add ebx,4
    pop ecx
    
    inc esi
    ;kiem tra i < n thi lap
    cmp esi,ecx
    jl LapMax
                      
__TimMax.KetThuc:
    ;cuoi thu tuc
    ;restor thanh ghi
    pop esi
    ;xoa stack
    add esp,32
    ;phuc hoi ebp
    pop ebp
    ret
    
;====End find Max

; Viet ham tim Max==============
;dau thu tuc
global _timTrungBinh
_timTrungBinh:
    ; backup ebp
    push ebp
    mov ebp,esp
    ;khai bao stack
    sub esp,32
    ;backup thanh ghi neu can
    push esi
    ;tham so 1 : n = [ebp + 12]
    ;tham so 2: arr = [ebp + 8]
     
; than thu tuc
   ;Cc tham so
   ;khoi tao
    mov ebx,[ebp+8] ;ebx=arr
    mov ecx,[ebp+12]
    mov ecx, [ecx] ; ecx = n
    mov esi,0
    mov eax, 0
      
TrungBinhLap:    
    push ecx
    
    add eax, [ebx]
    
    ;tang chi so
    add ebx,4
    pop ecx
    
    inc esi
    ;kiem tra i < n thi lap
    cmp esi,ecx
    jl TrungBinhLap
                      
_timTrungBinh.KetThuc:
    div ecx
    ;cuoi thu tuc
    ;restor thanh ghi
    pop esi
    ;xoa stack
    add esp,32
    ;phuc hoi ebp
    pop ebp
    ret
    
;====End tim trung binh