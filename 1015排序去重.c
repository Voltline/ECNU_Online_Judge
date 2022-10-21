#include <stdio.h>
#include <stdlib.h>
int compare_A(const void* e1, const void* e2);
int compare_D(const void* e1, const void* e2);
int main()
{
	char choice = '\0';
	scanf("%c", &choice);
	int temp = 0, nums[100] = {0}, cnt = 0;
	while (scanf("%d", &temp) != -1) {
		nums[cnt] = temp;
		cnt++;
	}
	if (choice == 'A') {
		qsort(nums, cnt, sizeof(int), compare_A);
	}
	else {
		qsort(nums, cnt, sizeof(int), compare_D);
	}
	int temp_cnt = cnt;
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (nums[j] == nums[i]) {
				nums[j] = 0;
				temp_cnt--;
			}	
			else {
				break;
			}
		}
	}
	for (int i = 0; i < cnt; i++) {
		if (temp_cnt != 1) {
			if (nums[i] != 0) {
				printf("%d ", nums[i]);
			}
		}
		else {
			printf("%d", nums[i]);
		}
	}
	
	return 0;
}
int compare_A(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int compare_D(const void* e1, const void* e2)
{
	return *(int*)e2 - *(int*)e1;
}