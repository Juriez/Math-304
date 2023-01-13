

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define F(x)  ( (x)*(x)*(x) + 4*(x)*(x) - 10 )

int main (void) {
  int i;
  double a=1.25, b=1.5, tol = 1.0e-5, x0;
  double fa,fb,fx0;

  fa = F(a);
  fb = F(b);

  if (fa*fb >= 0 ) {
    printf("No Root ...\n");
    return EXIT_FAILURE;
  }

  for (i=1; i< MAXN; i++) {
    x0 = (a*fb - b*fa)/(fb - fa);
    fx0 = F(x0);

    if (fabs(fx0) <= tol ) {
      printf("Root = %lf, Itr = %d\n", x0,i );
      return EXIT_SUCCESS;
    }

    if (fa*fx0 < 0 ) {
      b = x0;
      fb = fx0;
    } else {
      a = x0;
      fa = fx0;
    }
  }

  printf("Itr Overflow ...\n");
  return EXIT_FAILURE;
}

