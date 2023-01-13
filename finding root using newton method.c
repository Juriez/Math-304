
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define F(x)  ( (x)*(x)*(x) + 4*(x)*(x) - 10 )
#define DF(x) (3*x*x + 8*x)

int main (void) {
  int i;
  double x1=1.5, x2, tol = 10.0e-6, x0;
  double fx1,fx2,dfx1;

  fx1 = F(x1);   dfx1 = DF(x1);

  for (i=1; i< MAXN; i++) {
    x2 = x1-fx1/dfx1;
    fx2 = F(x2);

    if (fabs(fx2) <= tol ) {
      printf("\nAbsolute Root = %lf, Itr = %d\n", x2,i );
      //return EXIT_SUCCESS;
      break;
    }

    /*if (fx1*dfx1 < 0 ) {
      b = x0;
      fb = fx0;
    } else {
      a = x0;
      fa = fx0;
    }*/
    x1=x2;
    //x2=x3;
    fx1=fx2;
    dfx1=DF(x2);
  }

  //printf("Itr Overflow ...\n");
  return EXIT_FAILURE;
}


