#include<bits\stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;

int nodes[2001], tree[2001];
int num,pos = 0;
int tmp(int a,int b) {
	return a < b;
}

void build(int a) {
	if (a > num) return; // 为最后的结点
	int left = a * 2, right = a * 2 + 1;
	build(left);
	tree[a] = nodes[pos++];
	build(right);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("ouput.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> nodes[i];
	}
	sort(nodes, nodes + num, tmp);
	build(1);
	for (int i = 1; i < num+1; i++) {
		cout << tree[i];
		if (i != num) cout << " ";
	}
	return 0;
}