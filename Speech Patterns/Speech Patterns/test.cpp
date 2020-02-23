#include<bits\stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	string str, ans, tmp;
	map<string, int> mp;
	int num = -1;
	getline(cin, str);
	transform(str.begin(), str.end(), str.begin(),::tolower); // ת��ΪСд
	for (int i = 0; i < str.size(); i++) {
		if ((str[i] >= '0'&& str[i] <= '9') || (str[i] >= 'a'&& str[i] <= 'z')) {
			tmp += str[i];
		}
		else if(tmp.size())
		{
			mp[tmp]++;
			if (mp[tmp] > num) {
				num = mp[tmp];
				ans = tmp;
			}
			if (mp[tmp] == num && tmp < ans) {
				ans = tmp;
			}
			tmp.clear();
		}
	}
	if (tmp.size()) {
		num = 1;
		ans = tmp;
	}
	cout << ans << " " << num << endl;
	return 0;
}