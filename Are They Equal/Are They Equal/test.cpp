#define _CRT_SECURE_NO_WARNINGS
#include<bits\stdc++.h>
#include<iostream>
#include<cmath>

using namespace std;

string change(string s,int &y,int n) {
	int k = 0;
	while (s.length()>0 && s[0] == '0') {
		s.erase(s.begin());
	}
	if (s[0] == '.') {
		s.erase(s.begin());
		while (s.length() > 0 && s[0] == '0') {
			s.erase(s.begin());         //去掉小数点后的非零位前所有0
			y--;
		}
	}
	else {
		while (s.length() > k && s[k] != '.') { //在遇到小数点之前
			k++;
			y++;
		}
		if (k<s.length()) {  
			s.erase(s.begin() + k);   //删除小数点
		}
	}
	if (s.length() == 0)
		y = 0; // x是0
	int num = 0;
	k = 0;
	string res ;
	while (num < n)
	{
		if (k < s.length() && y != 0) {
			res += s[k++];
		}
		else
			res += "0";
		num++;
	}
	return  "0." + res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,tmp1 = 0,tmp2 = 0;
	string a, b, c, d;
	cin >> n >> a >> b;	c = change(a, tmp1, n);	d = change(b, tmp2, n);	if (c == d && tmp1 == tmp2) {		cout << "YES " << c << "*10^" << tmp1 << endl;
	}
	else
		cout << "NO " << c << "*10^" << tmp1 << " " << d << "*10^" << tmp2 << endl;	return 0;}