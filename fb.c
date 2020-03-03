#include "io.h"

#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

#define FB_COLS 80
#define FB_ROWS 25
#define FB_SIZE 2000

#define DEF_BG_COL 0x0
#define DEF_FG_COL 0xD
#define INT_COL 0xA

char *fb = (char *) 0x000B8000;
int fb_pos = 0; // current frame buffer position

void fb_move_cursor(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

void scroll()
{
    char* p = fb + 160;
    
    for(int i = 0; i < (FB_SIZE * 2) - 160; i++)
    {
        *(p-160) = *p;
        p++;
    }
    
    fb_move_cursor(FB_SIZE - 80);
    fb_pos = FB_SIZE - 80;
}

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    if(fb_pos > FB_SIZE)
    {
        scroll();
    }
    
	fb[i] = c;
	fb[i + 1] = (bg << 4) | (fg & 0x0F);
}

void writechar(char c)
{
    fb_write_cell(fb_pos * 2, c, DEF_FG_COL, DEF_BG_COL);
    fb_move_cursor(++fb_pos);
}

void writeinputchar(char c)
{
    fb_write_cell(fb_pos * 2, c, 0xE, DEF_BG_COL);
    fb_move_cursor(++fb_pos);
}

void clr_scrn()
{
	for(int i = 0; i < FB_SIZE; i++)
	{
		fb_write_cell(i * 2, ' ', DEF_BG_COL, DEF_BG_COL);
	}
    
    fb_move_cursor(0);
    fb_pos = 0;
}

void checkers(char c1, char c2)
{
    clr_scrn();
    
    for(int i = 0; i < FB_SIZE; i++)
    {
        if(i % 2)
        {
            if((i / 80) % 2)
            {
                fb_write_cell(i * 2, 219, c1, c1);
            }
            else
            {
                fb_write_cell(i * 2, 219, c2, c2);
            }
        }
        else
        {
            if((i / 80) % 2)
            {
                fb_write_cell(i * 2, 219, c2, c2);
            }
            else
            {
                fb_write_cell(i * 2, 219, c1, c1);
            }
        }
    }
}

int write(char* str, unsigned int len)
{
    if((fb_pos + len) > FB_SIZE)
    {
        scroll();
    }
    
	for(unsigned int i = 0; i < len; i++)
	{
		fb_write_cell(fb_pos * 2, str[i], DEF_FG_COL, DEF_BG_COL);
		fb_move_cursor(++fb_pos);
	}

	return 0;
}

void newline()
{
    int spaces = 80 - (fb_pos % 80);
    
    fb_pos += spaces;
    
    fb_move_cursor(fb_pos);
}

void writeint(int i)
{
    if((fb_pos + 10) > FB_SIZE)
    {
        scroll();
    }
    
    fb_write_cell(fb_pos * 2, '0', INT_COL, DEF_BG_COL);
    fb_move_cursor(++fb_pos);
    
    fb_write_cell(fb_pos * 2, 'x', INT_COL, DEF_BG_COL);
    fb_move_cursor(++fb_pos);
    
    char* p = (char *)&i;
    
    for(int j = 3; j >= 0; j--)
    {
        char byte = *(p+j);
        
        char lh = (byte & 0xF0) >> 4;
        char rh = byte & 0x0F;
        
        if(lh < 10)
        {
            lh += 48;
        }
        else
        {
            lh += 55;
        }
        
        if(rh < 10)
        {
            rh += 48;
        }
        else
        {
            rh += 55;
        }
        
        fb_write_cell(fb_pos * 2, lh, INT_COL, DEF_BG_COL);
        fb_move_cursor(++fb_pos);
        
        fb_write_cell(fb_pos * 2, rh, INT_COL, DEF_BG_COL);
        fb_move_cursor(++fb_pos);
    }
}

void writeupdateint(int i)
{
    writeint(i);
    fb_pos -= 10;
    fb_move_cursor(fb_pos);
}
