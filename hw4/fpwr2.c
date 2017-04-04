//2.90
//Avery Wong
//cs33
//904 582 269
//
//double |1|11|52|
//if we want 2^x to be return zero it has to break the threshold of
//0|00000000000|0000........1| therefoe its 2^(1-1023)*(2^-25) which 
//means x = -1075 at x < -1074 it should return 0
//for the 2nd case x < smallest normatlized value 1022 
// bias = 2^(k-1) - 1
//e = the unsigned int of the exponent field
//E = e - bias
// case 3:
//want s|11111111111|               |
//
double fpwr2(int x)
{
  unsigned long exp, frac;
  unsigned long u;

  if (x < -1074)
    {
      /* Too small. Return 0.0 */
      exp = 0;
      frac = 0;
    }
  else if ( x < -1022)
    {
      /* Denormalized result  */
      exp = 0;
      frac = 1 << (1074 + x) ;
    }
  else if (x < 1024)
    {
      /* Normalized result */
      exp =  x + 1023
      frac = 0

    }
  else
    {
      /* Too big. return +infinity */
      exp = 1 << 10 >> 10;
      frac = 0;
    }
  /* Pack exp  and frac into 64 bits*/
  u = exp << 52 | frac;
  extern double u2f(unsigned long);
}
