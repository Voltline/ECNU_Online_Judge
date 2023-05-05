#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max(a, b) ((a) > (b)) ? (a) : (b)
typedef struct
{
    int sign;
    int size;
    int digit[1000];
} BigInt;

int sgn(int x)
{
    return (x > 0) ? 1 : (x == 0) ? 0 : -1;
}

int bigger(BigInt* a, BigInt* b)
{
    if (a->sign * b->sign == -1) {
        if (a->sign == 1) return 1;
        else return -1;
    }
    else if (a->sign * b->sign == 0) {
    	if (a->sign == 0) {
        	if (b->sign == 1) return -1;
        	else if (b->sign == 0) return 0;
        	else return 1;
        }
        else if (b->sign == 0) {
        	if (a->sign == 1) return 1;
        	else if (a->sign == 0) return 0;
        	else return -1;
		}
	}
    else {
        if (a->sign == 1) { // a > 0, b > 0
        	if (a->size != b->size) {
        		return sgn(a->size - b->size);
			}
			else {
				for (int i = a->size-1; i >= 0; i--) {
					if (a->digit[i] > b->digit[i]) return 1;
					else if (a->digit[i] < b->digit[i]) return -1;
				}
				return 0;
			}
		}
		else { // a < 0, b < 0
        	if (a->size != b->size) {
        		return -sgn(a->size - b->size);
			}
			else {
				for (int i = a->size-1; i >= 0; i--) {
					if (a->digit[i] > b->digit[i]) return -1;
					else if (a->digit[i] < b->digit[i]) return 1;
				}
				return 0;
			}
		}
    }
}

void strToBigInt(const char* s, BigInt* b)
{
	memset(b->digit, 0, 1000*sizeof(int));
	b->size = 1;
	b->sign = 0;
	int beg = 0;
    if (s[0] == '-') {
    	b->sign = -1;
		beg = 1;
	}
    else if (s[0] != '0') b->sign = 1;
    else b->sign = 0;

    int len = strlen(s);
    int cnt = 0;
    for (int i = len-1; i >= beg; i--) {
        b->digit[cnt++] = s[i] - '0';
    }
    b->size = cnt;
}

void Add(BigInt* a, BigInt* b, BigInt* ans)
{
	ans->sign = 0;
	memset(ans->digit, 0, 1000 * sizeof(int));
	ans->size = 1;
    if ((a->sign) * (b->sign) == -1) {
        BigInt temp_b = *b;
        temp_b.sign *= -1;
        Minus(a, temp_b, ans);
        if (a->sign == -1) {
            ans->sign *= -1;
        }
    }
    else if ((a->sign) * (b->sign) == 1) {
        *ans = *a;
        for (int i = 0; i < b->size; i++) {
            ans->digit[i] += b->digit[i];
        }
        int max_size = Max(ans->size, b->size);
        ans->size = max_size;
        for (int i = 0; i < max_size; i++) {
            if (ans->digit[i] >= 10) {
                ans->digit[i+1] += ans->digit[i] / 10;
                ans->digit[i] %= 10;
            }
        }
        if (ans->digit[max_size] != 0) ans->size++;
        if (a->sign == -1) ans->sign = -1;
    }
    else {
        if (a->sign == 0) {
            *ans = *b;
            ans->sign = -1;
        }
        else {
            *ans = *a;
        }
    }
}

void Minus(BigInt* a, BigInt* b, BigInt* ans)
{
	memset(ans->digit, 0, 1000*sizeof(int));
	ans->sign = 0;
	ans->size = 1;
	if ((a->sign) * (b->sign) == -1) {
		BigInt temp_b = *b;
		temp_b.sign *= -1;
		Add(a, &temp_b, ans);
	}
	else {
		BigInt temp_a = *a, temp_b = *b;
		temp_a.sign = 1, temp_b.sign = 1;
		BigInt _left, _right;
		int check = bigger(&temp_a, &temp_b);
		if (check == 1 || check == -1) {
        	if (check == 1) {
        		_left = *a;
                _right = *b; // Ignore the (+-), just process the array
                if (a->sign == 1) ans->sign = 1;
                else ans->sign = -1;
			}
			else {
        		_left = *b;
                _right = *a; // Ignore the (+-), just process the array
				if (a->sign == 1) ans->sign = -1;
				else ans->sign = 1;
			}

            for (int i = 0; i < _left.size; i++) {
                ans->digit[i] = _left.digit[i] - _right.digit[i];
            }
            ans->size = _left.size;
            for (int i = 0; i < _left.size-1; i++) {
                if (ans->digit[i] < 0) {
                    ans->digit[i+1]--;
                    ans->digit[i] += 10;
                }
            }
            int i = 999;
            for (; i >= 1; i--) {
                if (ans->digit[i] != 0) break;
            }
            ans->size = i+1;
		}
		else if (check == 0) {
            memset(ans->digit, 0, 1000 * sizeof(int));
            ans->sign = 0;
            ans->size = 1;
		}
	}
}

void Multiply(BigInt* a, int b)
{
    if (b < 0) a->sign = -1 * a->sign;
    for (int i = 0; i < a->size; i++) {
        a->digit[i] *= b;
    }

    int carry = 0, size = a->size;
    for (int i = 0; i < 999; i++) {
        a->digit[i+1] += a->digit[i] / 10;
        a->digit[i] %= 10;
    }
	
	int i = 999;
	for (; i >= 0; i--) {
		if (a->digit[i] != 0) {
			break;
		}
	}
	a->size = i+1;
}

void Pow(BigInt* b, int a, int n)
{
    if (n == 0) {
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            Multiply(b, a);
        }
    }
}

void Print(BigInt* a)
{
    if (a->sign == -1) printf("-");
    for (int i = a->size-1; i >= 0; i--) {
        printf("%d", a->digit[i]);
    }
    printf("\n");
}

int cnt_zero(const BigInt* b)
{
    int cnt = 0;
    for (int i = 0; i < b->size; i++) {
        if (b->digit[i] != 0) {
        	cnt = i;
			break;	
		}
    }
    return cnt;
}

void Factorial(BigInt* b, int t)
{
    memset(b->digit, 0, 1000 * sizeof(int));
    b->digit[0] = 1;
    b->sign = 0;
    b->size = 1;
    for (int i = 1; i <= t; i++) {
        Multiply(b, i);
    }
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N = 0;
        scanf("%d", &N);
        BigInt b;
        Factorial(&b, N);
        printf("case #%d:\n%d\n", i, cnt_zero(&b));
    }
    return 0;
}
