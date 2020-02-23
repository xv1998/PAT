#include<bits\stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct  node
{
	int rank, id, total = 0 , num = 0;
	vector<int> score;
	bool isRank = false;
};

bool cmp(node a, node b) {
	if (a.total != b.total)
		return a.total > b.total;
	else if (a.num != b.num)
		return a.num > b.num;
	else return a.id < b.id;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int n, m, k;
	int full[7]; // 每题总分
	cin >> n >> k >> m;
	for (int i = 1; i <= k; i++) {
		int a;
		cin >> a;
		full[i] = a;
	}
	vector<node> arr(n + 1);
	for (int i = 1; i <= n; i++)
		arr[i].score.resize(k + 1, -1);
	for (int i = 0; i < m; i++) {
		int id, pro, score;
		cin >> id >> pro >> score;
		arr[id].id = id;
		arr[id].score[pro] = max(arr[id].score[pro], score);
		if (score != -1)
			arr[id].isRank = true; // 对于有编译成功案例的可以显示在排名上
		else if(arr[id].score[pro] == -1)
			arr[id].score[pro] = -2; // 提交了但没编译成功
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (arr[i].score[j] != -1 && arr[i].score[j] != -2)
				arr[i].total += arr[i].score[j];
			if (arr[i].score[j] == full[j])
				arr[i].num++;
		}
	}
	sort(arr.begin()+1, arr.end(),cmp);
	for (int i = 1; i <= n; i++) {
		arr[i].rank = i;
		if (i != 1 && arr[i].total == arr[i - 1].total)
			arr[i].rank = arr[i - 1].rank;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i].isRank == true) {
			printf("%d %05d %d", arr[i].rank, arr[i].id, arr[i].total);
			for (int j = 1; j <= k; j++) {
				if (arr[i].score[j] != -1 && arr[i].score[j] != -2) {
					printf(" %d", arr[i].score[j]);
				}else if(arr[i].score[j] == -1)
					printf(" -");
				else
					printf(" 0");
			}
			printf("\n");
		}
	}
	return 0;
}