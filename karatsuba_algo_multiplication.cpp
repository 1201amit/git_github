#include <iostream>
#include <math.h>

int karatsubaMultiplication(int multiplicant, int multiplier , int num_digit)
{
	if(num_digit <= 1)
		return multiplicant*multiplier;

	int n = pow(10,num_digit/2);
	int a = multiplicant/(n);
	int b = multiplicant%n;
	int c = multiplier/n;
	int d = multiplier%n;

	int ac = karatsubaMultiplication(a,c,num_digit/2);
	int bd = karatsubaMultiplication(b,d,num_digit/2);
	int rest = karatsubaMultiplication((a+b),(c+d),(num_digit/2))-ac-bd;

	return ac*pow(n,2) + rest*(n) + bd;
}

int main()
{
	int multiplicant = 9999;
	int multiplier = 9999;
	int num_digit = 4;

	int output = karatsubaMultiplication(multiplicant, multiplier, num_digit);
	printf("%d\n",output );
	return 0;
}