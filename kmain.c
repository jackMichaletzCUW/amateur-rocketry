#include "io.h"
#include "fb.h"
#include "kmemory.h"
#include "kinterrupts.h"
#include "gdt.h"
#include "string.h"
#include "prompt.h"
#include "imaging.h"

typedef long unsigned int size_t;

void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size) {
    unsigned char* dst = (unsigned char*) dstptr;
    const unsigned char* src = (const unsigned char*) srcptr;
    for (size_t i = 0; i < size; i++)
        dst[i] = src[i];
    return dstptr;
}

int main()
{
    gdt_init();
    init_idt();
	clr_scrn();
    
    toggleBlinking();
    
    imageDisplaySplash();
    
    memoryInitialize();
    
    promptInitialize("amateur rocketry> ");
    
	return 0;
}
