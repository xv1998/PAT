#include<bits\stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m, l, fav[205];
vector<int> ori;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &fav[i]);
	}
	cin >> l;
	ori.push_back(0);
	for (int i = 1; i <= l; i++) {
		int b;
		cin >> b;
		if (b - n > 0)
			continue;
		else ori.push_back(b);
	}// È¥³ý¶àÓàÊý×Ö
	vector<vector<int>> vec(m + 1, vector<int>(ori.size(),0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < ori.size(); j++) {
			if (fav[i] == ori[j]) {
				vec[i][j] = vec[i][j - 1] + 1;
			}
			else {
				vec[i][j] = max(vec[i - 1][j], vec[i][j - 1]);
			}
		}
	}
	cout << vec.back().back() << endl;
	return 0;
}