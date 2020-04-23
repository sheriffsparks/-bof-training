#include <stdio.h>

void vuln() {
    char buf[32];
    printf("What's your name? ");
    gets(buf);
    printf("Hi, %s!\n", buf);
}

void callMe()
{
    printf("you win! congratulations!!\n");
}

int main() {
    vuln();
    return 0;
}
