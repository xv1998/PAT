#include<iostream>
#include <algorithm>
#include <string>
#include<string.h>
#include<vector>

using namespace std;

struct car
{
	char name[50];
	int time;
	int status;
}t[10010];
int n, k,max_time = 0,max_num = 0,tmp = 0;
vector<car> valid,max_car;

bool compare(car a, car b) {
	if (strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
	else return a.time < b.time;
}
bool compare_stay(car a, car b) {
	return a.time < b.time;
}
int count(int time) {
	if (tmp == valid.size()) return max_num;
	while (valid[tmp].time <= time) {
		if (valid[tmp].status) max_num++;
		else max_num--;
		tmp++; if (tmp == valid.size()) break;
	}
	return max_num;
}
bool cmp_M(car a,car b) {
	return strcmp(a.name,  b.name) < 0;
}
void Cul_Time(int M) {
	int h, m, s;
	s = M % 60;     M /= 60;
	m = M % 60;     h = M / 60;
	printf("%02d:%02d:%02d\n", h, m, s);
}
int main() {
	int hh, mm, ss;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		char str[5];
		scanf("%s %d:%d:%d %s", t[i].name, &hh, &mm, &ss, str);
		if (strcmp(str, "in") == 0) t[i].status = 1;
		else t[i].status = 0;
		t[i].time = hh * 3600 + mm * 60 + ss;
	}
	sort(t, t + n, compare);
	// 清理数据
	for (int i = 0; i < n - 1; i++) {
		while (strcmp(t[i].name, t[i + 1].name) == 0) {
			if (t[i].status == 1 && t[i + 1].status == 0) {
				valid.push_back(t[i]);
				valid.push_back(t[i + 1]);
			}
			i++;
			if (i + 1 == n)   break;
		}
	}
	// 查找停留时间最大值
	for (int i = 0; i < valid.size() -1; i++) {
		int time = 0;
		while (strcmp(valid[i].name, valid[i + 1].name) == 0) {
			if (valid[i + 1].status == 0 && valid[i].status == 1) {
				int tmp = valid[i + 1].time - valid[i].time;
				time += tmp;
			}
			i++;
			if (i + 1 == valid.size())    break;
		}
		if (time > max_time) {
			max_time = time;
			max_car.clear();
			max_car.push_back(valid[i]);
		}
		else if (time == max_time) {
			max_car.push_back(valid[i]);
		}
	}
	// 按时间排序
	sort(valid.begin(), valid.end(), compare_stay);
	for (int i = 0; i < k; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int time = hh * 3600 + mm * 60 + ss;
		printf("%d\n", count(time));
	}
	sort(max_car.begin(), max_car.end(), cmp_M);
	for (int i = 0; i < max_car.size(); i++) {
		printf("%s ", max_car[i].name);
	}
	Cul_Time(max_time);
	system("pause");
	return 0;
}