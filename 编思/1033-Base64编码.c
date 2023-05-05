#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Base64Char(int c)
{
	if (c >= 0 && c <= 25) {
		return 'A' + c;
	}
	else if (c >= 26 && c <= 51) {
		return 'a' + (c - 26);
	}
	else if (c >= 52 && c <= 61) {
		return '0' + (c - 52);
	}
	else if (c == 62) return '+';
	else return '/';
}

char toBase64Char(int bit_set[], int beg)
{
    int i = bit_set[beg];
    for (int j = 1; j < 6; j++) {
        i <<= 1;
        i += bit_set[beg+j];
    }
    return Base64Char(i);
}

void toBase64(const char* str)
{
    int bit_set[1000] = {0}; // only contains 0 & 1
    int len = strlen(str);
    int i = 0;
    for (int j = 0; j < len; j++) {
        for (int u = 0; u < 8; u++) {
            bit_set[j * 8 + 7 - u] = (str[j] >> u) & 1;
        }
    }
    int bit_set_len = len * 8;
    if (bit_set_len % 6 != 0) {
	    for (int j = 0; j < (6 - bit_set_len % 6); j++) {
	        bit_set[bit_set_len + j] = 0;
	    }
 		bit_set_len += 6 - bit_set_len % 6;
	}
	
    for (int j = 0; j < bit_set_len; j += 6) {
        printf("%c", toBase64Char(bit_set, j));
    }
    if ((bit_set_len / 6) % 4 != 0) {
        for (int i = 0; i < 4 - ((bit_set_len / 6) % 4); i++) {
            printf("=");
        }
    }
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char str[120] = {0};
        scanf("%s", str);
        printf("case #%d:\n", i);
        toBase64(str);
        printf("\n");
    }
    return 0;
}
