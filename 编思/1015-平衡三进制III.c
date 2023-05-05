#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
ll tri[1000] = {0};
ll temp[1000] = {0};

void Print(int len, int cnt, int rest)
{
    if (len == 1 && tri[0] == 0) printf("0");
    for (int i = 0; i < len; i++) {
        if (i == 0 && tri[i] == 0) continue;
        printf("%lld", tri[i]);
    }
    if (rest != 0) {
        printf(".");
        for (int i = len; i < cnt; i++) {
            printf("%lld", tri[i]);
        }
    }
    printf("\n");
}

ll GCD(ll a, ll b)
{
    if (a % b == 0) return b;
    else return GCD(b, a % b);
}

int main()
{
    ll A = 0, B = 0;
    scanf("%lld%lld", &A, &B);
    int sign = (A*B > 0) ? 1 : (A*B==0) ? 0 : -1;
    if (sign == 1 && A < 0) {
        A *= -1;
        B *= -1;
    }

    if (sign == -1) {
        if (A < 0) A *= -1;
        else B *= -1;
    }

    ll f = GCD(A, B);
    A /= f;
    B /= f;
    ll rest = A % B;
    ll C = A / B; // C for integer, C A/B;

    A %= B;
    int cnt = 0;
    while (C != 0) {
        temp[cnt++] = C % 3;
        C /= 3;
    }
    for (int i = 0; i < cnt; i++) {
        tri[i+1] = temp[cnt - i - 1];
    }
    cnt++;
    int len = cnt;
    ll t = 1;
    for (; B != t; t *= 3) {
        //printf("3 * %lld / %lld = %lld\n", A, B, A*3/B);
        tri[cnt++] = A*3/B;
        if (tri[cnt-1] > 0) {
            A = A*3 - B*tri[cnt-1];
        }
        else {
            A *= 3;
        }
    }
    //Print(len, cnt, rest);
    for (int i = 1; i < cnt; i++) {
        tri[i]++;
    }
    //Print(len, cnt, rest);
    for (int i = cnt-1; i >= 1; i--) {
        if (tri[i] >= 3) {
            tri[i-1]++;
            tri[i] %= 3;
        }
    }
    //Print(len, cnt, rest);
    int start = 1;

    for (; start < cnt; start++) {
        tri[start]--;
        if (tri[start] == -1) tri[start] = 2;
    }

    if (sign == -1) {
        for (int i = 0; i < cnt; i++) {
            if (tri[i] == 1) tri[i] = 2;
            else if (tri[i] == 2) tri[i] = 1;
        }
    }

    Print(len, cnt, rest);
    return 0;
}
