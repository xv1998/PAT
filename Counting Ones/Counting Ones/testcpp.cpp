#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int n, i = 1,sum = 0;
	cin >> n;
	while (i <= n) {
		int high = n / (i*10);// 高位
		int low = n % i;// 低位 
		int cur = n / i %10;// 当前数
		sum += high*i;
		if (cur > 1)
			sum += 1 * i;
		else if (cur == 1)
			sum = sum + low + 1;
		i *= 10;
	}
	printf("%d", sum);
	return 0;
}