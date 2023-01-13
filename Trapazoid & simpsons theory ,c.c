#include<stdio.h>
#include<math.h>
int main()

{
float x[11];
for(int i=0;i<11;i++)
{
  scanf("%f",&x[i]);
}
float fx[11];
for(int i=0;i<11;i++)
{
  scanf("%f",&fx[i]);
}
float h=(x[1]-x[0]);
float O=0,E=0,X=0;
X=fx[10]+fx[0];
for(int i=1;i<10;i=i+2)
{
 O=O+fx[i];

}
for(int i=2;i<10;i=i+2)
{
 E=E+fx[i];

}
float I1=0,I2=0;
I1= h/2 * (X + 2*(O+E));
I2=h/3 * (X +4*O +2*E);
printf("Trapazoid : %f\n",I1);
printf("Simpsons : %f\n",I2);

}

