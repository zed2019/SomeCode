#include <stdio.h>
#include <stdlib.h>
#include "ringbuffer.h"


ringBuffer_t buffer = {0,0,{0}};

int main()
{
    int i = 0; 
    int Writebuf1[8]={1,2,3,4,5,6,7,8};
    int Writebuf2[8]={9,10,11,12,13,14,15,16};
    int Writebuf3[8]={17,18,19,20,21,22,23,24};
    int Readbuf1[8]={0};
    int Readbuf2[8]={0};
    int Readbuf3[8]={0};
    int fd = 0;

    RingBuf_Write(Writebuf1);
    RingBuf_Write(Writebuf2);
    RingBuf_Write(Writebuf3);

    // fd=RingBuf_Read(Readbuf1);   
    // printf("Readbuf1  fd is %d\n",fd);
    // fd=RingBuf_Read(Readbuf2);   
    // printf("Readbuf2  fd is %d\n",fd);
    // fd=RingBuf_Read(Readbuf3);   
    // printf("Readbuf3  fd is %d\n",fd);
    // printf("----------------------\n");
    // printf("Readbuf1   is %s\n",Readbuf1);
    // printf("Readbuf2   is %s\n",Readbuf2);
    // printf("Readbuf3   is %s\n",Readbuf3);
    return 0;
}