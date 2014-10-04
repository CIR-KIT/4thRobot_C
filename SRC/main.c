#include "main.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  /* int i; */
  /* char msgFromGim30[GIM30_DATASIZE]; */

  /* SetGim30(); */

  /* puts("Start Gim30"); */
  /* SendCom2Gim30("START\r\n"); */

  /* for(i=0; i<400; i++){ */
  /*   GetComFromGim30(msgFromGim30); */
  /*   printf("%s\n", msgFromGim30); */
  /* } */

  /* puts("Stop Gim30"); */
  /* SendCom2Gim30("STOP\r\n"); */

  /* CloseGim30(); */

  MVcmd JScmd;

  //Joy Stick set up
  if(SetJoystick()){
    puts("JoyStick Connect is Failed....");
    exit(1);
  }
    
  //Construct JScmd===============
  JScmd.gear = FORWARD;
  JScmd.speed = 0;
  JScmd.dir =  KEEP;
  JScmd.deg = 0;
  //==============================

  //Arduino Setup
  if(!SetArduino(AR_SEND_ID)) 
    puts("Arduino SEND_ID setup.....OK");
  else{
    puts("SEND Arduino Connect is Failed....");
    exit(1);
  }

  //Main loop(RC Mode)===========================
  while(1){
    GetJSinfo2MVcmd(&JScmd);
    Move(JScmd.gear, JScmd.speed, JScmd.dir);
  }
  //=============================================

  //Release Jscmd
  CloseJoystick();
  //Close Arduino connection
  CloseArduino(AR_SEND_ID);    
}
