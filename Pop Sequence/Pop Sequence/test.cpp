#include<bits\stdc++.h>
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int n, m, k;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		stack<int> s;
		vector<int>vec;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			vec.push_back(a);
		}
		int num = 0;
		bool tag = true;
		for (int j = 1; j <= n; j++) {
			if (s.size() == m) {
				tag = false;
				break;
			}
			s.push(j);
			while (!s.empty() && s.top() == vec[num]) {
				num++;
				s.pop();
			}
		}
		if (tag && s.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}