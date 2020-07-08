#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

int main() {
	int N, tmp = 1;
	scanf("%d", &N);

	int i = 0;
	
	while (1) {
		tmp += (6 * i);
		if (N <= tmp)
			break;
		i++;
	}

	printf("%d\n", i+1);
}