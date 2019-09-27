#include<iostream>
#include <vector>
using namespace std;
#define num 510
#define max 0x7fffffff

int bikes[num], weight[num], node[num][num]; // 各个站的现有车辆数 // 权值 // 节点信息
bool vis[num]; // 是否被访问
int cap, staNum, proNum, roadNum, ansSend = max, ansTake = max, per;
vector<int>pre[510], temppath, anspath;

void dfs(int tmp) {
	temppath.push_back(tmp);
	if (tmp == 0) { // 回到根节点
		int len = temppath.size(), send = 0, back = 0;
		for (int i = len - 1; i >= 0; i--) {
			int a = per - bikes[temppath[i]];
			if (a < 0) {
				back += a;
			}
			else {
				if ((0 - back) > a)
					back += a;
				else
				{
					send += (a + back);
					back = 0;
				}
			}
		}
		if (send < ansSend) {
			ansSend = send;
			anspath = temppath;
			ansTake = (0 - back);
		}
		else if (send == ansSend && ansTake > back) {
			anspath = temppath;
			ansTake = (0 - back);
		}
		temppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[tmp].size(); i++) { // 对每一条到达v的最短路径进行dfs
		dfs(pre[tmp][i]);
	}
	temppath.pop_back();
}
int main() {
	scanf("%d%d%d%d", &cap, &staNum, &proNum, &roadNum);
	for (int i = 1; i <= staNum; i++) {
		scanf("%d", &bikes[i]);
	};
	for (int i = 0; i < num; i++) {
		vis[i] = false;
	}
	fill(node[0], node[0] + 510 * 510, max); // 初始化二维数组
	fill(weight, weight + 510, max);
	for (int i = 0; i < roadNum; i++) {
		int beg, end;
		scanf("%d%d", &beg, &end);
		scanf("%d", &node[beg][end]);
		node[beg][end] = node[end][beg];
	}
	per = cap / 2;
	weight[0] = 0;
	for (int i = 0; i <= staNum; i++)
	{
		int tmp = -1, min = max;
		for (int j = 0; j <= staNum; j++) {
			if (vis[j] == false && weight[j] < min) {
				min = weight[j];
				tmp = j;
			}
		}
		if (tmp == -1)break;
		vis[tmp] = true;
		for (int r = 0; r <= staNum; r++) {
			if (vis[r] == false && node[r][tmp] != max) {
				if (weight[r] > weight[tmp] + node[tmp][r]) {
					pre[r].clear();
					pre[r].push_back(tmp);
					weight[r] = node[tmp][r] + weight[tmp];
				}
				else if (weight[r] == weight[tmp] + node[tmp][r])
					pre[r].push_back(tmp);
			}
		}
	}
	dfs(proNum);
	printf("%d 0", ansSend);
	for (int i = anspath.size() - 2; i >= 0; i--)
		printf("->%d", anspath[i]);
	printf(" %d", ansTake);
	return 0;
}