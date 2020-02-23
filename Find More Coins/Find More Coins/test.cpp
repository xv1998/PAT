#include<bits\stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;
int arr[10005],bag[101];
bool selected[10005][101];

bool tmp(int a, int b) {
	return a > b;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i+1] = a;
	}
	arr[0] = 0;
	sort(arr+1, arr + n+1, tmp);
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j - arr[i] >= 0 && bag[j - arr[i]] + arr[i] >=bag[j]) {
				selected[i][j] = true;
				bag[j] = bag[j - arr[i]] + arr[i];
			}
		}
	}
	if (bag[m] != m) {
		cout << "No Solution" << endl;
		return 0;
	}
	int j = m, i = n;
	while (1)
	{
		if (selected[i][j] == true) {
			cout << arr[i];
			j -= arr[i];
			if (j != 0)
				cout << " ";
		}
		i--;
		if (j == 0 || i == 0)
			break;
	}
	cout << endl;
	return 0;
}