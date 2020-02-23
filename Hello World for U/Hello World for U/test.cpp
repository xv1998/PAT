#include<bits\stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

int num1, num2, n, ans,isFound = 0;
int datas[1000005],tag[1000005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	cin >> num1 >> num2 >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		char c;
		cin >> a >> c >> b;
		datas[a] = b;
	}
	for (int i = num1; i != -1; i = datas[i]) {
		tag[i]++;
	}
	for (int i = num2; i!= -1; i = datas[i]) {
		if (tag[i] > 0) {
			ans = i;
			isFound = 1;
			break;
		}
	}
	if(isFound == 0)
		printf("-1");
	else printf("%05d", ans);
	return 0;
}