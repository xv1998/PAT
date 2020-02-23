#include<bits\stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int INF = 0x7fffffff;
int n, m, minTmp = INF,num = 0;
bool tag = false;
int all[100005];//前缀和数组
vector<int> nearest;
void binarySearch(int left,int right,int x) {
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (all[mid] - all[x - 1] == m) {
			printf("%d-%d\n", x, mid);
			tag = true;
			return;
		}
		else if (all[mid] - all[x - 1] > m)
			right = mid - 1;
		else left = mid + 1;
	}
	if (left >= right && !tag && left <= n) {
		if ((all[left] - all[x - 1]) < minTmp && (all[left] - all[x - 1]) > m) {
			minTmp = all[left] - all[x - 1];
			num = 0;
			nearest.clear();
			nearest.push_back(x);
			nearest.push_back(left);
			num++;
		}
		else if ((all[left] - all[x - 1]) == minTmp && (all[left] - all[x - 1]) > m) {
			nearest.push_back(x);
			nearest.push_back(left);
			num++;
		}
	}
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	cin >> n >> m;
	fill(all, all + n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		all[i] = tmp + all[i - 1];
	}
	int j = 1;
	nearest.push_back(0);
	nearest.push_back(INF);
	while (j <= n)
	{
		binarySearch(j,n,j);
		j++;
	}
	if (!tag) {
		j = 0;
		while (j != nearest.size())
		{
			printf("%d-%d\n", nearest[j], nearest[j+1]);
			j += 2;
		}
	}
	return 0;
}