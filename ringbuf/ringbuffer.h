#ifndef _RINGBUFFER_H
#define _RINGBUFFER_H


#define BUFFER_MAX 6400//定义缓冲区大小

typedef struct{
	unsigned int headPosition;//缓冲区头部位置
	unsigned int tailPosition;
	int  ringBuf[BUFFER_MAX];//缓冲区数组
	
}ringBuffer_t;

void RingBuf_Write(int* data);//向缓冲区写入一个字节
unsigned char RingBuf_Read(int* pData);//读取缓冲区一个字节的数据

#endif

