#include<bits\stdc++.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int n ,m,a,b;
	cin >> n;
	vector<int> all(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a;
		all[i] = a + all[i - 1];
	}
	cin >> m;
	for(int i = 0; i < m;i++){
		cin >> a >> b;
		if (a > b) swap(a, b);
		cout << min(all[b - 1] - all[a - 1],all[n] - all[b - 1] + all[a - 1]) << endl;
	}
	return 0;
}