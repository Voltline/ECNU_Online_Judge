#include <stdio.h>
#include <string.h>

/*  cases
    0 for outer
    1 for {}
    2 for []
    3 for ()
*/
int stack[123] = {0};
int pc = 0;

void Push(int c)
{
    stack[pc++] = c;
}

int Top()
{
    return stack[pc-1];
}

void Pop()
{
	stack[pc-1] = 0;
    pc--;
}

int toSave(char c)
{
    switch (c) {
    case '{': return 1;
    case '[': return 2;
    case '(': return 3;
    }
    return -1;
}

int check(const char* str)
{
	pc = 0;
	memset(stack, 0, 123 * sizeof(int));
    int len = strlen(str);
    if (len % 2 != 0) {
        return 0;
    }
    else {
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                Push(toSave(str[i]));
            }
            else {
                int t = Top();
                switch (str[i]) {
                case '{':
                    if (t == 0 || t == 3) {
                        Push(toSave(str[i]));
                        break;
                    }
                    else return 0;
                case '[':
                    if (t == 0 || t == 1) {
                        Push(toSave(str[i]));
                        break;
                    }
                    else return 0;
                case '(':
                    if (t == 0 || t == 2) {
                        Push(toSave(str[i]));
                        break;
                    }
                    else return 0;
                case ')':
                    if (t == 3) {
                        Pop();
                        break;
                    }
                    else return 0;
                case ']':
                    if (t == 2) {
                        Pop();
                        break;
                    }
                    else return 0;
                case '}':
                    if (t == 1) {
                        Pop();
                        break;
                    }
                    else return 0;
                }
            }
        }
        if (pc == 0) return 1;
        else return 0;
    }
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        char s[120] = {0};
        scanf("%s", s);
        printf(check(s) ? "Yes\n" : "No\n");
    }
    return 0;
}
