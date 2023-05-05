#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int f[30] = {0, 1}, g[30] = {0, 1};
    for (int i = 2; i < 21; i++) {
        f[i] = f[i-1] + g[i-1];
        g[i] = f[i] - g[i-2];
    }
    int in = 0;
    while (scanf("%d", &in)) {
        if (in != -1) printf("%d\n", f[in] + g[in]);
        else break;
    }
}
