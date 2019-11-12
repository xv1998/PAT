#include<bits\stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct mice {
	int num;
	int weight;
	int rank = 0;
}m[1005];

int np, ng;
queue<mice> q;
vector<mice> v;

bool tmp(mice a,mice b) {
	return a.weight > b.weight;
}
void find() {
	int a = 0, c = np,k;
	k = (c % ng == 0 ? 0 : 1) + c / ng;
	mice b;
	while (!q.empty()){
		for (int i = 0; i < ng && a < c; i++) {
			b = q.front();
			v.push_back(b);
			q.pop();
			a++;
		}
		if (c == 1) {
			v[0].rank = 1;
			m[v[0].num] = v[0];
			break;
		}
		sort(v.begin(), v.end(),tmp);
		for (int j = 0; j < v.size(); j++) {
			v[j].rank = k+1;
			m[v[j].num] = v[j];
		}
		q.push(v.front());
		v.clear();
		if (a == c) {
			a = 0;
			c = q.size();
			k = (c % ng == 0 ? 0 : 1) + c / ng;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a;
	cin >> np >> ng;
	for (int i = 0; i < np; i++) {
		cin >> a;
		m[i].weight = a;
		m[i].num = i;
	}
	for (int i = 0; i < np; i++) {
		cin >> a;
		q.push(m[a]);
	}
	find();
	for (int i = 0; i < np; i++) {
		if(i == 0)
			cout << m[i].rank;
		else
			cout << " " << m[i].rank;
	}
	return 0;
}