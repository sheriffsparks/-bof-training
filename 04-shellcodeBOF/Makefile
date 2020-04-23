all:
	gcc -m32 -fno-pic -zexecstack -fno-stack-protector -no-pie vulnerable.c -o vulnerable
	gcc -m32 -zexecstack runShellcode.c -o runShellcode

clean:
	rm vulnerable
