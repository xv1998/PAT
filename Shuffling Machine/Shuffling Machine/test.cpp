#include<bits\stdc++.h>
#include<iostream>

using namespace std;
int n, order[55],result[55];
void change(int i, int a, int num) {
	if (num != n) {
		a = order[a];
		change(i,a,++num);
	}
	else {
		result[a] = i;
		return;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	cin >> n;
	for (int i = 1; i <= 54; i++) {
		scanf("%d", &order[i]);
	}
	for (int i = 1; i <= 54; i++) {
		int num = 0;
		change(i,i,num);
	}
	for (int i = 1; i <= 54; i++) {
		if (result[i] <= 13)
			cout << "S" << result[i];
		else if(result[i] <= 26)
			cout << "H" << result[i] -13;
		else if (result[i] <= 39)
			cout << "C" << result[i] - 26;
		else if (result[i] <= 52)
			cout << "D" << result[i] - 39;
		else cout << "J" << result[i] - 52;
		if(i != 54)
			printf(" ");
	}
	return 0;
}