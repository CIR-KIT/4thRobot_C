#ifndef __GIM30__
#define __GIM30__

#define GIM30_DATASIZE 8

//Prototype
int SetGim30(void);
void CloseGim30(void);
int SendCom2Gim30(const char *command);
int GetComFromGim30(char *command);

#endif
