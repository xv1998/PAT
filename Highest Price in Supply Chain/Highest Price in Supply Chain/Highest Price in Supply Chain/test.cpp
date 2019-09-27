#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int maxFloor = 0, maxNum = 0, n;
vector<int> vec[100001];

void dfs(int num, int floor) {
	if (vec[num].size() == 0) { // р╤вс╫з╣Ц
		if (floor > maxFloor) {
			maxFloor = floor;
			maxNum = 1;
		}
		else if (floor == maxFloor)
			maxNum++;
		return;
	}
	for (int i = 0; i < vec[num].size(); i++)
		dfs(vec[num][i], floor + 1);
}

int main() {
	int root,tmp;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		if (tmp == -1)
			root = i;
		else
			vec[tmp].push_back(i);
	}
	dfs(root, 0);
	printf("%.2f %d", p * pow(1 + r / 100.0, maxFloor), maxNum);
	return 0;
}