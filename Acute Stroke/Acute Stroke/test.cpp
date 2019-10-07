#include <iostream>
#include <queue>
using namespace std;

struct point
{
	int x;
	int y;
	int z;
}node;
// 代表xyz坐标
int dx[6] = { 1,0,0,-1,0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };
int m,n,l,t;
int map[1300][130][70];
bool vis[1300][130][70];

bool check(int x, int y, int z) {
	if (x >= m || x<0 || y >= n || y<0 || z >= l || z<0) return false;
	if (map[x][y][z] == 0 || vis[x][y][z] == true) return false;
	return true;
}

int bfs(int i,int j,int k) {
	int num = 0;
	vis[i][j][k] = true;
	queue<point> q;
	node.x = i; node.y = j; node.z = k;
	q.push(node);
	while (!q.empty()){
		point first = q.front(); //获取第一个元素
		q.pop();
		num++;
		for (int m = 0; m < 6; m++) {
			int nx = first.x + dx[m];
			int ny = first.y + dy[m];
			int nz = first.z + dz[m];
			if (check(nx, ny, nz)) {
				node.x = nx; node.y = ny; node.z = nz;
				q.push(node);
				vis[nx][ny][nz] = true;
			}
		}
	}
	if (num >= t) return num;
	else return 0;
}

int main() {
	int ans = 0;
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for (int k = 0; k<l; k++)
			for (int i = 0; i<m; i++)
				for (int j = 0; j<n; j++)
					scanf("%d", &map[i][j][k]);
	for (int k = 0; k < l; k++)
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (map[i][j][k] == 1 && vis[i][j][k] == false)
					ans+=bfs(i, j, k);
	printf("%d", ans);
	system("pause");
	return 0;
}