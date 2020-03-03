#ifndef INCLUDE_FB_H
#define INCLUDE_FB_H

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
void fb_move_cursor(unsigned short pos);
void clr_scrn();
void write(char* str, unsigned int len);
void writeint(int i);
void newline();
void scroll();
void checkers();
void writeupdateint(int i);
void writechar(char c);
void writeinputchar(char c);

#endif
