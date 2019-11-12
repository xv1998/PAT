#include<iostream>
#include <cmath>

using namespace std;

int main() {
	int length = 0, n, start = 0;
	int begin;
	cin >> n;
	for (begin = 2; begin < sqrt(n); begin++) {
		if (n % begin == 0) {
			int tmpLen = 0;
			tmpLen++;
			int tmpBe = begin + 1, tmpEnd = n / begin;
			while (tmpEnd % tmpBe == 0) {
				tmpLen++;
				tmpEnd = tmpEnd / tmpBe;
				tmpBe++;
			}
			if (tmpLen > length) {
				length = tmpLen;
				start = begin;
			}
		}
	}
	if (length == 0) {
		length = 1;
		start = n;
	}
	cout << length << endl;
	for (int i = 0; i < length - 1; i++) {
		cout << start++ << "*";
	}
	cout << start << endl;
}