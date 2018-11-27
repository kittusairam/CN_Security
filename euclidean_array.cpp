#include <stdio.h>
#include <malloc.h>
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int gcd(int a, int b) {
	if(b == 0)
		return a;
	if(b == 1)
		return 1;
	int temp = a%b;
//	printf("%5d %5d %5d %5d\n", a/b, a, b, temp);
	a = b;
	b = temp;
	return gcd(a, b);
}
int main(int argc, char const *argv[]) {
	int n, i, result, temp;
	printf("Enter n value: ");
	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int)*n);
	printf("Enter %d values: ", n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	result = a[0];
	for(i=1; i<n; i++) {
		result = gcd(result, a[i]);
//		printf("\n");
	}
	printf("GCD of given of integers ");
	printf("%d", a[0]);
	for(i=1; i<n; i++)
		printf(", %d", a[i]);
	printf(" is %d\n", result);
	return 0;
}