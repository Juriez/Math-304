#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXROW 3
#define MAXCOL 3
#define PI   3.14159

#define F1(y,z) (85- 3*y + 2*z)/15;
#define F2(x,z) (51- 2*x -z)/10;
#define F3(x,y) (5 - x + 2*y)/8;
//#define tol 10.e-6;
int main()
{
    double tol=10.e-6;
    int i=0;
    double x10,x20,x30,x1,x2,x3;
    while(1)
    {
        x1=F1(x20,x30);
        x2=F2(x1,x30);
        x3=F3(x1,x2);
        i++;
        if((fabs(x1-x10) < tol) && (fabs(x2-x20)< tol) && (fabs(x3-x30)< tol))
        {
            printf("x1 = %9lf, x2 = %9lf, x3 = %9lf\n",x1,x2,x3);
            printf("Number of itteration = %d\n",i);
            break;

        }
        x10=x1;
        x20=x2;
        x30=x3;
    }
    return EXIT_SUCCESS;

}



