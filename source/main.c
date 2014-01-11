#include "main.h"
#include "memory.h"

int main()
{
  int i;
  char* a = "das hier ist ein test es ist zwar alles in caps das macht aber nix alle buchstaben sind noch nicht nach ordinale geordet in ein array";

  paint_word(a,40,40,0,0,0, TOP_LEFT_FRAME1);
  paint_word(a,40,40,0,0,0, TOP_LEFT_FRAME2);

  return 0;
}

