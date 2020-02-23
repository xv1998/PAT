#include<bits\stdc++.h>
#include<iostream>

using namespace std;
int arr[100005],result = 0,n;

int getNum(int tmp) {
	return arr[tmp];
}

void swap(int num) {
	if (arr[num] != 0) {
		int tmp = getNum(num);
		arr[num] = num;
		result++;
		if (arr[tmp] != tmp) {
			swap(tmp);
		}
	}
	else {
		arr[num] = num;
		return;
	}
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[a] = i;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] != i) {
			if(i!=0)
				result++;
			swap(i);
		}
	}
	cout << result << endl;
	return 0;
}