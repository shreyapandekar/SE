;write x86/64 bit APL to accept 64 bits hexadecimal number from user and display the accepted the number

%macro display 2
mov rax ,01
mov rdi ,01
mov rsi ,%1
mov rdx ,%2
syscall
%endmacro

section .data
m1 db "Please enter 5 numbers of 64 bits(64 digits)"
l1 equ $-m1

m2 db"Enter Number are:-",10
l2 equ $-m2

count db 05

section .bss
array resb 100

section .text
global _start
_start:

;Logic to accept numbers
mov rbx,00
display m1,l1

up:
mov rax,00
mov rdi,00
mov rsi,array
add rsi,rbx
mov rdx,17
syscall

add rbx ,17
dec byte[count]
jnz up

display m2,l2
mov byte[count],05
mov rbx,00

up1:
mov rax,01
mov rdi,01
mov rsi,array
add rsi,rbx
mov rdx,17
syscall

add rbx,17
dec byte[count]
jnz up1

exit:
mov rax,60
mov rdi,00
syscall
