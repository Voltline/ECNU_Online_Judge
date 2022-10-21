#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int compare_abs(const void* e1, const void* e2);
int main()
{
    int n = 0, nums[100] = {0}, temp = 0;
    while (scanf("%d", &n) != -1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            nums[i] = temp;
        }
        qsort(nums, n, sizeof(int), compare_abs);
        printf("%d",nums[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d",nums[i]);
        }
    }
    return 0;
}

int compare_abs(const void* e1, const void* e2)
{
    return abs(*(int*)e1) - abs(*(int*)e2);
}