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
    ;load character
    LODSB ;loads to RAX
    ;check done
    CMP RAX, 0
    JE done
    ;check for newline
    CMP RAX, 10
    JE done
    ;check if less than '0'
    CMP RAX, '0'
    JB err_msg ;jump if below
    CMP RAX, '9'
    JA err_msg ;jump if above
    SUB RAX, '0'
    ;check if current number is greater than 1844674407370955161
    MOV RDX, 1844674407370955161
    CMP RBX, RDX
    JA err_msg ;jump if above
    JNE normal_process
    ;check if next digit is greater than 5
    CMP RAX, 5
    JA err_msg
    
normal_process:
    ;multiply RBX by 10
    MOV RCX, RBX
    IMUL RCX, 10
    JC err_msg ; jump if carry (overflow)
    MOV RBX, RCX
    ;add RAX to RBX
    ADD RBX, RAX
    JC err_msg ; jump if carry (overflow)
    jmp check_inp

done:
    mov [inp], rbx ; store the input number
    xor rax, rax
    JMP ask_again
    
ask_again:
    PRINT_STRING "Input another number? (Y/N): "
    GET_STRING inp, 21
    MOV RSI, inp
    LODSB ;loads to RAX
    CMP RAX, 'Y'
    JE ask_input
    CMP RAX, 'y'
    JE ask_input
    CMP RAX, 'N'
    JE end_program
    CMP RAX, 'n'
    JE end_program
    JMP ask_again

end_program:
    xor rax, rax
    ret

err_msg:
    PRINT_STRING "Invalid Input."
    NEWLINE
    JMP ask_input