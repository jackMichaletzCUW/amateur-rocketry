#ifndef INCLUDE_KMEM_H
#define INCLUDE_KMEM_H

char* deal(unsigned int bytes_requested);
unsigned int fold(char* address);
void meminit();

#endif