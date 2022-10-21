#include <stdio.h>

int count(char* string);

int main()
{
    int ans;
    char a[1024];
    while (scanf("%s", a) != -1) {
        printf("%d\n",count(a));
    }
    return 0;
}

int count(char* string)
{
    int ans = 0;
    int i = 0;
    while (string[i] != '\0') {
        i++;
        ans++;
    }
    return ans;
}