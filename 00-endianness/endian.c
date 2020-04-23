#include <stdio.h>

int main(int argc, char * argv){

  int a = 0xdeadbeef;

  //treat the integer like a array of one-byte values
  char * p = (char *) &a;

  int i;
  for(i=0;i<4;i++){
    printf("p[%d] = 0x%hhx\n",i,p[i]);
  }

  return 0;

}
