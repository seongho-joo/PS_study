#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define MAX  1000000

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int cnt;
	scanf("%d", &cnt);
	int *arr = (int *)malloc(sizeof(int) * cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, cnt, sizeof(int), compare);

	for (int i = 0; i < cnt; i++)
		printf("%d\n", arr[i]);
}