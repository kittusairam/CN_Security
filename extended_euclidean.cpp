#include <stdio.h>
int s1 = 1, s2 = 0, s, t1 = 0, t2 = 1, t;
int gcd(int a, int b) {
	if(b == 0)
		return a;
	if(b == 1)
		return b;
	int q = a/b;
	int temp = a - q * b;
//	printf("%d %d %d %d\n", q, a, b, temp);
	a = b;
	b = temp;
 
	s = s1 - q * s2;
	s1 = s2;
	s2 = s;
 
	t = t1 - q * t2;
	t1 = t2;
	t2 = t;
	return gcd(a, b);
}
int main(int argc, char const *argv[]) {
	int a, b, temp;
	printf("Enter two numbers: ");
	scanf("%d%d", &a, &b);
//	printf("%5s %5s %5s %5s\n", "q", "r1", "r2", "r");
	printf("GCD of %d %d is %d\n", a, b, gcd(a, b));
 
	printf("s = %d, t = %d", s, t);
	while(s<0)
		s += b;
	while(t<0)
		t += a;
	
	printf("\n%d is the multiplication inverse of %d under modulo %d", s, a, b);
	printf("\n%d is the multiplication inverse of %d under modulo %d", t, b, a);
	return 0;
}