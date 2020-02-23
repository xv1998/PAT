#include<bits\stdc++.h>
#include<iostream>
#include<string>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output,txt", "w", stdout);
#endif // !ONLINE_JUDGE
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int i = s1.size();
	for (int j = 0; j < i; j++) {
		if (s2.find(s1[j]) == -1)
			cout << s1[j];
	}
	return 0;

}