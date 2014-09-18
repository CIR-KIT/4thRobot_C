#include "main.h"

#include <unistd.h>
#include <stdio.h>

int main(void)
{
  int i;
  char msgFromGim30[GIM30_DATASIZE];

  SetGim30();

  puts("Start Gim30");
  SendCom2Gim30("START\r\n");

  for(i=0; i<400; i++){
    GetComFromGim30(msgFromGim30);
    printf("%s\n", msgFromGim30);
  }

  puts("Stop Gim30");
  SendCom2Gim30("STOP\r\n");



  CloseGim30();

}
