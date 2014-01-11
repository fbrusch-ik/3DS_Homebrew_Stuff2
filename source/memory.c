#include "memory.h"
#include "letters.h"


void write_word(int address, int word){
  int *a = (int*) address;
  *a = word;
}

void write_color(int address, char r, char g, char b){
  write_byte(address, b);
  write_byte(address+1, g);
  write_byte(address+2, r);
}

void write_byte(int address, char byte){
  char *a = (char*) address;
  *a = byte;
}

int read_word(int address){
  int *a = (int*) address;
  return *a;
}

void* find_byte_sequence(char* sequence, int num, int base_address){
  char* c = (char*)base_address;  
  while (1){
    if (*c == sequence[0]){
      int i;
      for (i = 1; i < num; i++){
        if(*(c+i) == sequence[i]){

        } else {
          break;
        }
        return (void*)c;
      }
    }
    c++;
  }
}

void paint_pixel(int x, int y, char r, char g, char b, int screen){
  int coord = 720*x+720-(y*3);
  write_color(coord+screen,r,g,b);
}

void paint_letter(char letter,int x,int y, char r, char g, char b, int screen){

  int i;
  int k;
  unsigned char mask;
  unsigned char* _letter;
  unsigned char l; 

  switch(letter){
    case 'a':
      _letter = letter_A;
      break;
    case 'b':
      _letter = letter_B;
      break;
    case 'c':
      _letter = letter_C;
      break;
    case 'd':
      _letter = letter_D;
      break;
    case 'e':
      _letter = letter_E;
      break;
    case 'f':
      _letter = letter_F;
      break;
    case 'g':
      _letter = letter_G;
      break;
    case 'h':
      _letter = letter_H;
      break;
    case 'i':
      _letter = letter_I;
      break;
    case 'j':
      _letter = letter_J;
      break;
    case 'k':
      _letter = letter_K;
      break;
    case 'l':
      _letter = letter_L;
      break;
    case 'm':
      _letter = letter_M;
      break;
    case 'n':
      _letter = letter_N;
      break;
    case 'o':
      _letter = letter_O;
      break;
    case 'p':
      _letter = letter_P;
      break;
    case 'q':
      _letter = letter_Q;
      break;
    case 'r':
      _letter = letter_R;
      break;
    case 's':
      _letter = letter_S;
      break;
    case 't':
      _letter = letter_T;
      break;
    case 'u':
      _letter = letter_U;
      break;
    case 'v':
      _letter = letter_V;
      break;
    case 'w':
      _letter = letter_W;
      break;
    case 'x':
      _letter = letter_X;
      break;
    case 'y':
      _letter = letter_Y;
      break;
    case 'z':
      _letter = letter_Z;
      break;
    case ' ':
      return;
      break;
    case '1':
      _letter = letter_C;
      break;
    default:
      break;
  }

  for (i = 0; i < 8; i++){
    mask = 0b10000000;
    l = _letter[i];
    for (k = 0; k < 8; k++){
      if ((mask >> k) & l){
        paint_pixel(k+x,i+y,r,g,b,screen);
      }     
    }
  }
}

int strlen(char* string){
  int i;
  for (i = 0; ; i++){
      if (string[i] == 0x00){
        return i;
      }
  }
}

void paint_word(char* word, int x,int y, char r, char g, char b, int screen){
    int tmp_x =x;
    int i;
    int line = 0;

    for (i = 0; i <strlen(word); i++){
     
      if (tmp_x+8 > TOP_WIDTH) {
        line++;
        tmp_x = x;
      }
      paint_letter(word[i],tmp_x,y+(line*8),r,g,b, screen);

      tmp_x = tmp_x+8;
    }

}