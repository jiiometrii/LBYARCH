; Bernardo, Xian Ira O. | Manlangit Aila Janelle C. | S14

%include "io64.inc"

section .bss
inp resb 21

section .data
num dq 0
res dq 0 ;result of squaring and adding

section .text
global main

main:
    mov rbp, rsp; for correct debugging 
    mov rcx, 0
    mov [inp], rcx
    xor rcx, rcx

ask_input:
    xor RAX, RAX
    xor RBX, RBX
    MOV RDI, inp ; Clear the input buffer
    MOV RCX, 21
    MOV AL, 0
    REP STOSB
    
    mov [num], rbx ; Reset num variable
    mov [res], rbx ; Reset res variable

    PRINT_STRING "Input number: "
    GET_STRING inp, 21
    MOV RSI, inp
    
check_inp:
    LODSB ;loads to RAX
    CMP RAX, 0
    JE input_valid
    CMP RAX, 10
    JE input_valid
    CMP RAX, '0'
    JB err_msg
    CMP RAX, '9'
    JA err_msg
    SUB RAX, '0'
    MOV RDX, 1844674407370955161
    CMP RBX, RDX
    JA err_msg
    JNE normal_process
    CMP RAX, 5
    JA err_msg

normal_process:
    IMUL RBX, 10
    JC err_msg
    ADD RBX, RAX
    JC err_msg
    jmp check_inp

input_valid:
    mov [num], rbx ; store the input number
    xor rax, rax
    jmp print_ite ; jump to computation

; computation starts here
MOV RCX, 1

print_ite:
    CMP RCX, 1
    JA split_num
    PRINT_STRING "Iterations: "
    PRINT_DEC 8, [num]

split_num:
    MOV RAX, [num]
    CMP RAX, 0
    JE print_result
    
    MOV RDI, 10
    MOV RDX, 0
    DIV RDI
    MOV [num], RAX

square_num:
    MOV RAX, RDX
    MUL RDX
    ADD [res], RAX
    JMP split_num
    
print_result:
    PRINT_STRING ", "
    PRINT_DEC 8, [res]
    MOV RSI, [res]
    CMP RSI, 1
    JE happy_num
    INC RCX
    CMP RCX, 18
    JA sad_num
    MOV RDI, [res]
    MOV [num], RDI
    MOV RDI, 0
    MOV [res], RDI
    JMP split_num

happy_num:
    NEWLINE
    PRINT_STRING "Sad Number: No"
    NEWLINE
    JMP ask_again

sad_num:
    NEWLINE
    PRINT_STRING "Sad Number: Yes"
    NEWLINE
    JMP ask_again

ask_again:
    NEWLINE
    PRINT_STRING "Input another number? (Y/N): "
    GET_STRING inp, 21
    NEWLINE
    MOV RSI, inp
    LODSB
    CMP RAX, 'Y'
    JE ask_input
    CMP RAX, 'y'
    JE ask_input
    CMP RAX, 'N'
    JE exit_program
    CMP RAX, 'n'
    JE exit_program
    JMP ask_again

err_msg:
    PRINT_STRING "Invalid Input."
    NEWLINE
    JMP ask_again

exit_program:
    xor rax, rax
    ret
