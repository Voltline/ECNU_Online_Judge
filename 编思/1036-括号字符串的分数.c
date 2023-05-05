#include <stdio.h>
#include <string.h>
int top = 0;
typedef struct
{
    int data[60];
} stack;

void Push(stack* s, int i)
{
    s->data[top++] = i;
}

void Pop(stack* s)
{
    top--;
}

int Top(stack* s)
{
	if (top > 0)
		return s->data[top-1];
	else return -2;
}

int main()
{
    char s1[60] = {0};
    scanf("%s", s1);
    stack s;
    for (int i = 0; i < 60; i++) s.data[i] = 0;
    int len = strlen(s1);
    for (int i = 0; i < len; i++) {
        if (s1[i] == '(') {
            Push(&s, -1);
        }
        else {
            int temp = 0;
            if (Top(&s) != -1) {
                while (Top(&s) != -1) {
                    temp += Top(&s);
                    Pop(&s);
                }
                temp *= 2;
                Pop(&s);
                Push(&s, temp);
            }
            else {
                Pop(&s);
                Push(&s, 1);
            }
        }
    }
    
    if (top != 1) {
    	int temp = 0;
		while (top != 0) {
	    	temp += Top(&s);
	    	Pop(&s);
		}
		Push(&s, temp);
	}

	
    printf("%d\n", Top(&s));
    return 0;
}
