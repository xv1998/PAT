/*树状数组*/
#include<bits\stdc++.h>
#include<iostream>
#include<cstring>
#include<stack>
#define lowbit(i) ((i) & (-i))

using namespace std;
const int MAX = 100001;

stack<int> sta;
int n, c[MAX];
void update(int x, int v) {
	for (int i = x; i < MAX; i += lowbit(i)) {
		c[i] += v;
	}
}
int getsum(int x) {
	// 返回小于x的数出现的个数
	int sum = 0;
	for (int i = x; i > 1; i -= lowbit(i)) {
		sum += c[i];
	}
	return sum;
}
void PeekMedian() {
	int left = 1, right = MAX, mid, k = (sta.size() + 1) / 2;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (getsum(mid) >= k) {
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << left << endl;
}
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int a;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "Pop") {
			if (sta.empty()) {
				cout << "Invalid\n";
			}
			else {
				update(sta.top(), -1);
				cout << sta.top() << "\n";
				sta.pop();
			}
		}
		else if (s == "PeekMedian") {
			if (!sta.empty())
				PeekMedian();
			else
				printf("Invalid\n");
		}
		else {
			cin >> a;
			sta.push(a);
			update(a, 1);//出现次数+1
		}
	}
	return 0;
}