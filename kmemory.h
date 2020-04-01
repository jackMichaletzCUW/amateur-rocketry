#ifndef KMEMORY_H
#define KMEMORY_H

unsigned int memoryFree(char* address, unsigned int size);
char* memoryAllocate(int numByte);
void setBitToOne (int bitPos,int count);
void memoryInitialize();

#endif
