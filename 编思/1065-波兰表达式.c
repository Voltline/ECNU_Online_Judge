#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isOP(const char* s)
{
    int len = strlen(s);
    if (len == 1 && (s[0] < '0' || s[0] > '9')) {
        return 1;
    }
    return 0;
}

double PN()
{
    char op[20] = {0};
    scanf("%s", op);
    if (isOP(op)) {
        double A = 0, B = 0;
        A = PN();
        B = PN();
        switch (op[0]) {
        case '+': return A+B;
        case '-': return A-B;
        case '*': return A*B;
        case '/': return A/B;
        }
    }
    else {
        return atof(op);
    }
    return 0.0;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; i++) {
        printf("case #%d:\n%.6f\n", i, PN());
    }
    return 0;
}
