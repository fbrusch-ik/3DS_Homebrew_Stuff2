#ifndef MEMORY_H
#define MEMORY_H

#define STACK_SIZE 0x00004000
#define FCRAM_BASE 0x20000000
#define TOP_ASPECT_X 0x5
#define TOP_ASPECT_Y 0x3
#define TOP_HEIGHT 240
#define TOP_WIDTH 400
#define TOP_LEFT_FRAME1 0x20184E60
#define TOP_LEFT_FRAME2 0x201CB370

void write_byte(int address, char byte);
void write_word(int address, int word);
void write_color(int address, char r, char g, char b);
int read_word(int address);
void* find_byte_sequence(char* sequence, int num, int base_address);
void paint_pixel(int x, int y, char r, char g, char b, int screen);
void paint_letter(char letter,int x,int y, char r, char g, char b, int screen);
void paint_word(char* word, int x,int y, char r, char g, char b, int screen);
int strlen(char* string); 
#endif

