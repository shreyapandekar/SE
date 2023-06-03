section .data
	m1 db 10,"hello all",10
	l1 equ $-m1

	m2 db 10,"hello all,Im here",10
	l2 equ $-m2

	m3 db 10,"hello all",10
	l3 equ $-m3

	m4 db 10,"hello all,Good morning",10
	l4 equ $-m4

	%macro display 4
	mov rax ,%1
	mov rdi ,a%2
	mov rsi ,%3
	mov rdx ,%4
	syscall
	%endmacro

section .bss

section .txt
	global _start:
	_start:

	display 1,1,m1,11

	display 1,1,m2,12

	display 1,1,m3,13

	display 1,1,m4,14

	mov rax,60
	syscall
