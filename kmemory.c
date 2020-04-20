#include "fb.h"

//int firstblank = 0;

/*char pointer*/
char* originalByte = (char*) 0x00300000;
char* endByte = (char*) 0x1F00000;
char* memoryStartPointer;

void memoryInitialize()
{
    memoryStartPointer = originalByte + ((endByte - originalByte) / 9);
    
    int characterSize = ((int)endByte - (int)originalByte) / 2000;
    
    writestr("clearing memory...  ");
    
    for (char* i = originalByte; i < endByte-1; i++) {
        *i = 0x00;
        
        if ((int)i % 0x100000 == 0) {
            writeupdateint((int)i);
        }
        
        /*if ((int)i % characterSize == 0) {
            *((((char*)0xB8000) + ( ( ( (int)i - (int)originalByte ) / characterSize ) * 2) ) + 1)  |= 0xF0;
           // writechar(' ');
        }*/
    }
    
    clr_scrn();
    
    newline();
    writechar(' ');
    writechar(201);
    for(int i = 0; i < 32; i++) { writechar(205); }
    writechar(187); newline();
    writechar(' ');
    writechar(186);
    write(" a m a t e u r  r o c k e t r y ", 32);
    writechar(186);
    newline();
    writechar(' ');
    writechar(200);
    for(int i = 0; i < 32; i++) { writechar(205); }
    writechar(188); newline();
    newline();
    
    
    write("meminit:", 9); newline();
    writechar(' '); writechar(186); writechar(' ');
    write("allocation table start : ", 25); writeint(originalByte); newline();
    writechar(' '); writechar(186); writechar(' ');
    write("free memory start      : ", 25); writeint(memoryStartPointer); newline();
    writechar(' '); writechar(186); writechar(' ');
    write("free memory end        : ", 25); writeint(endByte); newline();
    //writechar(' '); writechar(186); writechar(' ');
    newline();
    /*write("setting up allocation table...", 30); newline();
    writechar(' '); writechar(200); writechar(' ');
    write("bytes written: ", 15);
    
    int sll = sizeof(long long);
    
    for(int i = 0; i < ((int)memoryStartPointer - (int)originalByte) / sll; i++)
    {
        *((long long*)(originalByte + i)) = 0x0000;
        writeupdateint(i * sll);
    }
    
    newline();*/
}

void setBitToOne (int bitPos,int count)
{
    char* target =  originalByte + (bitPos/8);
    
    /**target |= (1 << (7 - (bitPos % 8)));

    // possible recursion stack overflow?? might have to rewrite as iterative in order for large allocations to work
    if (count > 1)
    {
        setBitToOne (bitPos + 1 , count - 1);
    }**/
    
    // iterative way
    while (count>0) {
        *target |= (1 << (7 - (bitPos % 8)));
        
        bitPos++;
        count--;
        
        if (bitPos % 8 == 0) {
            target++;
        }
    }
}

char* memoryAllocate(int numByte)
{
    int count = 0;
    int bitCount = 0;
    char* curByte = originalByte;
    
    while (curByte < memoryStartPointer)
    {
        for (int i = 7; i >= 0; i--)
        {
            bitCount++;
            
            if ((*curByte >> i) & 1)
            {
                count = 0;
            }
            else
            {
                count++;
                if(count == numByte)
                {
                    setBitToOne(bitCount - count, count);
                    return memoryStartPointer + (bitCount - count);
                }
            }
        }
        
        curByte++;
    }
    
    return (char*)0xCAFEBABE;
}

unsigned int memoryFree(char* address, unsigned int size)
{
    int offset = (int)(address - memoryStartPointer);
    char* targetByte = originalByte + (offset / 8);
    
    int bitOffset = offset % 8;
    
    while (size>0) {
        *targetByte &= (0xFF & ~(1 << (7-bitOffset)));
        
        bitOffset++;
        size--;
        
        if (bitOffset == 8) {
            bitOffset = 0;
            targetByte++;
        }
    }
    
    return 0xDEADBABE;
}
