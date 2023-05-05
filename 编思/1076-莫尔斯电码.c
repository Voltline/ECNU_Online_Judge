#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char c;
    char code[10];
} Morse;

Morse table[] =
{
    {'A',    ".-"}, {'B',  "-..."}, {'C',  "-.-."},
    {'D',   "-.."}, {'E',     "."}, {'F',  "..-."},
    {'G',   "--."}, {'H',  "...."}, {'I',    ".."},
    {'J',  ".---"}, {'K',   "-.-"}, {'L',  ".-.."},
    {'M',    "--"}, {'N',    "-."}, {'O',   "---"},
    {'P',  ".--."}, {'Q',  "--.-"}, {'R',   ".-."},
    {'S',   "..."}, {'T',     "-"}, {'U',   "..-"},
    {'V',  "...-"}, {'W',   ".--"}, {'X',  "-..-"},
    {'Y',  "-.--"}, {'Z',  "--.."}, {'0', "-----"},
    {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."},
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}
};

char translate(const char* s)
{
    for (int i = 0; i < 36; i++) {
        if (!strcmp(s, table[i].code)) return table[i].c;
    }
}

int find_sep(const char* str, int beg, int len)
{
    for (int i = beg; i < len; i++) {
        if (str[i] == '/') return i;
    }
    return len;
}

void solve(const char* morse)
{
    int len = strlen(morse);
    int i = 0, last = 0;
    while (i < len) {
        char temp[10] = {0};
        last = i;
        i = find_sep(morse, i, len);
        memcpy(temp, morse+last, (i-last) * sizeof(char));
        printf("%c", translate(temp));
        if (i < len && morse[i+1] == '/') {
            int cnt = 0;
            int j = 0;
			for (j = i; j < len; j++) {
                if (morse[j] == '/') cnt++;
                else {
                    i = j-1;
                    break;
                }
            }
            if (j == len) i = j-1;
            if (cnt == 3) printf(" ");
            else printf(".");
        }
        i++;
    }
    printf("\n");
}
// .-///-...///-.-.///-..///.///..-.///--.///....///..///.---///-.-///.-..///--///-.///---///.--.///--.-///.-.///...///-///..-///...-///.--///-..-///-.--///--..///-----///.----///..---///...--///....-///.....///-....///--...///---..///----.///
int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char morse[1200] = {0};
        scanf("%s", morse);
        printf("case #%d:\n", i);
        solve(morse);
    }
    return 0;
}
//morse[
