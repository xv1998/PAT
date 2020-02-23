#include<bits\stdc++.h>
#include<iostream>
using namespace std;
int num;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("ouput.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	cin >> num;
	for (int i = 0; i < num; i++) {
		long double a, b, c;
		cin >> a >> b >> c;
		if(a + b > c)
			cout << "Case #" << i + 1 << ": true" << endl;
		else
			cout << "Case #" << i + 1 << ": false" << endl;
	}
	return 0;
}