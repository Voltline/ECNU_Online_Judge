#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
ll ans[1500] = {0};
ll cnt = 0;
typedef struct
{
    int sign;
    int size;
    int digit[120];
} BigInt;

BigInt Add(BigInt* a, int r)
{
    BigInt ans = *a;
    ans.digit[0] += r;
    if (ans.size == 0) ans.size++;
    for (int i = 0; i < ans.size; i++) {
        if (ans.digit[i] >= 10) {
            ans.digit[i+1] += ans.digit[i] / 10;
            ans.digit[i] %= 10;
            if (i == ans.size-1) ans.size++;
        }
    }
    return ans;
}

int MOD2(const BigInt* a)
{
    return a->digit[0] % 2;
}

BigInt DIV2(BigInt* a)
{
    BigInt ans = *a;
    int carry = 0;
    if (ans.digit[ans.size-1] < 2) {
        carry = 1;
        ans.digit[ans.size-1] = 0;
        ans.size--;
    }
    for (int i = ans.size-1; i >= 0; i--) {
        int t = carry * 10 + ans.digit[i];
        ans.digit[i] = t / 2;
        carry = t % 2;
    }
    return ans;
}

BigInt DIV(BigInt* a)
{
    BigInt temp = DIV2(a);
    if (a->sign == 0) {
        temp.sign = 1;
    }
    else {
        int r = MOD2(a);
        temp.sign = 0;
        temp = Add(&temp, r);
    }
    return temp;
}

void toBin(BigInt* a)
{
    int r = 0;
    BigInt temp = *a;
	while (temp.size >= 1) {
		r = MOD2(&temp);
		temp = DIV(&temp);
		ans[cnt++] = (int)r;
	}
	// if (temp.digit[0] != 0) ans[cnt++] = 1;
	
	for (ll i = cnt-1; i >= 0; i--) {
		printf("%lld", ans[i]);
	}
}

void strToBigInt(const char* s, BigInt* a)
{
    int begin = 0;
    if (s[0] == '-') {
        begin = 1;
        a->sign = 1;
    }
    int len = strlen(s);
    int c = 0;
    for (int i = len-1; i >= begin; i--) {
        a->digit[c++] = s[i] - '0';
    }
    a->size = c;
}

void Print(BigInt* a)
{
	if (a->sign == 1) printf("-");
	for (int i = a->size-1; i >= 0; i--) {
		printf("%d", a->digit[i]);
	}
	printf("\n");
}

int main()
{
    char s[120] = {0};
    scanf("%s", &s);
	BigInt s1 = {0, 1, {0}};
    strToBigInt(s, &s1);
    //Print(&s1);
	//printf("%lld / %lld = %lld ... %lld", s, -2ll, Div(s), Mod(s));
	if (s1.size == 1 && s1.digit[0] == 0) printf("0\n");
	else toBin(&s1);
	return 0;
}
