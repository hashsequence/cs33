
//F.
long loop(long x, long n)
{
	long result = 0;
	long mask;
	for (mask = 1; mask != 0; mask <<= n&0xff)
	{
		result |= mask&x;
	} 
	return result;
}

/*

A. originally %rdi holds x but then r8 holds x at one point too, originally 
   esi holds n, but later it was copy assigned to ecx, result is stored in %rax
   mask is stored in %edx

B. the initial values of result is 0, the initial result of mask is 1

c. the test condition of mask is mask != 0 because testq %rdx, %rdx returns 
	mask&mask which is either zero or not and if it is not equal zero
	it continues though the loop
D. the mask is updated in line salq %cl, %rdx where it shifts
    mask by the last 8 bits of the register that holds n (register %cl)

E. result gets updated like: result |= mask&x;
    via the instructions:
	 movq %rdi, %r8    4th argument holds x
	 andq %rdx %r8     4th arguments now holds mask&x
	 orq  %r8  %rax     result |= mask&x
*/
