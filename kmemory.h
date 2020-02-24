#ifndef KMEMORY_H
#define KMEMORY_H

void kmeminit();
unsigned int kfree(char* address, unsigned int size);
char* kalloc(unsigned int size);

char* yoink(int numByte);
void setBitToOne (int bitPos,int count);
void memoryInitialize();

#endif
