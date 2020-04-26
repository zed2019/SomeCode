#include "ringbuffer.h"

extern ringBuffer_t buffer;

void RingBuf_Write(int* data){//向缓冲区写入一个字节
	for(int tmp=0;tmp<8;tmp++)
		buffer.ringBuf[buffer.tailPosition+tmp] = *(data+tmp);//从尾部追加
	buffer.tailPosition += 8;		
	if(++buffer.tailPosition >= BUFFER_MAX)//尾节点偏移
		buffer.tailPosition = 0;//大于数组，最大长度归零，形成环形数组
	//如果尾部节点追到头部节点，则修改头节点偏移位置丢弃早期数据
	if(buffer.tailPosition == buffer.headPosition)
		if(++buffer.headPosition >= BUFFER_MAX)
			buffer.headPosition=0;
	printf("Wbuffer.tailPosition is %d\n",buffer.tailPosition);	
	printf("Wbuffer.headPosition is %d\n",buffer.headPosition);		
}


unsigned char RingBuf_Read(int* pData){//读取缓冲区一个字节的数据
	if(buffer.headPosition == buffer.tailPosition){//头尾相接表示缓冲区数据为空
		return 0;//读取失败返回0
	}
	else{
		for(int tmp=0;tmp<8;tmp++)
			*(pData+tmp) = buffer.ringBuf[buffer.headPosition+tmp];//如果缓冲区非空则取头结点值并偏移头结点
		buffer.headPosition += 8;
		if(++buffer.headPosition>=BUFFER_MAX)
			buffer.headPosition = 0;
		return 1;//读取成功返回1
	}
	printf("Rbuffer.tailPosition is %d\n",buffer.tailPosition);	
	printf("Rbuffer.headPosition is %d\n",buffer.headPosition);	
}


