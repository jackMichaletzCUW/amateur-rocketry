#include "fb.h"

char* mem_end_ptr = (char *) 0x1F00000;
char* idx_start_ptr = (char *) 0x300000;

char* mem_start_ptr;
int offset;

//int firstblank = 0;

/*char pointer*/
char* originalByte = (char*) 0x00300000;
char* endByte = (char*) 0x1F00000;
char* memoryStartPointer;

void memoryInitialize()
{
    memoryStartPointer = originalByte + ((endByte - originalByte) / 9);
    
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
    
    *target |= (1 << (7 - (bitPos % 8)));

    // possible recursion stack overflow?? might have to rewrite as iterative in order for large allocations to work
    if (count > 1)
    {
        setBitToOne (bitPos + 1 , count - 1);
    }
}

char* yoink(int numByte)
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

void kmeminit()
{
    int delta = (int)mem_end_ptr - (int)idx_start_ptr;
    
    offset = delta / 8;
    
    mem_start_ptr = idx_start_ptr + offset;
    
    write("KMEMINIT:", 9); newline();
    write("  IDX_START_PTR: ", 17); writeint(idx_start_ptr); newline();
    write("  MEM_START_PTR: ", 17); writeint(mem_start_ptr); newline();
    write("  MEM_END_PTR  : ", 17); writeint(mem_end_ptr); newline();
    newline();
}

unsigned int kfree(char* address, unsigned int size)
{
    
}

char* kalloc(unsigned int size)
{
    char* aptr = idx_start_ptr;
    
    unsigned int bitcount = 0;
    unsigned int linesize = 0;
    
    while(aptr < mem_start_ptr)
    {
        for(unsigned int i = 0; i < 8; i++)
        {
            if(linesize == size)
            {
                if(linesize <= (i + 1))
                {
                    *aptr |= ((0xFF >> ((i + 1) - linesize)) & (0xFF << 7 - i));
                    
                    //return mem_start_ptr + (((int)aptr - (int)idx_start_ptr) * 8) + ((i + 1) - linesize);
                    return mem_start_ptr + (bitcount - size);
                }
                else
                {
                    unsigned int ls = linesize;
                    
                    for(int j = i; j >= 0; j--)
                    {
                        *aptr |= 0x1 << (7 - j);
                        
                        ls--;
                    }
                    
                    aptr--;
                    
                    while(ls != 0)
                    {
                        for(int j = 7; j >= 0; j--)
                        {
                            if(ls > 0)
                            {
                                *aptr |= 0x1 << (7 - j);
                            
                                ls--;
                            }
                            else
                            {
                                return mem_start_ptr + (bitcount - size);
                            }
                        }
                        
                        aptr--;
                    }
                }
            }
            
            if((*aptr >> i) ^ 0x1)
            {
                linesize++;
            }
            else
            {
                linesize = 0;
            }
            
            bitcount++;
        }
               
        aptr++;
    }
}
