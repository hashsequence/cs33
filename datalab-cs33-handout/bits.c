/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer s ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4- returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  return (( ~x & ( x + ~0 ) ) >> 31)&1;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
 
int t1 = 0x55 + (0x55 << 8) + (0x55 << 16) + (0x55 << 24);
int t2 = 0x33 + (0x33 << 8) + (0x33 << 16) + (0x33 << 24);
int t3 = 0x0F + (0x0F << 8) + (0x0F << 16) + (0x0F << 24);
//int t4 = 0xFF + (0xFF << 16); 
//int t5 = 0xFF + (0xFF << 8); 
/*the idea is a type of binary recursion type algorithm where we sum up the little parts then
add up the branches take a look at (10,11) and (01, 00), with two leaevs each,  treat these as branches then we use shifts and 
addition to store the ones on each of the two leaves of each branch so we get (01,10)  and (01, 00), now for each branch we sum the leaves 
and we get (0100) and (0001) now these are the two leaves of the 8 bit branch and we do this recursively upwards */
int a0 = x & t1;
int a1 = (x >> 1 ) & t1;
int b = a0 + a1;

int b0 = b & t2;
int b1 = (b >> 2) & t2;
int c = b0 + b1;

int c0 = c & t3;
int c1 = (c >> 4) & t3;
 x = c0 + c1;
 //notice the max sum of the bits is 32 so we only need 8 bits to store the data
//since all the sums are already on the last 8 bits, we just need to shift
//and add the four leaves of 8bits that store the sum and add up the leaves
//there for I can optimize the number of ops this way
   x = x + (x >> 8);  
   x = x + (x >> 16);
  	
   return x & 0x7f;
}
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~(~x&~y);
}
/*
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40
 *   Rating: 4
 */
int bitRepeat(int x, int n) {
  int m = ((1 << n) - 1);
  //int m = ~((0x80 << 24) >> (31 - n));
  int s = x&m;
  
  int s1 = s + (s << n);
  int s2 = s1 + (s1 << n << n);
  int s3 = s2 + (s2 << n << n << n << n);
  int s4 = s3 + (s3 << n << n << n << n << n << n << n << n);
  //int s5 = s4 + (s4 << n << n << n << n << n << n << n << n 
  //	            << n << n << n << n << n << n << n << n); 
  int n_is_one_V = s4 + (s4 << 16);
  int n_is_one = ((!(1^n))<<31)>>31;
  int n_is_32 = ((!(0x20^n))<<31)>>31;
  return ((n_is_one)&n_is_one_V)|((n_is_32)&x)|(~(n_is_one|n_is_32)&s4);
  
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  //int m0 = ( 1 << n); // mask 1 in the nth position
  //int m1 = ((m0) + (~1 + 1));  // mask to check all the bits beyond the n bits

  //int c1 = !!(x&(~m1));
  //int c2 = ((((1 << 31) & x) >> 31)&1) & (((m0 & x) >> n));
  //return c1 & c2;;
  int t1 = (32 +(~n+1)); //basically we want to extract the n least significant bits 
  int t2 = ((x << t1) >> t1); // this extracts only the right n bits and leaves either trailing ones or zeroes
  int t3 = !(t2^x); // xor the mask with x, and if the two value are the same then should return 1
  return t3;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int m = n << 3;
  int m2 = 0xff << m;
  return (((x&m2) >> m)&0xff);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  //int m = 1 << 31;
  //int c1 =  ((~(y + (~x+1))&(m)) >> 31)&1;
  //int c2 = !(((~(x + (~y+1))&(m)) >> 31)&1); 
  //int c3 = (((x&m)>>31)&1)&((~((y&m)>>31))&1);
  // int tmin = 1 << 31;
  //int xisneg = ((x&tmin) >> 31)&1; //returns true if x is negative
  //int yisneg = ((y&tmin) >> 31)&1; //returns true if y is negative
  //int e0 = !(((~x+y+1) >> 31)&1); //non-boudary cases (negating x)
  //int e3 = !((tmin) + y); // true if y is tmin
  // int e2 = !((tmin) + x); //true if x is tmin
  int sumchecker = (((~x+1)+ y) >> 31);//is 11111.... if neg, is 0000.. if pos
  int signchecker = 1 << 31;
  int xisneg = signchecker&x;
  int yisneg = signchecker&y;
  int xysigndiffer = ((xisneg^yisneg) >> 31)&1;
  return (xysigndiffer&(xisneg>>31)) | (!sumchecker&(!xysigndiffer)); 

}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return (!(((1 << 31) & x) >> 31))&(!!(x|0));
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
   return (x >> n) & ~(((1 << 31) >> n) << 1);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
