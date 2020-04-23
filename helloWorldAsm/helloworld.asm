[BITS 32]

section .data
msg db "Hello World!", 0x0a, 0x00 ; defines some data in the data segment
msglen equ $-msg ; calculates the length of the data

section .text
global _start

_start:
    ; write syscall
    ;   eax is the syscall number
    ;   ebx is the fd descriptor to write to
    ;   ecx is a pointer to the buffer that hold the data to be written
    ;   edx is the number of bytes to write
    mov eax, 4      ; write is syscall 4
    mov ebx, 1      ; 1 is the file descriptor number for standard output
    mov ecx, msg    ; ecx point to our msg
    mov edx, msglen ; edx is the length of the msg
    int 0x80        ; interupt 0x80 is the instruction to ask the kernel to make the syscall

    ; exit syscall
    ; eax is the syscall number
    ; ebx is the error code
    mov eax, 1  ; exit is syscall 1
    mov ebx, 0  ; 0 for no eror
    int 0x80    ; ask kernel to make syscall to exit program

