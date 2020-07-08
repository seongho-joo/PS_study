#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	int arr[1000];
	int cnt, temp;
	
	printf("ют╥б . . .");
	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &arr[i]);
	}

	temp = 0;

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < cnt; i++)
		printf("%d\n", arr[i]);
}