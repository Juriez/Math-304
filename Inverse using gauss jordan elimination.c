
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXROW 3
#define MAXCOL 3
#define PI   3.14159


int main (void) {
  int i, j, k;
  double A[MAXROW][MAXCOL] = { {1,3,2}, {1,2,3}, {2,-1,4}};
  double b[MAXROW][MAXCOL] = {{1,0,0},{0,1,0},{0,0,1}};
  double Ab[MAXROW][MAXCOL+3];
  double M, L;

  for (i=0; i< MAXROW; i++) {
    for (j=0; j< MAXCOL+3; j++) {
            //if(j<MAXCOL)
      Ab[i][j] = A[i][j];

    }
  }
    int l;
  for (i=0; i< MAXROW; i++) {
    for (j=MAXCOL,l=0; j< MAXCOL+3,l<3; j++,l++) {
            //if(j<MAXCOL)
      Ab[i][j] = b[i][l];


    }
  }


  printf("[ [A] [b] ] :\n");
  for (i=0; i< MAXROW; i++) {
    for (j=0; j< MAXCOL+3; j++) {
      printf("%9.3lf", Ab[i][j] );
    }
    printf("\n");
  }


  for (i=0; i<MAXROW; i++) {
    L = Ab[i][i];
    for (j=0; j<MAXCOL+3; j++) {
        Ab[i][j] = Ab[i][j]/L;
    }

    for (k=0; k<MAXROW; k++) {
      if (k != i) {
        M = -Ab[k][i];
        for (j=0; j<MAXCOL+3; j++) {
          Ab[k][j] = Ab[k][j] + M*Ab[i][j];
        }
      }
    }
  }


  printf("[ [A'] [b'] ] :\n");
  for (i=0; i< MAXROW; i++) {
    for (j=0; j< MAXCOL+3; j++) {
      printf("%9.3lf", Ab[i][j] );
    }
    printf("\n");
  }
  printf("\n So, the inverse matrix of the given matrix A is :\n");
  for(i=0;i<MAXROW;i++)
  {
      for(j=MAXCOL;j<MAXCOL+3;j++)
      {
          printf("%9.3lf ",Ab[i][j]);
      }
      printf("\n");
  }

}

