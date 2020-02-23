#include<bits\stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
struct node
{
	vector<string> vec;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int n, k ,a,b;
	string s;
	cin >> n >> k;
	map<int, node> m;
	for (int i = 0; i < n; i++) {
		char sname[4];
		scanf("%s %d", sname, &a);
		s = sname;
		for (int j = 0; j < a; j++) {
			cin >> b;
			m[b].vec.push_back(s);
		}
	}
	for (int i = 1; i <= k; i++) {
		int len = m[i].vec.size();
		sort(m[i].vec.begin(), m[i].vec.end());
		cout << i << " "<< len << endl;
		for (int j = 0; j < len; j++) {
			cout << m[i].vec[j] << endl;
		}
	}
	return 0;
}