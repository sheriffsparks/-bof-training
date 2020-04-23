# Requirements
- add 32 bit if you are running 64
`sudo dpkg --add-architecture i386`
`sudo apt update`
- add gcc multilib if you are running 64 bit
`sudo apt install gcc-multilib`

# Running
- Turn off ASLR:
* safer option is to only do it for the shell with:
`exec setarch linux32 -R /bin/bash`
* less safe is to turn it off for the os:
`echo 0 | sudo tee /proc/sys/kernel/randomize_va_space`

- programs can be compiled with
`make`
- This runs the commands specified in the make file
