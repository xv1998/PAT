#include<bits\stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m, s, ss = 0;
int weight[101];
vector<int> leaf[101], que;
vector<vector<int>> result;
void recursion(int num, int sum,vector<int> q) {
	q.push_back(num);
	sum += weight[num];
	if (sum > s)
		return;
	if (sum == s && leaf[num].empty()) {
		vector<int> v;
		for (int i = 0; i < q.size(); i++) {
			v.push_back(weight[q[i]]);
		}
		result.push_back(v);
		ss++;
	}
	else if (sum == s && !leaf[num].empty())
		return;
	else {
		for (int i = 0; i < leaf[num].size(); i++)
			recursion(leaf[num][i], sum, q);
	}
	return;

}

bool tmp(vector<int> a,vector<int> b) {
	int length = min(a.size(), b.size());
	int i = 0;
	for (i; i < length; i++) {
		if (a[i] == b[i])
			continue;
		else return a[i] > b[i];
	}
	if (i == length)
		return a.size() > b.size();
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < b; j++) {
			int c;
			cin >> c;
			leaf[a].push_back(c);
		}
	}
	recursion(0, 0, que);
	sort(result.begin(), result.end(), tmp);
	for (int i = 0; i < ss; i++) {
		for (int j = 0; j < result[i].size(); j++) {
			if(j!= result[i].size() - 1)
				printf("%d ", result[i][j]);
			else if(i != ss -1)
				printf("%d\n", result[i][j]);
			else printf("%d", result[i][j]);
		}
	}
	return 0;
}