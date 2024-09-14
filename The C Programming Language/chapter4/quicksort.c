#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main() {
	int test[] = {1, 23, 3, 412, 2, 6};
	int size = sizeof(test) / sizeof(test[0]);

	qsort(test, 0, size - 1);
	printf("Sorted array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", test[i]);
	}
	printf("\n");
	return 0;
}

void qsort(int v[], int left, int right) {
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)
		return ;

	swap(v, left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (v[i] < v[left]) {
			swap(v, ++left, i);
		}
		swap(v, left, last);
		qsort(v, left, last - 1);
		qsort(v, last + 1, right);
	}
}

void swap(int v[], int i, int j) {
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
