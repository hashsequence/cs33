#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
int fob()
{
  int x = random();
  int y = random();
  int z = random();

  /*convert to double*/

  double dx = (double)x;
  double dy = (double)y;
  double dz = (double)z;
  printf("dx %d dy %d dz %d \n", dx, dy,dz);
  printf("x %d y %d z %d \n", x, y,z);
  //return (dx*dy)*dz == dx*(dy*dz);
   return (float)x == (float)dx;
  //return dx-dy == (double)(x-y);
}

int main()
{
  int value;
  int i = 0;
  for (i = 0; i < 100; i ++)
    {
    value = fob();
  printf("value : %d\n", value);
    }
}
