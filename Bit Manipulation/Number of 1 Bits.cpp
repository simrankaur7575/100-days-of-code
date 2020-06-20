/*
QUES - Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011
*/

int Solution::numSetBits(unsigned int A) {
int count=0;
while(A)
{
A=(A)&(A-1);
count++;
}
return count;
}
