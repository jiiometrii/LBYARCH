%include "io64.inc"

section .data
inp dq 0

section .text
global main
; ask input
; get string
; get string_len
; while valid and less than string_len process input
; if not valid exit loop ask for new input
; if end of string check if greater than 18446744073709551615
; if greater than, exit
; if equal or less than, store num

main:
    mov rbp, rsp; for correct debugging 
    mov rcx, 0
    mov [inp], rcx
    xor rcx, rcx
    PRINT_STRING "Input number: "
    GET_STRING inp, 8
    PRINT_STRING [inp]
    MOV RSI, inp
    xor RAX, RAX
    xor RBX, RBX
    
check_inp:
    ;load character
    LODSB ;loads to RAX
    ;check done
    CMP RAX, 0
    JE done
    ;check if less than '0'
    CMP RAX, '0'
    JB err_msg ;jump if below
    CMP RAX, '9'
    JA err_msg ;jump if above
    SUB RAX, '0'
    CMP RAX, 18446744073709551615
    JA err_msg
    mov [inp], rax
    jmp check_inp
    ;MOV RCX, 10
    ;MUL RCX
    ;ADD RDX, RBX
;errors only checks first_char
done:
    mov [inp], rax ; store the input number
    PRINT_DEC 8, [inp]
    xor rax, rax
    ret

err_msg:
    PRINT_STRING "Invalid Input."
    NEWLINE
    JMP main