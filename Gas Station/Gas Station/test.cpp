#include<bits\stdc++.h>
#include<iostream>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;
int n, m, k, d;
int road[1020][1020], dis[1020];
double avr[1020];
bool vis[1020],isDone = true;
int minWay = -1, minRoot = INF, minAvr = INF;

int read(string s) {
	int v = 0;
	if (s[0] == 'G') {
		for (int i = 1; i < s.size(); i++) {
			v = v *10 + s[i] - '0';
		}
		return v += n;
	}
	else
	{
		for (int i = 0; i < s.size(); i++) {
			v = v * 10 + s[i] - '0';
		}
		return v;
	}
}

void dijkstra(int root) {
	int p = INF;
	dis[root] = 0;
	while (1)
	{
		int a = 0, b = INF;
		for (int i = 1; i <= n + m; i++) {
			if (dis[i] < b && !vis[i]) {
				a = i;
				b = dis[i];
			}
		}
		if (a == 0)
			break;
		vis[a] = true;
		for (int i = 1; i <= n + m; i++) {
			if (!vis[i] && road[a][i] < INF && dis[i] > road[a][i] + dis[a] && road[a][i] + dis[a] <= d) {
				dis[i] = road[a][i] + dis[a];
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] == INF) {
			isDone = false;
		}
		if (dis[i] < p)
			p = dis[i];
		sum += dis[i];
	}
	if (isDone) {
		if (minWay > p)
			return;
		else if (minWay == p && minAvr > sum) {
				minRoot = root;
				minAvr = sum;
		}else if(minWay < p) {
			minWay = p;
			minRoot = root;
			minAvr = sum;
		}
	}
	else return;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	fill(road[0], road[0] + 1020 * 1020, INF);
	cin >> n >> m >> k >> d;
	for (int i = 0; i < k; i++) {
		string a, b;
		int l,r,c;
		cin >> a >> b >> c;
		l = read(a);
		r = read(b);
		if(l != r && c < road[r][l])
			road[l][r] = road[r][l] = c;
	}
	for (int i = n + 1; i <= m + n; i++) {
		isDone = true;
		fill(dis, dis + 1020, INF);
		fill(vis, vis + 1020, false);
		dijkstra(i);
	}
	if (minRoot == INF) {
		cout << "No Solution";
	}
	else
		printf("G%d\n%.1f %.1f", minRoot - n, (float)minWay, (float)(minAvr / (n*1.0)));
	return 0;
}