#include<bits\stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct node
{
	bool show = false;
	int num = 0;
}num[510];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int n, m, a;
	bool isFind = false;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		num[a].show = true;
		num[a].num++;
		vec[i] = a;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		if (vec[i] <= (m - vec[i]) && (m - vec[i]) <= 500 && num[m - vec[i]].show) {
			if (vec[i] == (m - vec[i]) && num[m - vec[i]].num < 2)
				continue;
			cout << vec[i] << " " << m - vec[i];
			isFind = true;
			break;
		}
	}
	if (!isFind)
		cout << "No Solution" << endl;
	return 0;
}