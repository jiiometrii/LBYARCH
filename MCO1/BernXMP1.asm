%include "io64.inc"

section .data
buffer dq 0 ; buffer to store the input string
bufferLen equ $-buffer
inp dq 0

section .text
global main
main:
    mov rbp, rsp; for correct debugging
    ;accommodate largest 64 bit integer
    ;write your code here
    
start_inp:
    PRINT_STRING "Input number: "
    GET_STRING [buffer], 8 ; read the input as a string
    NEWLINE

    ; validate the input
    mov rsi, buffer
    
validate_input:
    lodsb ; load the next character from the string
    test al, al ; check if we reached the end of the string
    jz input_valid ; if we did, the input is valid
    sub al, '0' ; convert the character to a number
    jb err_msg ; if it's less than 0, it's not a valid number
    cmp al, 9 ; check if the number is greater than 9
    ja err_msg ; if it is, it's not a valid number
    jmp validate_input ; check the next character

input_valid:
    ; convert the string to a number
    mov rsi, buffer
    xor rax, rax
    
convert_string:
    lodsb ; load the next character from the string
    test al, al ; check if we reached the end of the string
    jz proc_inp ; if we did, we're done
    sub al, '0' ; convert the character to a number
    imul rax, rax, 10 ; multiply the current number by 10
    add rax, rax, al ; add the new digit
    jmp convert_string ; process the next character
    
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
    MOV RBX, RAX
    MUL RBX
    
exit:
    xor rax, rax
    ret