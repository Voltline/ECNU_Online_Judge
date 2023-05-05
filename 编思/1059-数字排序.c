#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int pos;
    int beg;
    int sgn;
    char s[120];
} FLOAT;

int find_point(const char* s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '.') return i;
    }
    return -1;
}

int cmp(const void* a, const void* b)
{
    FLOAT f1 = *(FLOAT*)a, f2 = *(FLOAT*)b;
    if (f1.sgn ^ f2.sgn == 1) {
        return f2.sgn - f1.sgn;
    }
    else {
        if (f1.pos - f1.beg != f2.pos - f2.beg) {
        	if (f1.sgn == 1) {
        		return f1.beg + f2.pos - f1.pos - f2.beg;
			}
			else return f1.pos - f1.beg - f2.pos + f2.beg;
        }
        else {
            if (f1.sgn == 1) {
                return -strcmp(f1.s+f1.beg, f2.s+f2.beg);
            }
            else return strcmp(f1.s+f1.beg, f2.s+f2.beg);
        }
    }
}

int main()
{
    FLOAT floats[200];
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", floats[i].s);
        int pos = find_point(floats[i].s);
        floats[i].pos = (pos != -1) ? pos : strlen(floats[i].s);
        if (floats[i].s[0] == '-') {
            floats[i].beg = 1;
            floats[i].sgn = 1;
        }
        else if (floats[i].s[0] == '+') {
            floats[i].beg = 1;
            floats[i].sgn = 0;
        }
        else {
            floats[i].sgn = 0;
        }
    }
    
    qsort(floats, n, sizeof(FLOAT), cmp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", floats[i].s);
    }
    return 0;
}
