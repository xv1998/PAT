#include<stdio.h>
using namespace std;
int main() {
	int a, b, c, d, e, f;
	scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
	b += e + (c + f) / 29;
	a += d + b / 17;
	printf("%d.%d.%d\n", a, b % 17, (c + f) % 29);
	return 0;
}