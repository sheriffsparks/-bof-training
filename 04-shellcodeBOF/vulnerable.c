#include <stdio.h>
#include <unistd.h>

void vuln() {

    char buf[32];
    printf("What's your name? ");
    gets(buf);
    printf("Hi, %s!\n", buf);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    vuln();
    return 0;
}
