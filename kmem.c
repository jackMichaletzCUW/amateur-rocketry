#include "fb.h"

#define MEM_END_PTR 0x1F00000
#define FREE_INDEX_START_PTR 0x300000
#define AT_STEP_SIZE 1024

#define DEBUG 0

unsigned int *free_index = (unsigned int *) FREE_INDEX_START_PTR;
char **allodex = (char **)(FREE_INDEX_START_PTR + 0x80);
char *at_end_ptr;
char *at_start_ptr;
char *mem_start_ptr = (char *) MEM_END_PTR;

int alloc_amt; // number of allocation records (how far out the allocation table reaches)

int allodex_size;
int allodex_count;

void meminit()
{
    allodex_count = 1;
    
    for(int i = 0; i < 64; i++)
    {
        free_index[i] = 0;
    }
    
    allodex_size = ((int)MEM_END_PTR - (int)FREE_INDEX_START_PTR) / (AT_STEP_SIZE + 4);
    
    for(int i = 0; i < allodex_size; i++)
    {
        allodex[i] = (char*)FREE_INDEX_START_PTR;
    }
    
    allodex[0] = (char*)MEM_END_PTR;
    
    at_start_ptr = (char*)allodex + (allodex_size * 4);
    at_end_ptr = at_start_ptr;
    
    write("MEMINIT:", 9); newline();
    writechar(' '); writechar(186); writechar(' ');
    write("FREE INDEX START       : ", 25); writeint(FREE_INDEX_START_PTR); newline();
    writechar(' '); writechar(186); writechar(' ');
    write("ALLOCDEX START         : ", 25); writeint(allodex); newline();
    writechar(' '); writechar(186); writechar(' ');
    write("ALLOCATION TABLE START : ", 25); writeint(at_start_ptr); newline();
    writechar(' '); writechar(186); writechar(' ');
    write("FREE MEMORY START      : ", 25); writeint(at_end_ptr); newline();
    writechar(' '); writechar(186); writechar(' ');
    write("FREE MEMORY END        : ", 25); writeint(mem_start_ptr); newline();
    /*write(" BEGIN ZERO WRITE: ", 19); newline();
    write("  BYTES WRITTEN: ", 17);
    
    long long* zw = at_start_ptr;
    
    for(int i = 0; i < ((int)mem_start_ptr - (int)at_start_ptr) / sizeof(long long); i++)
    {
        *zw = 0x00;
        zw += sizeof(long long);
        writeupdateint(i);
    }
    
    write(" ...DONE", 8); newline(); newline();
    
    newline();*/
}

char *dec_at(char *atptr)
{
    while(*(atptr - 2) >> 6 & 0x1)
    {
        atptr--;
    }

    return atptr - 1;
}

char *inc_at(char *atptr)
{
    while(*atptr >> 6 & 0x1)
    {
        atptr++;
    }

    return atptr + 1;
}

unsigned int gars_helper(char *at_ptr)
{
    if((*at_ptr >> 6) & 0x1)
    {
        return (*at_ptr & 0x3F) + gars_helper(at_ptr + 1) + 1;
    }
    else
    {
        return (*at_ptr & 0x3F) + 1;
    }
}

unsigned int get_at_record_size(char *at_ptr)
{
    if(at_ptr != (char *)at_start_ptr)
    {
        if((*(at_ptr - 1) >> 6) & 0x1)
        {
            return get_at_record_size(at_ptr - 1);
        }
        else
        {
            return gars_helper(at_ptr);
        }
    }
    else
    {
        if((*at_ptr >> 6) & 0x1)
        {
            return gars_helper(at_ptr);
        }
        else
        {
            return (*at_ptr & 0x3F) + 1;
        }
    }
}

unsigned int fold(char *address)
{
    //write("FOLD ADDR:  ", 12); writeint(address); newline();
    if(address == mem_start_ptr)
    {
        // last entry, easy
        char* tptr = dec_at(at_end_ptr);

        int size = get_at_record_size(tptr);

        mem_start_ptr += size;

        int atrecs = 1 + (size / 64);

        for(int i = 0; i < atrecs; i++)
        {
            *(tptr + i) = 0x00;
        }

        at_end_ptr -= atrecs;
        
        alloc_amt -= atrecs;
    }
    else
    {
        // determine whether address is closer to end or start of memory
        int delta_start = (int)address - (int)mem_start_ptr;
        int delta_end = (int)MEM_END_PTR - (int)address;

        if(delta_start > delta_end)
        {
            // closer to end than start, start at beginning of AT and work forward
            if(DEBUG) { write("c2etS", 5); }
            /*char *atptr = (char *)at_start_ptr;

            int recordsize = get_at_record_size(atptr);

            while(delta_end != recordsize)
            {
                delta_end -= recordsize;

                atptr = inc_at(atptr);

                recordsize = get_at_record_size(atptr);
            }*/
            
            unsigned int dex_ct = 0;
            
            while(dex_ct < allodex_count - 1 && allodex[dex_ct] > address)
            {
                dex_ct++;
            }
            
            int delta_dex = (int)address - (int)allodex[dex_ct];
            
            // we get this far at least
            
            char *atptr = at_start_ptr + (AT_STEP_SIZE * dex_ct);
            
            int recordsize = get_at_record_size(atptr);
            
            if(DEBUG) {
            newline();
            write("Addr:    ", 9);
            writeint((int)address);
            newline();
            write("dex ptr: ", 9);
            writeint((int)allodex[dex_ct]);
            newline();
            write("del dex: ", 9);
            writeint(delta_dex);
            newline();
            write("adc:     ", 9);
            writeint(allodex_count);
            newline();
            write("atsp:    ", 9);
            writeint((int)at_start_ptr);
            newline();
            write("dexCT:   ", 9);
            writeint(dex_ct);
            newline();
            write("at_dptr: ", 9);
            writeint((int)atptr);
                newline(); }

            
            while(delta_dex != recordsize)
            {
                delta_dex -= recordsize;

                atptr = dec_at(atptr);

                recordsize = get_at_record_size(atptr);
            }
            
            // TODO: figure out why I need to do this
            atptr = dec_at(dec_at(atptr));
            
            if(DEBUG) {
            write("atptr:   ", 9);
            writeint((int)atptr);
                newline(); }

            if((*atptr >> 6) & 0x1)
            {
                // more than 64 bytes; multiple AT bytes need to be modified

                do
                {
                    *atptr &= 0x3F;
                    free_index[*atptr & 0x3F]++;
                    atptr++;
                } while ((*atptr >> 6) & 0x1);

                *atptr &= 0x3F;
                free_index[*atptr & 0x3F]++;
            }
            else
            {
                *atptr &= 0x3F;
                free_index[*atptr & 0x3F]++;
            }

            return 0xBABEDEAD;
        }
        else
        {
            // closer to start than end, start at end of AT and work back
            if(DEBUG) { write("c2stE", 5); }
            /*char* atptr = dec_at(at_end_ptr);

            int recordsize = get_at_record_size(atptr);

            while(delta_start != 0)
            {
                delta_start -= recordsize;
                
                atptr = dec_at(atptr);

                recordsize = get_at_record_size(atptr);
            }*/
            
            
            char* atptr;
            
            unsigned int dex_ct = allodex_count - 1;
            
            int delta_dex;

            if(address > allodex[dex_ct])
            {
                //if(allodex[dex_ct] )
                while(dex_ct > 0 && allodex[dex_ct] > address)
                {
                    dex_ct--;
                }
            
                delta_dex = (int)address - (int)allodex[dex_ct];
            
                atptr = at_start_ptr + (AT_STEP_SIZE * dex_ct);
                
                int recordsize = get_at_record_size(atptr);
                
                if(DEBUG) {
                newline();
                write("Addr:    ", 9);
                writeint((int)address);
                newline();
                write("adc:     ", 9);
                writeint(allodex_count);
                newline();
                write("dexCT:   ", 9);
                writeint(dex_ct);
                newline();
                write("dex ptr: ", 9);
                writeint((int)allodex[dex_ct]);
                newline();
                write("del dex: ", 9);
                writeint(delta_dex);
                newline();
                write("at_dptr: ", 9);
                writeint((int)atptr);
                    newline(); }
                
                while(delta_dex != recordsize)
                {
                    delta_dex -= recordsize;

                    atptr = dec_at(atptr);

                    recordsize = get_at_record_size(atptr);
                }
                

            }
            else
            {
                atptr = dec_at(at_end_ptr);

                int recordsize = get_at_record_size(atptr);

                //return mem_start_ptr;

                while(delta_start != 0)
                {
                    delta_start -= recordsize;
                    
                    atptr = dec_at(atptr);

                    recordsize = get_at_record_size(atptr);
                }
            }
            
            // TODO: figure out why I need to do this
            atptr = dec_at(dec_at(atptr));
        
            if(DEBUG) {
            write("atsp:    ", 9);
            writeint((int)at_start_ptr);
            newline();
            
            write("atptr:   ", 9);
            writeint((int)atptr);
                newline(); }

            
            // atptr is the AT record for this memory address now

            if((*atptr >> 6) & 0x1)
            {
                // more than 64 bytes; multiple AT bytes need to be modified

                do
                {
                    *atptr &= 0x3F;
                    free_index[*atptr & 0x3F]++;
                    atptr++;
                } while ((*atptr >> 6) & 0x1);

                *atptr &= 0x3F;
                free_index[*atptr & 0x3F]++;
            }
            else
            {
                *atptr &= 0x3F;
                free_index[*atptr & 0x3F]++;
            }

            return 0xDEADBABE;
        }
        
    }

    return 0xBABEBABE;
}

char* deal(unsigned int bytes_requested)
{
    if(bytes_requested < 65 && free_index[bytes_requested - 1] > 0)
    {
        // free chunk that can be reused

        unsigned int bytes_traversed = 0;

        char* at_loc = (char *)at_start_ptr;

        for(int i = 0; i < (int)at_end_ptr - (int)at_start_ptr; i++)
        {
            bytes_traversed += (*at_loc & 0x3F) + 1;

            if(((*at_loc >> 7) ^ 0x1) && (*at_loc & 0x3F) == (bytes_requested - 1))
            {
                // we found it :)

                *at_loc |= 0x80; // set used flag
                
                free_index[bytes_requested - 1]--; // update free chunk index
                
                if(DEBUG) {
                newline();
                write("Slotting @ ", 11);
                    writeint(MEM_END_PTR - bytes_traversed); newline(); }
                return (char*)MEM_END_PTR - bytes_traversed;
            }

            at_loc++;
        }

        // shouldn't happen - means could not find freed memory
        return (char *)0xBEEFCAFE;
    }
    else
    {
        // no free chunk of requested size; allocate

        unsigned int br_count = bytes_requested;

        while(br_count > 64)
        {
            // will need multiple entries in the allocation table

            *at_end_ptr = 0xFF;
            at_end_ptr++;
            alloc_amt++;
            
            if(alloc_amt % AT_STEP_SIZE == 0)
            {
                allodex[alloc_amt / AT_STEP_SIZE] = mem_start_ptr + (br_count - bytes_requested);
                allodex_count++;
            }
            
            br_count -= 64;
        }

        *(at_end_ptr) = 0x80 | (br_count - 1);
        at_end_ptr++;
        alloc_amt++;

        mem_start_ptr -= bytes_requested;
        
        if(alloc_amt % AT_STEP_SIZE == 0)
        {
            allodex[alloc_amt / AT_STEP_SIZE] = mem_start_ptr;
            
            if(DEBUG) {
            writeint(allodex_count);
            write(": ", 2);
            writeint((int)allodex[alloc_amt / AT_STEP_SIZE]);
                newline(); }
            
            allodex_count++;
        }
        
        return mem_start_ptr;
    }
    
}
