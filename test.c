#include <stdio.h>

#define LEN 10

void InsertSort(int a[], int length) {
	int i, j;
	for (i = 2; i <= length; ++i) {
		if (a[i] > a[i - 1]) {
			a[0] = a[i];
			a[i] = a[i - 1];
			for (j = i - 2; a[0] > a[j]; --j)
				a[j + 1] = a[j];
			a[j + 1] = a[0];
		}
	}
}

void BubbleSort(int a[], int length) {
	int m = length - 1;
	int flag = 1;
	while ((m > 0) && (flag == 1)) {
		flag = 0;
		int t;
		for (int j = 1; j <= m; j++)
			if (a[j] < a[j + 1]) {
				flag = 1;
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		--m;
	}
}

int Partition(int a[], int low, int high) {
	a[0] = a[low];
	int pivotkey = a[low];
	while (low < high) {
		while (low < high && a[high] <= pivotkey)
			--high;
		a[low] = a[high];
		while (low < high && a[low] >= pivotkey)
			++low;
		a[high] = a[low];
	}
	a[low] = a[0];
//    printf("pivotkey = %d: ", pivotkey);
//    for(int j = 1; j <= LEN; ++j)
//    {
//        printf("%d ", a[j]);
//    }
//    printf("\n");
	return low;
}
void QSort(int a[], int low, int high) {
	if (low < high) {
		int pivotkey = Partition(a, low, high);
		QSort(a, low, pivotkey - 1);
		QSort(a, pivotkey + 1, high);
	}
}
void QuickSort(int a[], int length) {
	QSort(a, 1, length);
}

void SelectSort(int a[], int length) {
	for (int i = 1; i < length; ++i) {
		int k = i;
		for (int j = i + 1; j <= length; ++j)
			if (a[j] > a[k])
				k = j;
		int t;
		if (k != i) {
			t = a[i];
			a[i] = a[k];
			a[k] = t;
		}
	}
}

int main() {
	int a[LEN + 1] = { 0, 12, 2, 16, 30, 28, 10, 16, 20, 6, 18 };
	int i;
	printf("原始序列: ");
	for (i = 1; i <= LEN; i++)
		printf("%d ", a[i]);
	printf("\n");
	//InsertSort(a, LEN);
	BubbleSort(a, LEN);
	//QuickSort(a, LEN);
	//SelectSort(a, LEN);
	printf("排序序列: ");
	for (i = 1; i <= LEN; i++)
		printf("%d ", a[i]);
	printf("\n");
	printf("test\n");
	return 0;
}
