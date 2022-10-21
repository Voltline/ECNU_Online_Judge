#include <stdio.h>

int main()
{
    char a;
    do {
        scanf("%c", &a);
        if ((int)a <= 122 && (int)a >= 97) {
            printf("%c", a - 32);
        }
        else {
            printf("%c", a);
        }
    } while (a != '\n');
    return 0;
}