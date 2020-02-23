#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct node
{
	int arr, wait = 0,vip = 0,play,id = -1;
};
struct table {
	int time = 28800, id, num = 0,isVip = 0;
}tab[101];
bool tmp(node a, node b) {
	return a.arr <= b.arr;
}
bool tmp2(table a,table b) {
	if (a.time == b.time)
		return a.id < b.id;
	return a.time < b.time;
}
bool tmp3(table a, table b) {
	return a.id < b.id;
}
bool tmp4(node a, node b) {
	return a.id <b.id;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int n, tables, vipN, pid = 0;;
	int openT = 28800, closeT = 75600;
	cin >> n;
	vector<node> people;
	for (int i = 0; i < n; i++) {
		int h, m, s;
		node a;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &a.play, &a.vip);
		if (a.play > 120)
			a.play = 120;
		a.arr = h * 3600 + m * 60 + s;
		if (a.arr < openT || a.arr >= closeT)
			continue;
		people.push_back(a);
	}
	cin >> tables >> vipN;
	n = people.size();
	for (int i = 0; i < tables; i++) {
		tab[i].id = i;
	}
	for (int i = 1; i <= vipN; i++) {
		int a;
		cin >> a;
		tab[a - 1].isVip = 1;
	}
	sort(people.begin(), people.end(), tmp);
	bool isout = false;
	int i = 0;
	while(!isout && i< n){
		sort(tab, tab + tables, tmp2);
		if (tab[0].time > closeT || tab[0].time + people[i].play * 60 > closeT) {
			isout = true;
			break;
		}
		else {
			vector<int> vipArrTime, minTables;
			if (i != 0) {
				for (int j = 1; j < tables; j++) {
					if (tab[j].time == tab[0].time)
						minTables.push_back(j);
				}
			}
			if (!minTables.empty()) {
				for (int j = 0; j < minTables.size(); j++) {
					if (tab[minTables[j]].isVip == 1) {
						table a = tab[0];
						tab[0] = tab[minTables[j]];
						tab[minTables[j]] = a;
						sort(tab + 1, tab + tables, tmp2);
					}
				}
			}
			if (people[i].arr < tab[0].time && people[i].vip == 0 && tab[0].isVip == 1) { //来的时候没有空位置,且最短时间的桌子是vip桌子
				for (int j = i,tmp = 0; j < n && tmp < tables; j++) {
					if (people[j].arr <= tab[tmp].time && people[j].vip == 1) {
						vipArrTime.push_back(j);
						tmp++;
					}
				}
				if (people[vipArrTime[0]].arr > tab[0].time) { //后面没有vip
					people[i].wait = tab[0].time - people[i].arr;
					people[i].id = people[i].id == -1? pid++: people[i].id;
					tab[0].time += (people[i].play * 60);
					tab[0].num++;
				}
				else
				{//后面有vip，寻找第一个非vip抢占位
					for (int j = 0,tmp = 0; j < tables; j++, tmp++) {
						if (tab[j].isVip == 0 || tab[j].time < people[vipArrTime[tmp]].arr) {
							people[i].wait = tab[j].time - people[i].arr;
							people[i].id = people[i].id == -1 ? pid++ : people[i].id;
							tab[j].time += (people[i].play * 60);
							tab[j].num++;
						}
						else {
							people[vipArrTime[tmp]].id = people[vipArrTime[tmp]].id == -1 ? pid++ : people[vipArrTime[tmp]].id;
						}
					}
				}
			}
			else if(people[i].arr < tab[0].time && tab[0].isVip == 0){//来的时候没有空位置,但最短时间的是普通桌子
				people[i].wait = tab[0].time - people[i].arr;
				people[i].id = people[i].id == -1 ? pid++ : people[i].id;
				tab[0].time += (people[i].play * 60);
				tab[0].num++;
			}
			else if(people[i].arr >= tab[0].time && people[i].vip == 1){//来的时候有空位置，但是他是vip
				bool isFind = false;
				for (int j = 0; j < tables; j++) {
					if (tab[j].isVip == 1 && tab[j].time < people[i].arr) {
						tab[j].time = people[i].arr + (people[i].play * 60);
						people[i].id = people[i].id == -1 ? pid++ : people[i].id;
						tab[j].num++;
						isFind = true;
						break;
					}
				}if (!isFind) {// 空闲桌子没有vip桌子
					tab[0].time += people[i].arr + (people[i].play * 60);
					people[i].id = people[i].id == -1 ? pid++ : people[i].id;
					tab[0].num++;
				}
			}
			else {
				tab[0].time = people[i].arr + (people[i].play * 60);
				people[i].id = people[i].id == -1 ? pid++ : people[i].id;
				tab[0].num++;
			}
		}
		i++;
	}
	sort(tab, tab + tables, tmp3);
	sort(people.begin(), people.end(), tmp4);
	for (int i = 0; i < n; i++) {
		printf("%02d:%02d:%02d ", people[i].arr / 3600, (people[i].arr % 3600) / 60, people[i].arr % 60);
		printf("%02d:%02d:%02d ", (people[i].arr + people[i].wait) / 3600, ((people[i].arr + people[i].wait) % 3600) / 60, (people[i].arr + people[i].wait) % 60);
		int min = people[i].wait % 60;
		if (min >= 30)
			printf("%d\n", people[i].wait / 60 + 1);
		else printf("%d\n", people[i].wait / 60);
	}
	for (int i = 0; i < tables; i++) {
		cout << tab[i].num;
		if (i != tables - 1) printf(" ");
	}
	return 0;
}