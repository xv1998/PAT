#include<bits/stdc++.h>
#include<iostream>
#include<map>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen( "input.txt","r",stdin );
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int m, n,tmp = 0,ans;
	cin >> m >> n;
	map<int, int> ma;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int c;
			cin >> c;
			ma[c] += 1;
		}
	}
	for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++) {
		if (it->second > tmp) {
			tmp = it->second;
			ans = it->first;
		}
	}
	cout << ans << endl;
	return 0;
}