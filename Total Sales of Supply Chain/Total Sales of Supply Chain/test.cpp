#include<iostream>
#include <iomanip>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;
int n, visit[100005];
double orprice, race;
queue<int> q;
vector<int> k[100005];

void bfs() {
	visit[0] = 0;
	double result = 0.0;
	q.push(0);
	while (!q.empty()){
		int tmp = q.front();
		q.pop();
			if (k[tmp][0] != 0) {
				for (int i = k[tmp].size() - 1; i >= 0; i--) {
					q.push(k[tmp][i]);
					visit[k[tmp][i]] = visit[tmp] + 1;
				}
			}else{
				result += k[tmp][1]*orprice*pow(race, visit[tmp]);
			}
	}
	printf("%.1f", result);
}

int main() {
	int a, b;
	cin >> n >> orprice >> race;
	race = 1 + race / 100;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			k[i].push_back(b);
		}
		if (a == 0) {
			k[i].push_back(0);
			cin >> b;
			k[i].push_back(b);
		}
	}
	bfs();
	system("pause");
	return 0;
}