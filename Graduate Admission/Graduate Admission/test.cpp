#include<iostream>
#include<bits\stdc++.h>
#include<algorithm>
#include<vector>

using namespace std;
int n, m, k;
int quota[101];
struct nodes{
	int ge, gt,num;
	double fin;
}node[40005];
vector<int> preSchool[40005],admit[101];

bool cmp(nodes a,nodes b) {
	if (a.fin > b.fin)
		return true;
	else if (a.fin == b.fin && a.ge > b.ge) {
		return true;
	}else {
		return false;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	nodes demo[40005];
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a;
		quota[i] = a;
	}
	for (int i = 0; i < n; i++) {
		int c, d;
		cin >> c >> d;
		node[i].num = i;
		node[i].ge = c; node[i].gt = d;
		node[i].fin = double(c + d) / 2.0;
		for (int j = 0; j < k; j++) {
			cin >> b;
			preSchool[i].push_back(b);
		}
	}
	for (int i = 0; i < n; i++)
		demo[i] = node[i];
	// mergeSort(node, 0, n);
	sort(node, node + n, cmp);
	for (int i = 0; i < n; i++) {
		int pernum = node[i].num;
		for (int j = 0; j < preSchool[pernum].size(); j++) {
			a = quota[preSchool[pernum][j]];
			if (a > 0 || i == 0) {
				admit[preSchool[pernum][j]].push_back(pernum);
				quota[preSchool[pernum][j]] = --a;
				break;
			}
			if ((node[i].fin == demo[admit[preSchool[pernum][j]].back()].fin) && (node[i].ge == demo[admit[preSchool[pernum][j]].back()].ge)) {
				admit[preSchool[pernum][j]].push_back(node[i].num);
				break;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (admit[i].size() == 0) {
			printf("\n");
		}else{
			sort(admit[i].begin(), admit[i].end());
			for (int j = 0; j < admit[i].size(); j++) {
				if (j != 0) printf(" ");
				printf("%d", admit[i][j]);
			}
			if (i != (m - 1)) printf("\n");
		}
	}
	system("pause");
	return 0;
}