.section START_VECTOR, "x"
.global _Homebrew
_Homebrew:
  B load_c

load_c:  
//LDR sp, =stack_top
BL c_entry
B .
