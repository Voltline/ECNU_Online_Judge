#include <stdio.h>
#include <stdlib.h>
int A_size = 0, B_size = 0;
int A[510] = {0}, B[510] = {0};

int find(int r, int A_size)
{
    for (int i = 0; i < A_size; i++) {
        if (A[i] == r) return i;
    }
    return -1;
}

int cmp(const void* a, const void* b)
{
    int a1 = *(int*)a, b1 = *(int*)b;
    int ia = find(a1, A_size), ib = find(b1, A_size);
    if (ia != -1 && ib != -1) {
        return ia - ib;
    }
    else {
        if (ia == ib) {
            return a1 - b1;
        }
        else if (ia == -1) {
            return 1;
        }
        else {
            return -1;
        }
    }
}

int main()
{
    scanf("%d", &A_size);
    for (int i = 0; i < A_size; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &B_size);
    for (int i = 0; i < B_size; i++) {
        scanf("%d", &B[i]);
    }
    qsort(B, B_size, sizeof(int), cmp);
    for (int i = 0; i < B_size; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
    return 0;
}
