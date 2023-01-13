
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define F(x)  ( (x)*(x)*(x) + 4*(x)*(x) - 10 )

int main (void) {
  int i;
  double x1=2, x2=1.5,x3, tol = 10.0e-5, x0;
  double fx1,fx2,fx3;

  fx1 = F(x1);   fx2 = F(x2);

  for (i=1; i< MAXN; i++) {
    //printf("%lf     %lf     %lf     %lf     %lf     %lf     %d\n",a,b,x0,F(a),F(b),F(x0),i);
    x3 = x2-((fx2)*(x2-x1))/(fx2-fx1);
    fx3 = F(x3);

    if (fabs(fx3) <= tol ) {
      printf("\nAbsolute Root = %lf, Itr = %d\n", x3,i );
      //return EXIT_SUCCESS;
      break;
    }

    /*if (fx1*fx3 < 0 ) {
      b = x0;
      fb = fx0;
    } else {
      a = x0;
      fa = fx0;
    }*/
    x1=x2;
    x2=x3;
    fx1=fx2;
    fx2=fx3;
  }

  //printf("Itr Overflow ...\n");
  return EXIT_FAILURE;
}


