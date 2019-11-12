#include <iostream>
#include<algorithm>
#include<queue>

using  namespace std;

int arr[105];
int n, k = 0;

typedef struct node {
	int left, right, parent, child = 0, num;
}Nodes;
Nodes tree[105];

void create(int root) {
	if (root == -1) return;
	create(tree[root].left);
	tree[root].num = arr[k++];
	create(tree[root].right);
}
void bfs() {
	queue<int> q;
	q.push(0);
	while (!q.empty()){
		int tmp = q.front();
		q.pop();
		if (tree[tmp].left!= -1)
			q.push(tree[tmp].left);
		if (tree[tmp].right!= -1)
			q.push(tree[tmp].right);
		cout << tree[tmp].num;
		if (!q.empty()) cout << " ";
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tree[i].left >> tree[i].right;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n); 
	create(0);
	bfs();
	system("pause");
	return 0;
}