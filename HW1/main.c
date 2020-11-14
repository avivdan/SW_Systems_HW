#include <stdio.h>
#include "myMath.h"

int main(){
	double a,b,c;
	
	//e^x +x^3 -2
	printf("insert real number to get : f(X) = e^x +x^3 -2:- \n");
	scanf("%lf",&a);
	double StExp, StPow, StVar, St;
	int floor = mathFloor(a);
	StExp = exponent(floor);
	StPow = power(a,3);
	StVar = add(StPow, StExp);
	St = sub(StVar, 2);
	printf("\nf(X) = e^x +x^3 -2 = %0.4lf", St);
	
	//3x+2x^2
	printf("\ninsert real number to get : f(X) = 3x+2x^2\n");
	scanf("%lf",&b);
	double NdSq, Nd;
	NdSq = power(b,2);
	Nd = add(mul(b,3),mul(NdSq,2));
	printf("\nf(X) = 3x+2x^2 = %0.4lf\n", Nd);
	
	//4x^3/(5-x^2)
	printf("\ninsert real number to get : f(X) = 4x^3/(5-x^2)\n");
	scanf("%lf",&c);
	double RdUp,RdDown,Rd;
	RdUp = mul(4,power(c, 3));
	RdDown = sub(5,power(c,2));
	Rd = div(RdUp, (int)RdDown);
	printf("f(X) = 4x^3/(5-x^2) = %0.4lf\n", Rd);

}

