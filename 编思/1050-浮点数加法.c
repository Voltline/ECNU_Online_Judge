#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b)) ? (a) : (b)

typedef struct
{
    int In_Cnt;
    int De_Cnt;
    int In[502];
    int De[502];
} Decimal;

int find_p(const char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') return i;
    }
    return -1;
}

int toDigit(char c)
{
    return c - '0';
}

void strToDecimal(const char* str, Decimal* dec)
{
    // printf("str = %s\n", str);
    memset(dec->De, 0, 502 * sizeof(int));
    memset(dec->In, 0, 502 * sizeof(int));
    int loc = find_p(str), len = strlen(str);
    if (loc != -1) {
        dec->In_Cnt = (loc >= 1) ? loc : 1;
        dec->De_Cnt = len - loc - 1;
        int cnt = 0;
        for (int i = loc-1; i >= 0; i--) {
            dec->In[cnt++] = toDigit(str[i]);
        }
        cnt = 0;
        for (int i = loc+1; i < len; i++) {
            dec->De[cnt++] = toDigit(str[i]);
        }
    }
    else {
        dec->In_Cnt = len;
        dec->De_Cnt = 1;
        int cnt = 0;
        for (int i = len-1; i >= 0; i--) {
            dec->In[cnt++] = toDigit(str[i]);
        }
    }
}

Decimal Add(const Decimal* d1, const Decimal* d2)
{
    Decimal ans = *d1;
    for (int i = 0; i < d2->De_Cnt; i++) {
        ans.De[i] += d2->De[i];
    }
    
    for (int i = 0; i < d2->In_Cnt; i++) {
        ans.In[i] += d2->In[i];
    }
    
    int max_De_size = max(d1->De_Cnt, d2->De_Cnt);
    for (int i = max_De_size-1; i >= 1; i--) {
        if (ans.De[i] >= 10) {
            ans.De[i-1] += ans.De[i] / 10;
            ans.De[i] %= 10;
        }
    }
    if (ans.De[0] >= 10) {
        ans.In[0] += ans.De[0] / 10;
        ans.De[0] %= 10;
    }
    for (int i = 501; i >= 0; i--) {
        if (ans.De[i] != 0) {
            ans.De_Cnt = i+1;
            break;
        }
    }

    int max_In_size = max(d1->In_Cnt, d2->In_Cnt);
    for (int i = 0; i < max_In_size; i++) {
        if (ans.In[i] >= 10) {
            ans.In[i+1] += ans.In[i] / 10;
            ans.In[i] %= 10;
        }
    }
	for (int i = 501; i >= 0; i--) {
        if (ans.In[i] != 0) {
            ans.In_Cnt = i+1;
            break;
        }
    }
    return ans;
}

void Print(const Decimal* dec, int T)
{
    Decimal temp = *dec;
    if (temp.De[T] >= 5) {
        temp.De[T-1]++;
        temp.De[T] /= 10;
    }
    temp.De_Cnt = T;
    for (int i = T-1; i >= 1; i--) {
        if (temp.De[i] >= 10) {
            temp.De[i-1] += temp.De[i] / 10;
            temp.De[i] %= 10;
        }
    }
    if (temp.De[0] >= 10) {
        temp.In[0] += temp.De[0] / 10;
        temp.De[0] %= 10;
    }
    for (int i = 0; i < temp.In_Cnt; i++) {
        if (temp.In[i] >= 10) {
            temp.In[i+1] += temp.In[i] / 10;
            temp.In[i] %= 10;
        }
    }
    if (temp.In[temp.In_Cnt] != 0) {
        temp.In_Cnt++;
    }

    for (int i = temp.In_Cnt-1; i >= 0; i--) {
        printf("%d", temp.In[i]);
    }
    printf(".");
    for (int i = 0; i < temp.De_Cnt; i++) {
        printf("%d", temp.De[i]);
    }
    printf("\n");
}

int main()
{
    char str[520] = {0}, str2[520] = {0};
    scanf("%s", str);
    scanf("%s", str2);
    int N = 0;
    scanf("%d", &N);
    Decimal d1, d2;
    strToDecimal(str, &d1);
    strToDecimal(str2, &d2);
    Decimal ans = Add(&d1, &d2);
    Print(&ans, N);
    return 0;
}
