#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
struct node
{
	int num, next, key;
};
bool tmp(node a,node b) {
	return a.key < b.key;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int n, start;
	cin >> n >> start;
	vector<node> v;
	map<int,node> r;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		r[a].num = a;
		r[a].key = b;
		r[a].next = c;
	}
	if (start == -1) {
		printf("0 -1");
		return 0;
	}
	for (int i = 0, num = start; num != -1 && i < n; num = r[num].next, i++) {
		v.push_back(r[num]);
	}
	sort(v.begin(), v.end(),tmp);
	printf("%d %05d\n", v.size(), v.front().num);
	for (int i = 0; i < v.size(); i++) {
		if (i != v.size() - 1) {
			printf("%05d %d %05d\n", v[i].num, v[i].key, v[i+1].num);
		}else printf("%05d %d -1", v[i].num, v[i].key);
	}
	return 0;
}