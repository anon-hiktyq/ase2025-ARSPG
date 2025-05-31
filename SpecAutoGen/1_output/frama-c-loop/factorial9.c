
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int factorial9(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

  int i = 1;
  int f = 1;

  while (i <= n)  {
    f = f * i;
    i = i + 1;
  }
  return f;
}