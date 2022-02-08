#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
// C code to return the binary representation of an input hexadecial digit
// In other words, an encoder for a hexadecimal digit to binary digits

// Or returns the or operation between 8 inputs -> a1,a2...a8
int Or(char a, char a1, char a2, char a3, char a4, char a5, char a6, char a7, char a8)
{
	if(a==a1||a==a2||a==a3||a==a4||a==a5||a==a6||a==a7||a==a8)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// We define functions for each bit
int B0(char c) 
{
	int b0 = Or(c,'1','3','5','7','9','B','D','F'); // B0 = 1 + 3 + 5 + 7 + 9 + B + D + F
	return b0;
}
int B1(char c)
{
	int b1 = Or(c,'2','3','6','7','A','B','E','F'); //B1 = 2 + 3 + 6 + 7 + A + B + E + F
	return b1;
}
int B2(char c)
{
	int b2 = Or(c,'4','5','6','7','C','D','E','F'); //B2 = 4 + 5 + 6 + 7 + C + D + E + F
	return b2;
}
int B3(char c)
{
	int b3 = Or(c,'8','9','A','B','C','D','E','F'); //B3 = 8 + 9 + A + B + C + D + E + F
	return b3;
}

int main(void)
{
	char c;
	printf("Enter a digit from 0 to 9, or an uppercase alphabet from A to F: ");
	c = getchar();
	int b0 = B0(c);
	int b1 = B1(c);
	int b2 = B2(c);
	int b3 = B3(c);
	printf("The binary representation for the input digit is: %d%d%d%d\n",b3,b2,b1,b0);
}