#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct Data {
	char str[51];
	int len;
}Data;

int compare(const void *d1, const void *d2) {
	Data *a = (Data *)d1, *b = (Data *)d2;
	if (a->len != b->len)
		return a->len - b->len;
	else {
		for (int i = 0; i < a->len; i++) {
			if (a->str[i] == b->str[i])
				continue;
			else
				return (int) (a->str[i] - b->str[i]);
		}
	}
	return 0;
}

int main() {
	int num;
	scanf("%d", &num);
	Data *data = (Data*)malloc(sizeof(Data) * num);

	for (int i = 0; i < num; i++) {
		scanf("%s", &data[i].str);
		data[i].len = strlen(data[i].str);
	}

	qsort(data, num, sizeof(Data), compare);

	for (int i = 0; i < num; i++) {
		int cnt = 0;
		if (strcmp(data[i].str, data[i + 1].str)) printf("%s\n", data[i].str);
	}
}