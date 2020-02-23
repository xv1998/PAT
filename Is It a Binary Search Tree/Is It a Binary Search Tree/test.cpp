#include<bits\stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;
int n, pre[1005], minOrder[1005],aft[1005],num1 = 0,num2 = 0, mirror = 1;
bool isTure = true;

bool cmp(int a, int b) {
	return a < b;
}

void isBTS(int first,int last) {
	if (isTure == false || first == last)
		return;
	int root = pre[num1++], length;
	bool tag = false;
	for (int i = first; i < last; i++) {
		if (minOrder[i] == root) {
			length = i;
			tag = true;
			break;
		}
	}
	if (!tag) {
		isTure = false;
		return;
	}
	//if (first == length) {
		//aft[num2++] = minOrder[length];
	//}
	if (mirror == 1) {
		isBTS(first, length);
		isBTS(length + 1, last);
	}
	else if (mirror == 2) {
		isBTS(length + 1, last);
		isBTS(first, length);
	}
	if(isTure == true)
		aft[num2++] = minOrder[length];
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("ouput.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
		minOrder[i] = pre[i];
	}
	sort(minOrder, minOrder + n, cmp);// ÖÐÐò
	isBTS(0, n);
	if (isTure == false && mirror == 1) {
		mirror++;
		isTure = true; num1 = 0, num2 = 0,
		isBTS(0, n);
	}
	if(isTure == false && mirror == 2)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			cout << aft[i];
			if (i != n - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}