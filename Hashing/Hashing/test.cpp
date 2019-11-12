#include<iostream>
#include<vector>

using namespace std;
int MSize, n, step;
int k[10000];

bool prime() {
	if (MSize <= 1) {
		return false;
	}
	if (MSize == 2) {
		return true;
	}else{
		for (int i = 2; i < MSize; i++) {
			if (MSize % i == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int a;
	cin >> MSize >> n;
	while (!prime()) {
		MSize++;
	}
	for (int i = 0;  i < n; i++) {
		cin >> a;
		for(step = 0; step < MSize / 2; step++){
			int b = (a + step * step) % MSize;
			if (k[b] != 1) {
				k[b] = 1;
				cout << b ;
				break;
			}
		}
		if (step >= (MSize / 2)) cout << "-";
		if(i != n -1) cout << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
