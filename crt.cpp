#include <stdio.h>
#include <malloc.h>
int inverse(int a, int b) {
	int s1 = 1, s2 = 0, s, t1 = 0, t2 = 1, t;
	int gcd(int a, int b) {
		if(b == 0)
			return a;
		if(b == 1)
			return b;
		int q = a/b;
		int temp = a - q*b;
		a = b;
		b = temp;
		s = s1 - q*s2;
		s1 = s2;
		s2 = s;
		t = t1 - q*t2;
		t1 = t2;
		t2 = t;
		return gcd(a,b);
	}
	gcd(a, b);
	while(s < 0)
		s += b;
		printf("%d is Modular inverse of %d with %d\n", s, a, b);
	return s;
}
int main() {
	int k, M = 1, i, x = 0;
	printf("Enter no of inputs: ");
	scanf("%d", &k);
	int *a = (int*)malloc(sizeof(int)*k), *r = (int*)malloc(sizeof(int)*k), *m = (int*)malloc(sizeof(int)*k), *m_i = (int*)malloc(sizeof(int)*k);
	printf("Enter %d coprime elements as array: ", k);
	for(i=0; i<k; i++) {
		scanf("%d", &a[i]);
		M *= a[i];
	}
	printf("Enter %d elements of their remainders as array: ", k);
	for(i=0; i<k; i++)
		scanf("%d", &r[i]);
	for(i=0; i<k; i++){
		m[i] = M / a[i];
		m_i[i] = inverse(m[i], a[i]);
	}
	for(i=0; i<k; i++)
		x += r[i] * m[i] * m_i[i];
	x %= M;
	printf("The Chinese Remainder Theorem output for given numbers and their respective remainder is: %d", x);
}