#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) return 1;
    return 0;
}

unsigned int toDigit(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    else {
        return c - 'a' + 10;
    }
}

int main()
{
    char str[100320] = {0};
    scanf("%s", str);
    long long ans = -1;
    int status = 0;
    int cnt = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (i < len-2 && str[i] == '0' && str[i+1] == 'x') {
            if (check(str[i+2])) {
                status = 1;
                i++;
                ans = 0;
            }
            else if (status == 1) {
                ans *= 16;
                i++;
            }
        }
        else if (status == 1 && check(str[i])) {
            ans *= 16;
            ans += toDigit(str[i]);
        }
        else if (status == 1 && !check(str[i])) {
            status = 0;
            printf("%lld ", ans);
            ans = -1;
            cnt++;
        }
        else if (status == 0 && !check(str[i])) {

        }
    }
    if (ans != -1) {
        cnt++;
        printf("%lld ", ans);
    }
    if (cnt == 0) printf("-1");
    return 0;
}
