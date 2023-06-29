#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void read_complex(char* str, long long* a, long long* b)
{
	long long t[2] = {0, 0};
	int cnt = 0;
    int len = strlen(str);
    if (str[len-1] != 'i') {
        *a = atoll(str);
        *b = 0;
        return ;
    }
    else if (str[len-1] == 'i' && (len == 1 || !isdigit(str[len-2]))) {
    	if (len == 1) {
    		*a = 0;
    		*b = 1;
    		return ;
		}
		else {
			if (str[len-2] == '+') {
				*b = 1;
			}
			else {
				*b = -1;
			}
			str[len-2] = 0;
			*a = atoll(str);
			return ;
		}
	}
    else {
        long long temp = 0, sign = 1;
        for (int i = 0; i < len; i++) {
            if (i == 0 && str[i] == '-') {
                sign = -1;
            }
            else {
                if (isdigit(str[i])) {
                    temp = temp * 10 + (str[i] - '0');
                }
                else {
                    t[cnt++] = temp * sign;
                    temp = 0;
                    sign = 1;
                    if (str[i] == '-') sign = -1;
                }
            }
        }
    }
    if (cnt == 2) {
		*a = t[0];
		*b = t[1];
	}
	else {
		if (str[len-1] == 'i') *b = t[0];
		else *a = t[0];
	}
}

void solve(long long a, long long b)
{
	char ans[10001] = {0};
	int cnt = 0;
	long long ta = a, tb = b, r = 0;
	if (a == 0 && b == 0) {
		printf("0\n");
		return ;
	}
	while (!(a == 0 && b == 0)) {
		if ((a+b) % 2 == 0) {
			ans[cnt++] = '0';
			tb = -1*(a+b)/2;
			ta = b + tb;
		}
		else {
			ans[cnt++] = '1';
			tb = -1*(a+b-1)/2;
			ta = b + tb;
		}
		a = ta;
		b = tb;
	}
	for (int i = cnt-1; i >= 0; i--) {
		putchar(ans[i]);
	}
}

int main()
{
    long long a = 0, b = 0;
    char s[120] = {0};
    scanf("%s", s);
    read_complex(s, &a, &b);
//    printf("a = %lld, b = %lld\n", a, b);
    solve(a, b);
    return 0;
}
