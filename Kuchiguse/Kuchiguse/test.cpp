/*求最长公共子串*/
#include<iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;
int n;

int main() {
	cin >> n;
	vector<string> s;
	string ss;
	string res;
	getline(cin, res);
	int minlen = 256;
	for (int i = 0; i < n; i++) {
		getline(cin, ss);
		s.push_back(ss);
		reverse(s[i].begin(), s[i].end());
		if (s[i].size() < minlen)
			minlen = s[i].size();
	}
	bool flag = true;
	string str;
	for (int i = 0; i < minlen; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (s[j][i] != s[j + 1][i]){
				flag = false;
				break;
			}
		}
		if (!flag) {
			break;
		}
		str += s[0][i];
	}
	reverse(str.begin(), str.end());
	if (str.size() == 0) {
		cout << "nai" << endl;
	}else {
		cout << str << endl;
	}
	system("pause");
	return 0;
}