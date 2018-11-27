#include <stdio.h>
int main() {
	int a, b, c, temp, m, i;
	printf("Enter a, b, c values in a^b mod c: ");
	scanf("%d %d %d", &a, &b, &c);
	temp = b;
	m = 0;
	int bin[10];
	while(temp > 0) {
		bin[m] = temp % 2;
//		printf("%d %d\n", temp % 2, m);
		temp = temp/2;
		m++;
	}
	int arr[15];
	arr[0] = a;
	int val = 1;
	temp = a;
	while(val < m) {
		temp = (temp * temp) % c;
		arr[val] = temp;
//		printf("%d\n", temp);
		val++;
	}
	int pro = 1;
	for(i=0; i<val; i++)
		if(bin[i] == 1) {
			pro *= arr[i];
//			printf("-%d-\n", arr[i]);
		}
	printf("Result after computing given number using Faster Modular exponential is %d\n", pro % c);
	return 0;
}