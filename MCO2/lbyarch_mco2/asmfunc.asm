section .data
ze dq 0.0 ;initialize sum
msg db "sdot: %lf", 10, 0
section .text
bits 64
default rel

global sdotfunc
extern printf

; xmm0: 1st param
; xmm1: 2nd param
; r8: 3rd param
; r9: 4th param
; xmm2: sum
sdotfunc: 
	mov rcx, r8
	movsd xmm2, qword [ze] 
L1:	vmulsd xmm3, xmm0, xmm1
	addsd xmm2, xmm3
	loop L1
	movsd [r9], xmm2
	movsd xmm0, xmm2
	
	;printing in assembly
	;sub rsp, 8*5
    ;lea rcx, [msg]
    ;movq rdx, xmm2
    ;call printf
    ;add rsp, 8*5

ret