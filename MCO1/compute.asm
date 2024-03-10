%include "io64.inc"
section .data
inp dq 0
flag db 0 ;if sad num
res dq 0 ;result of squaring and adding
ite db 1 ;count iterations

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    PRINT_STRING "Input num: "
    GET_DEC 8, inp
    
split_num:
    MOV RAX, [inp]
    CMP RAX, 0
    JE exit
    
    MOV RCX, 10
    MOV RDX, 0
    DIV RCX
    ;PRINT_DEC 8, RAX;reduced num
    ;NEWLINE
    ;PRINT_DEC 8, RDX;modulo
    MOV [inp], RAX
;divide input by 10 until 0

square_num:
    MOV RAX, RDX
    MUL RDX
    ADD [res], RAX
    JMP split_num
    
result:
    PRINT_DEC 8, [res]
    
    xor rax, rax
    ret