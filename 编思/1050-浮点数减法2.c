#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define SIZE 502

typedef struct
{
    int In_Cnt;
    int De_Cnt;
    int In[SIZE];
    int De[SIZE];
    int sign;
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
    memset(dec->De, 0, SIZE * sizeof(int));
    memset(dec->In, 0, SIZE * sizeof(int));
    dec->sign = 1;
    int start = 0;
    if (!isdigit(str[0])) {
        if (str[0] != '.') {
            start = 1;
            if (str[0] == '-') dec->sign = -1;
            else dec->sign = 1;
        }
    }
    int loc = find_p(str), len = strlen(str);
    if (loc != -1) {
        dec->In_Cnt = (loc >= 1) ? loc : 1;
        dec->De_Cnt = len - loc - 1;
        int cnt = 0;
        for (int i = loc-1; i >= start; i--) {
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
        for (int i = len-1; i >= start; i--) {
            dec->In[cnt++] = toDigit(str[i]);
        }
    }
}

Decimal pure_add(const Decimal* d1, const Decimal* d2)
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
    for (int i = SIZE-1; i >= 0; i--) {
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
	for (int i = SIZE-1; i >= 0; i--) {
        if (ans.In[i] != 0) {
            ans.In_Cnt = i+1;
            break;
        }
    }
    return ans;
}

Decimal pure_minus(const Decimal* d1, const Decimal* d2)
{
    Decimal ans = *d1;
    for (int i = 0; i < d2->De_Cnt; i++) {
        ans.De[i] -= d2->De[i];
    }

    for (int i = 0; i < d2->In_Cnt; i++) {
        ans.In[i] -= d2->In[i];
    }

    for (int i = d2->De_Cnt-1; i >= 1; i--) {
        if (ans.De[i] < 0) {
            ans.De[i-1]--;
            ans.De[i] += 10;
        }
    }
    if (ans.De[0] < 0) {
        ans.In[0]--;
        ans.De[0] += 10;
    }

    for (int i = 0; i < SIZE; i++) {
        if (ans.In[i] < 0) {
            ans.In[i] += 10;
            ans.In[i+1]--;
        }
    }
    ans.In_Cnt = 1;
    for (int i = SIZE-1; i >= 0; i--) {
        if (ans.In[i] != 0) {
            ans.In_Cnt = i+1;
            break;
        }
    }
    return ans;
}

int Compare(const Decimal* d1, const Decimal* d2)
{
    // return  1 -> d1  > d2
    // return  0 -> d1 == d2
    // return -1 -> d1  < d2
    if (d1->sign * d2->sign == 1) {
        if (d1->In_Cnt != d2->In_Cnt) {
            if (d1->sign == -1) {
                if (d1->In_Cnt > d2->In_Cnt) return -1;
                else return 1;
            }
            else {
                if (d1->In_Cnt > d2->In_Cnt) return 1;
                else return -1;
            }
        }
        else {
            int ret = 0;
            for (int i = d1->In_Cnt-1; i >= 0; i--) {
                if (d1->In[i] > d2->In[i]) {
                    ret = 1;
                    break;
                }
                else if (d1->In[i] < d2->In[i]) {
                    ret = -1;
                    break;
                }
            }
            if (ret != 0) return ret * d1->sign; // |a| > |b| -> 1, a < b -> 1 * (-1) = -1
            else {
                int max_de_size = max(d1->De_Cnt, d2->De_Cnt);
                for (int i = 0; i < max_de_size; i++) {
                    if (d1->De[i] > d2->De[i]) {
                        ret = 1;
                        break;
                    }
                    else if (d1->De[i] < d2->De[i]) {
                        ret = -1;
                        break;
                    }
                }
                return ret * d1->sign;
            }
        }
    }
    else {
        if (d1->sign == 1) return 1;
        else return -1;
    }
}

Decimal Add(const Decimal* d1, const Decimal* d2)
{
    if (d1->sign * d2->sign == 1) {
        return pure_add(d1, d2);
    }
    else {
        Decimal d1_in = *d1, d2_in = *d2;
        d1_in.sign = 1, d2_in.sign = 1;
        int cmp = Compare(&d1_in, &d2_in);
        if (cmp == 1) {
            if (d1->sign == 1) {
                return pure_minus(&d1_in, &d2_in);
            }
            else {
                Decimal ans = pure_minus(&d1_in, &d2_in);
                ans.sign *= -1;
                return ans;
            }
        }
        else if (cmp == 0) {
            Decimal ans = {1, 0, {0}, {0}, 1};
            return ans;
        }
        else {
            if (d1->sign == 1) {
                Decimal ans = pure_minus(&d2_in, &d1_in);
                ans.sign *= -1;
                return ans;
            }
            else {
                return pure_minus(&d2_in, &d1_in);
            }
        }
    }
    return pure_add(d1, d2);
}

Decimal Minus(const Decimal* d1, const Decimal* d2)
{
    if (d1->sign * d2->sign == 1) {
        if (d1->sign == 1) {
            int cmp = Compare(d1, d2);
            if (cmp == 1) {
                return pure_minus(d1, d2);
            }
            else if (cmp == 0) {
                Decimal ans = {1, 0, {0}, {0}, 1};
                return ans;
            }
            else {
                Decimal ans = pure_minus(d2, d1);
                ans.sign *= -1;
                return ans;
            }
        }
        else {
            Decimal d1_in = *d1, d2_in = *d2;
            d1_in.sign = 1, d2_in.sign = 1;
            int cmp = Compare(&d1_in, &d2_in);
            if (cmp == 1) {
                Decimal ans = pure_minus(&d1_in, &d2_in);
                ans.sign *= -1;
                return ans;
            }
            else if (cmp == 0) {
                Decimal ans = {1, 0, {0}, {0}, 1};
                return ans;
            }
            else {
                return pure_minus(&d2_in, &d1_in);
            }
        }
    }
    else {
        if (d1->sign == 1) {
            Decimal d2_in = *d2;
            d2_in.sign = 1;
            return pure_add(d1, &d2_in);
        }
        else {
            Decimal d1_in = *d1, d2_in = *d2;
            d1_in.sign = 1, d2_in.sign = 1;
            Decimal ans = pure_add(&d1_in, &d2_in);
            ans.sign *= -1;
            return ans;
        }
    }
}

void Print(const Decimal* dec, int T)
{
    if (dec->sign == -1) putchar('-');
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
    char str[SIZE] = {0}, str2[SIZE] = {0};
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

// 24571276581.512589
// 10119911111.119111
// 30
// 9999999999.999999999999999999 -213.99999999 10
