#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int all_cnt = 0;

typedef struct
{
    char str[305];
} string;

int find1(const char* s, int start)
{
    int len = strlen(s);
    for (int i = start; i < len-1; i++) {
        if (s[i] == '*' && s[i+1] == '/') return i;
    }
    return -1;
}

int find2(const char* s, int start)
{
    int len = strlen(s);
    for (int i = start; i < len-1; i++) {
        if (s[i] == '"') return i;
    }
    return -1;
}

void erase_comments(string* lines, string* ans, int cnt)
{
    string temp;
    int state = 0;
    // 0 for global
    // 1 for "one line comment //"
    // 2 for "multi lines comment /* */"
    // 3 for string literal ""
    // 3 has the highest priority
    bool next = false, has_insert = false;
    int right = 0;

    for (int i = 0; i < cnt; i++) {
        strcpy(temp.str, lines[i].str);
        int len = strlen(temp.str);
        temp.str[len] = '\n';
        temp.str[++len] = 0;
        next = false;
        has_insert = false;
        for (size_t i = 0; i < len; i++) {
            if (!next) {
                switch (temp.str[i]) {
                case '/':
                    if (temp.str[i + 1] == '/' && state == 0) {
                        state = 1;
                        temp.str[i] = '\n';
                        temp.str[i+1] = 0;
                        has_insert = true;
                        strcpy(ans[all_cnt++].str, temp.str);
                        state = 0;
                        next = true;
                    }
                    else if (temp.str[i + 1] == '*' && state == 0) {
                        state = 2;
                        int u = find1(temp.str, i+2);
                        if (u != -1) {
                            memmove(temp.str+i, temp.str+(u+2), (len - u - 1) * sizeof(char));
                            len -= u-i+2;
                            i--;
                            state = 0;
                        }
                        else {
                            next = true;
                        }
                    }
                    break;
                case '"':
                    if (temp.str[i - 1] != 92) {
                        state = 3;
                        right = find2(temp.str, i+1);
                        if (right < len && right > i && temp.str[right - 1] != 92) {
                            i = right;
                            state = 0;
                        }
                        else if (right < len && right > i && temp.str[right - 1] == 92) {
                            int cnt = 0;
                            for (int i = right - 1; temp.str[i] == 92; i--) cnt++;
                            if (cnt % 2 == 0) {
                                i = right;
                                state = 0;
                            }
                        }
                        else if (right > len) {
                            state = 0;
                        }
                        break;
                    }
                    break;
                case '*':
                    if (temp.str[i + 1] == '/' && state == 2) {
                        memmove(temp.str, temp.str+i+2, (len-i-2) * sizeof(char));
                        temp.str[len-i-2] = 0;
                        len -= i + 2;
						state = 0;
                        i = -1;
                    }
                    break;
                case '\n':
                    if (state == 2) {
                        temp.str[len-2] = 0;
                    }
                    else {
                        strcpy(ans[all_cnt++].str, temp.str);
                        has_insert = true;
                    }
                    break;
                }
            }
            else {
                next = false;
                break;
            }
        }
        if (!has_insert && state == 0) {
            strcpy(ans[all_cnt++].str, temp.str);
            //cout << temp << endl; // TODO
        }
    }
}

int main()
{
    string* lines = (string*)malloc(10000 * sizeof(string));
    int cnt = 0;
    while (gets(lines[cnt++].str) != NULL);
    cnt--;
    string* ans = (string*)malloc(cnt * sizeof(string));
    erase_comments(lines, ans, cnt);

    for (int i = 0; i < all_cnt; i++) {
        printf("%s", ans[i].str);
    }
    return 0;
}
