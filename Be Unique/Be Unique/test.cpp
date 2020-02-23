#include<bits\stdc++.h>
#include<iostream>
#include<map>
using namespace std;

struct node
{
	int show = 0, rank = 0;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int n, tmp = 1,min = -1;
	cin >> n;
	map<int,node> arr;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a].show++;
		if (arr[a].rank == 0)
			arr[a].rank = tmp++;
	}
	map<int, node>::iterator iter;
	for (iter = arr.begin(); iter != arr.end();iter++) {
		if (iter->second.show == 1 && iter->second.rank < tmp) {
			tmp = iter->second.rank;
			min = iter->first;
		}
	}
	if(min != -1)
		cout << min << endl;
	else cout << "None" << endl;
	return 0;
}