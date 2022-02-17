#include<stdio.h>

int  tinhgiaithua( int n) {
	if (n==1)
	    return 1;
	return n*tinhgiaithua(n-1);
	
}

int main()
{
	int n;
	scanf("%d",&n);
	tinhgiaithua(n);
	printf("%d",tinhgiaithua(n));
}
