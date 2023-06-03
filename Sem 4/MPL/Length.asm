%macro print 2                    ;macro declaration with 4 parameter
mov rax,1			  ;1st parameter has been moved to rax
mov rdi,1                         ;2nd parameter has been moved to rdi
mov rsi,%1                        ;3rd parameter has been moved to rsi
mov rdx,%2                        ;4th parameter has been moved to rdx
syscall                           ;call the kernal
%endmacro                         ;endmacro

%macro read 2                     
mov rax,0
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro


section .data                                                        ;data begins here
m db 10,"APL to print the entered string and its length",10
l equ $-m
m1 db 10d,"Enter a string: "                                         ;m1 variable initialised
l1 equ $-m1                                                          ;l1 stores length of string m1
m2 db 10d,"Entered a string: "                                       ;m2 variable initialised
l2 equ $-m2                                                          ;l2 stores length of string m2
m3 db 10d,13d,"Length: "                                             ;m3 variable initialised
l3 equ $-m3                                                          ;l3 stores length of string m3

section .bss                                                         ;.bss begins here
buffer resb 50                                                       ;buffer array of size 50
size equ $-buffer                                                    ;size variable to have input
count resb 1                                                         ;to store size of buffer
dispnum resb 16                                                      ;to display 16 digit length

section .text                                                        ;.text begins here
global _start                                                        ;moving to _start lable
_start:                                                              ;_start label

print m,l
print m1,l1                                                          ;macro call to display m1
read buffer,size                                                     ;macro call to input m1

mov [count],rax                                                      ;length of buffer gets store in count
print m2,l2                                                          ;macro call to display m2
print buffer,[count]                                                 ;macro call to display m2


call display                                                      
Exit:
	mov rax,60                                                   ;sys_exit function
	mov rbx,0                                                    ;sucessful termination
	syscall                                                      ;call the kernel
	
display:
mov rsi,dispnum+15                                                   ;rsi points to 16th location of dispnum
mov rax,[count]                                                      ;rax now stores value of count
mov rcx,16                                                           ;rcx get initiaised with 16
dec rax                                                              ;decrement the velue of rax

UP1:                                                                 ;UP1 label
mov rdx,0                                                            ;rdx gets initialised with 0
mov rbx,10                                                           ;rbx gets initialised with 10
div rbx                                                              ;divide the content of rax by rbx
add dl,30h                                                           ;add 30 to remainder
mov [rsi],dl                                                         ;dl content get copied to rsi
dec rsi                                                              ;decrement rsi
loop UP1                                                             ;jump to UP1 till rcx become 0


print m3,l3                                                          ;macro call to display
print dispnum+14,02                                                  ;macro call to displat dispnum
ret
