#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isMeasurable(int* w, int n, int target)
{
    int x[] = {-1, 1, 0};
    int ans = 0;
    if (target == 0) return 1;
    if (n == 0) return 0;
    for (int i = 0; i < 3; i++) {
        ans = isMeasurable(w+1, n-1, target+x[i] * (*w));
        if (ans == 1) return 1;
    }
    return 0;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int w[10] = {0};
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", w+i);
        sum += *(w+i);
    }
    for (int i = 1; i <= sum; i++) {
        printf("%d", isMeasurable(w, n, i));
    }
    return 0;
}
