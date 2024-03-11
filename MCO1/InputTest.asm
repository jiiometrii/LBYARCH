%include "io64.inc"

section .bss
inp resb 21

section .text
global main

main:
    mov rbp, rsp; for correct debugging 
    mov rcx, 0
    mov [inp], rcx
    xor rcx, rcx

ask_input:
    PRINT_STRING "Input number: "
    GET_STRING inp, 21
    MOV RSI, inp
    xor RAX, RAX
    xor RBX, RBX
    
check_inp:
    LODSB ;loads to RAX
    CMP RAX, 0
    JE done
    CMP RAX, 10
    JE done
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
    MOV RCX, RBX
    IMUL RCX, 10
    JC err_msg
    MOV RBX, RCX
    ADD RBX, RAX
    JC err_msg
    jmp check_inp

done:
    mov [inp], rbx
    xor rax, rax
    JMP ask_again
    
ask_again:
    PRINT_STRING "Input another number? (Y/N): "
    GET_STRING inp, 21
    MOV RSI, inp
    LODSB
    CMP RAX, 'Y'
    JE ask_input
    CMP RAX, 'y'
    JE ask_input
    CMP RAX, 'N'
    JE end_program
    CMP RAX, 'n'
    JE end_program
    JMP ask_again

err_msg:
    PRINT_STRING "Invalid Input."
    NEWLINE
    JMP ask_input
    
end_program:
    xor rax, rax
    ret