#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;
vector<int> map[1005], userId;
queue<int> q;
int n, level, flag[1005];

void bfs(int root) {
	int lev = 0, count = -1;
	q.push(root);
	flag[root] = 1;
	while (!q.empty()){
		int tmp = q.front();
		q.pop();
		count++;
		if (!map[tmp].empty() && flag[tmp] < (level + 1)) {
			for (int i = map[tmp].size() - 1; i >= 0; i--)
				if (flag[map[tmp][i]] == 0) {
					q.push(map[tmp][i]);
					flag[map[tmp][i]] = flag[tmp] + 1;
				}
		}
	}
	cout << count << endl;
}

int main() {
	int k, a, b;
	cin >> n >> level;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		while (a--) {
			cin >> b;
			map[b].push_back(i);
		}
	}
	cin >> k;
	while (k--) {
		cin >> a;
		memset(flag, 0, sizeof(flag));
		bfs(a);
	}
	system("pause");
	return 0;
}