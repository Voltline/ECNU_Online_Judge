#include <stdio.h>
#include <stdlib.h>
int compare(const void* e1, const void* e2);
int main()
{
    int n = 0, year[30], year_temp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &year_temp);
        year[i] = year_temp;
    }
    qsort(year, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) {
        printf("%d\n",year[i]);
    }
    return 0;
}

int compare(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}