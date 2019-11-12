#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

const int MAX = 100000;
typedef struct nodes
{
	int key, next;
}Nodes;
int ex[MAX];
Nodes node[MAX];
int main() {
	int firstAdd, n,addr,deletes[MAX],comfirm[MAX];
	int i = 1,a = 0,b = 0;
	cin >> firstAdd >> n;
	for (i = 0; i < n; i++) {
		int index;
		cin >> index;
		cin >> node[index].key >> node[index].next;
	}
	for (addr = firstAdd; addr != -1; addr = node[addr].next) {
		int key = abs(node[addr].key);
		if (ex[key] == 1) {
			deletes[a++] = addr;
		}
		else {
			ex[key] = 1;
			comfirm[b++] = addr;
		}
	}
	for (i = 0; i < b; i++) {
		printf("%05d %d ", comfirm[i], node[comfirm[i]].key);
		if (i != b - 1) printf("%05d\n", comfirm[i + 1]);
		else printf("-1\n");
	}
	for (i = 0; i < a; i++) {
		printf("%05d %d ", deletes[i], node[deletes[i]].key);
		if (i != a - 1) printf("%05d\n", deletes[i + 1]);
		else printf("-1\n");
	}
	system("pause");
	return 0;
}