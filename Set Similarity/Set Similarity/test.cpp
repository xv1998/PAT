#include<set>
#include<iostream>
#include<vector>
#include<bits\stdc++.h>

using namespace std;
set<int> s[55];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,m,a,b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 1; j <= m; j++) {
			cin >> a;
			s[i].insert(a);
		}
	}
	cin >>m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vector<int> plus(s[a].size()+ s[b].size());
		vector<int> minutes(s[a].size() + s[b].size());
		auto it = set_union(s[a].begin(), s[a].end(), s[b].begin(), s[b].end(), plus.begin());
		auto iter = set_intersection(s[a].begin(), s[a].end(), s[b].begin(), s[b].end(), minutes.begin());
		plus.resize(it - plus.begin());
		minutes.resize(iter - minutes.begin());
		printf("%.1lf%%\n", minutes.size() * 100.0 / plus.size());
	}

	return 0;
}