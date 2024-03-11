%include "io64.inc"
section .data
inp dq 0
res dq 0 ;result of squaring and adding

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    PRINT_STRING "Input num: "
    GET_DEC 8, inp
    MOV RCX, 1 ; count iterations
    ;PRINT_DEC 1, RCX

print_ite:
    CMP RCX, 1
    JA split_num
    NEWLINE
    PRINT_STRING "Iterations: "
    PRINT_DEC 8, inp

split_num:
    MOV RAX, [inp]
    CMP RAX, 0
    JE print_result
    
    MOV RDI, 10
    MOV RDX, 0
    DIV RDI
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
    
print_result:
    PRINT_STRING ", "
    PRINT_DEC 8, [res]
    MOV RSI, [res]
    CMP RSI, 1
    JE happy_num
    INC RCX
    CMP RCX, 19
    JA sad_num
    MOV RDI, [res]
    MOV [inp], RDI
    MOV RDI, 0
    MOV [res], RDI
    JMP split_num

happy_num:
    NEWLINE
    PRINT_STRING "Sad Number: No"
    JMP exit

sad_num:
    NEWLINE
    PRINT_STRING "Sad Number: Yes"
    
exit:
    NEWLINE
    PRINT_STRING "End of Program"
    xor rax, rax
    ret