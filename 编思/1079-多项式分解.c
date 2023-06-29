#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int gcd(int a, int b)
{
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

void readpoly(char *s, int* co)
{
    while (*s) {
        int sign=1,coef=0,dim=0;
        if (*s=='+') s++;
        else if (*s=='-') sign=-1,s++;
        while (isdigit(*s)) { coef=coef*10+*s-'0'; s++; }
        if (coef==0) coef=1;
        if (*s!='x') { co[0]=coef*sign; return; } else s++;
        if (*s=='^') s++;
        while (isdigit(*s)) { dim=dim*10+*s-'0'; s++; }
        if (dim==0) dim=1;
        co[dim]=coef*sign;
    }
}


int main()
{
    int coef[5] = {0};
    char str[100] = {0};
    scanf("%s", str);
    readpoly(str, coef);
    int a = coef[2], b = coef[1], c = coef[0];
    int delta = b * b - 4 * a * c;
    int delta_sqrt = (int)sqrt(delta);
    if (delta_sqrt * delta_sqrt == delta) {
        int fz1 = -b + delta_sqrt, fz2 = -b - delta_sqrt;
        int fm1 = 2 * a, fm2 = 2 * a;
        int gcd1 = gcd(fz1, fm1);
        fz1 /= gcd1;
        fm1 /= gcd1;
        int gcd2 = gcd(fz2, fm2);
        fz2 /= gcd2;
        fm2 /= gcd2;
        int a1 = fm1, c1 = -fz1, a2 = fm2, c2 = -fz2;
        if (a1 < 0) {
        	a1 = -a1;
        	c1 = -c1;
		}
		if (a2 < 0) {
        	a2 = -a2;
        	c2 = -c2;
		}
        if (a1 <= a2) {
            if (a1 == a2) {
				if (c1 <= c2) {
					printf("%d %d %d %d\n", a1, c1, a2, c2);
				}
				else printf("%d %d %d %d\n", a2, c2, a1, c1);
            }
            else printf("%d %d %d %d\n", a1, c1, a2, c2);
        }
        else {
			printf("%d %d %d %d\n", a2, c2, a1, c1);
        }
    }
    else {
        printf("No Answer!\n");
    }
    return 0;
}
