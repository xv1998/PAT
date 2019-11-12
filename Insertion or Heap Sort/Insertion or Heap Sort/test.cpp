#include <iostream>
#include <algorithm>

using namespace std;
int part[105], insertArr[105], heap[105];
//int heap[28] = {0, 8, 2, 22, 14, 21, 20, 24, 19, 16, 5 ,18, 13, 10, 23, 9, 11, 17, 26, 3, 4 ,27, 25, 12, 15, 1, 6, 7 };
//int insertArr[28] = {0, 8, 2, 22, 14, 21, 20, 24, 19, 16, 5 ,18, 13, 10, 23, 9, 11, 17, 26, 3, 4 ,27, 25, 12, 15, 1, 6, 7 };
//int part[28] = {0, 17, 16, 15, 14, 12, 10, 13, 11, 3, 7, 4, 6, 5, 1, 9, 2, 8, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
int n;

int is_equal(int arr[], int arr2[]) {
	for (int i = 1; i <= n; i++) {
		if (arr[i] != arr2[i])
			return -1;
	}
	return 1;
}

void insert_sort(int i) {
	int j = i;
	int tmp = insertArr[i];
	while (j > 1 && tmp < insertArr[j - 1]) {
		insertArr[j] = insertArr[j - 1];
		j--;
	}
	insertArr[j] = tmp;
}

void downAdjust(int low, int high) {
	int i = low, j = i * 2;// ×óº¢×Ó
	while (j <= high) {
		if (j + 1 <= high && heap[j + 1]>heap[j]) {
			j += 1;
		}
		if (heap[j] > heap[i]) {
			swap(heap[j], heap[i]);
			i = j;
			j = i * 2;
		}
		else
			break;
	}
}

void create() {
	for (int i = n / 2; i >= 1; --i) {
		downAdjust(i, n);
	}
}
void print_arr(int n, int arr[]) {
	for (int i = 1; i <= n - 1; i++)
		cout << arr[i] << " ";
	cout << arr[n] << endl;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> insertArr[i];
		heap[i] = insertArr[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> part[i];
	}
	create();
	for (int i = 2; i <= n; i++) {
		insert_sort(i);
		if (is_equal(insertArr, part) == 1) {
			insert_sort(++i);
			printf("Insertion Sort\n");
			print_arr(n, insertArr);
			break;
		}

	}
	for (int i = n; i > 1; i--) {
		if (is_equal(heap, part) == 1) {
			swap(heap[i], heap[1]);
			downAdjust(1, i - 1);
			printf("Heap Sort\n");
			print_arr(n, heap);
			break;
		}
		swap(heap[i], heap[1]);
		downAdjust(1, i - 1);
	}

	return 0;
}