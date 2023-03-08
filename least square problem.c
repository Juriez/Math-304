#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXROW 11
#define MAXCOL 4

int i, j, k;
  double A[MAXROW][MAXROW] ;
  double b[MAXROW] ;
  double x[MAXROW],fx[MAXROW],At[MAXROW][MAXROW],AAt[MAXROW][MAXROW];
void multiplication(double a[MAXROW][MAXROW],double b[MAXROW][MAXROW], int m, int n,double c[MAXROW][MAXROW]);
int main (void) {

  printf("Enter the value of x & f(x) :\n");
  for(int i=0;i<MAXROW;i++)
  {
      scanf("%lf",&x[i]);
      scanf("%lf",&fx[i]);

  }

  printf("Let's create the matrix :\n");


  for(i =0;i<MAXROW;i++)
  {
      A[i][0]=1;
  }

  for(int i=1;i<MAXROW;i++)
  {
      for(int j=1;j<MAXCOL;j++)
      {
          A[i][j]=pow(x[i],j);
      }
  }

  for (i=0; i< MAXROW; i++) {
    for (j=0; j< MAXCOL; j++) {
      printf(" %lf ", A[i][j] );
    }
    printf("\n");
  }

  printf("Transpose of the matrix :\n");
  for(int i=0;i<MAXROW;i++)
  {
      for(int j=0;j<MAXCOL;j++)
      {
          At[j][i]=A[i][j];
      }
  }
  for (i=0; i< MAXCOL; i++) {
    for (j=0; j< MAXROW; j++) {
      printf(" %lf ", At[i][j] );
    }
    printf("\n");
  }
  printf("MULTIPLICATION :\n");
  multiplication(At,A,MAXCOL,MAXROW,AAt);

   for(int i=0;i<MAXCOL;i++)
   {
       for(int j=0;j<MAXCOL;j++)
       {
           printf(" %lf ",AAt[i][j]);
       }printf("\n");
   }

   printf("Create column matrix :\n");
    double sum=0;
   for(int i=0;i<MAXCOL;i++)
   {
       for(int j=0;j<MAXROW;j++)
       {
           sum= sum+At[i][j]*fx[j];
       }
       b[i]=sum;
       sum=0;
   }
   for(int i=0;i<MAXCOL;i++)
   {
       printf("\n%lf ",b[i]);
   }

  double Ab[MAXCOL][MAXCOL+1];
  double M, L;

  for (i=0; i< MAXCOL; i++) {
    for (j=0; j< MAXCOL; j++) {
      Ab[i][j] = AAt[i][j];
    }
    Ab[i][j] = b[i];
  }

  printf("[ [A] [b] ] :\n");
  for (i=0; i< MAXCOL; i++) {
    for (j=0; j< MAXCOL+1; j++) {
      printf("%9.3lf", Ab[i][j] );
    }
    printf("\n");
  }


  for (i=0; i<MAXCOL; i++) {
    L = Ab[i][i];
    for (j=i; j<MAXCOL+1; j++) {
        Ab[i][j] = Ab[i][j]/L;
    }

    for (k=0; k<MAXCOL; k++) {
      if (k != i) {
        M = -Ab[k][i];
        for (j=i; j<MAXCOL+1; j++) {
          Ab[k][j] = Ab[k][j] + M*Ab[i][j];
        }
      }
    }
  }


  printf("[ [A'] [b'] ] :\n");
  for (i=0; i< MAXCOL; i++) {
    for (j=0; j< MAXCOL+1; j++) {
      printf("%9.3lf", Ab[i][j] );
    }
    printf("\n");
  }
  printf("So,the value of corresponding coefficients B0, B1, B2, B3 are :");

for (i=0; i< MAXCOL; i++) {
    printf("%9.3lf ", Ab[i][MAXCOL] );
  }
  return EXIT_SUCCESS;
}
void multiplication(double a[MAXROW][MAXROW],double b[MAXROW][MAXROW], int m, int n,double c[MAXROW][MAXROW]){
  double sum =0;
    for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           for(int k=0;k<n;k++)
           {
               c[i][j]=a[i][k]*b[k][j];
               sum=sum+c[i][j];

           }
           c[i][j]=sum;
           sum=0;
       }
   }
  }
/*
0 0.2 0.4 0.6 0.8 1 1.2 1.4 1.6 1.8 2
1 1.04 1.16 1.36 1.64 2 2.44 2.96 3.56 4.24 5
*/
