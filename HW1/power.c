#include "myMath.h"
#define exp 2.71828
double exponent(int x){
	int a;
	double b = 1;
	if(x<0){
		for(a=0; a< -x; a = a + 1){
			b = b/exp;
		}
		return b;
	}else{
		for( a = 0; a < x; a = a + 1 ){
	    		b=b*exp;
	    	}
	    	return b;
	}
}

double power(double x, int y){
	int a;
	double b = 1;
	if(y<0){
		for( a = 0; a < -y; a = a + 1 ){
	    		b=b/x;
	    	}
	    	return b;
	}else{
		for( a = 0; a < y; a = a + 1 ){
	    		b=b*x;
	    	}
	    	return b;
	}
	
}
int mathFloor(double x){
	int a = (int)x;
	if(x>=0){
		return a;
	}else if(a-x>0.01){
		return a-1;
	}else{
		return a;
	}
}
