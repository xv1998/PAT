#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int tree[110][110];
int n, m, lev = 1, num = 1, maxlev = 1;
queue<int> map;


void bfs() {
	map.push(1);
	int cnum = 0;
	int a = 1;
	while (!map.empty()) {
		for (int j = 0; j < a; j++) {
			int tmp = map.front();
			map.pop();
			for (int i = 1; i <= n; i++) {
				if (tree[tmp][i] == 1) {
					map.push(i);
					cnum++;
				}
			}
		}
		lev++;
		if (cnum > num) {
			num = cnum;
			maxlev = lev;
		}
		a = cnum;
		cnum = 0;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		for (int j = 0; j < b; j++) {
			int c;
			scanf("%d", &c);
			tree[a][c] = 1;
		}
	}
	bfs();
	printf("%d %d",num, maxlev);
	system("pause");
	return 0;
}