%include "io64.inc"
section .data
inp dq 0
res dq 0
section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ;accommodate largest 64 bit integer
    ;write your code here
    
start_inp:
    MOV RAX, 0x1111
    PRINT_STRING "Input number: "
    ;change to get string convert to int
    GET_DEC 8, RAX
    NEWLINE
    ;infinite loop
    CMP RAX, 1
    JB err_msg
    JNB proc_inp
    
proc_inp:
    MOV [inp], RAX
    PRINT_HEX 8,[inp]

;err mess
err_msg:
    PRINT_STRING "Invalid Input."
    NEWLINE
    JMP start_inp
    
    ;enter loop
    
    ;is single digit
    ;single digit square
    ;loop to start
    
    ;is not single digit
    ;enter loop
    ;separate digits
    ;square each digit
    ;add each square
    ;is 1 - loop if no, exit if yes
    
    MOV RAX, [inp]
    MUL RAX
    
exit:
    xor rax, rax
    ret