#include<iostream>
#include<bits\stdc++.h>
#include<vector>
#include<cmath>
using namespace std;
struct node{
	int value;
	int coe = 0;
};
vector<node> nodes;

int nextPrime(long int x) {
	bool flag = true;
	while (flag)
	{
		x++;
		int i = 2;
		for (; i <= sqrt(x); i++) {
			if (x % i == 0) {
				flag = true;
				break;
			}
		}
		if (i > sqrt(x)) flag = false;
	}
	return x;
}

void countNum(int x) {
	int a = sqrt(x), b = 2,tmp = x;
	node p;
	while (b <= a)
	{
		if (tmp%b == 0) {
			int i = 0;
			for (; i < nodes.size(); i++) {
				if (nodes[i].value == b){
					nodes[i].coe += 1;
					break;
				}
			}
			if (i >= nodes.size()) {
				p.coe = 1;
				p.value = b;
				nodes.push_back(p);
			}
			tmp = tmp / b;
			b = 2; a = sqrt(tmp);
		}else{
			b = nextPrime(b);
		}
	}
	if (tmp != 0) {
		int i = 0;
		for (; i < nodes.size(); i++) {
			if (nodes[i].value == tmp) {
				nodes[i].coe += 1;
				break;
			}
		}
		if (i >= nodes.size()) {
			p.coe = 1;
			p.value = tmp;
			nodes.push_back(p);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;	if (n == 1) cout << "1=1";	else
	{
		cout << n << "=";		countNum(n);		for (int i = 0; i < nodes.size(); i++) {			cout << nodes[i].value;			if (nodes[i].coe != 1) {				cout << "^" << nodes[i].coe;			}			if (i < nodes.size() - 1) cout << "*";		}
	}	system("pause");
	return 0;
}