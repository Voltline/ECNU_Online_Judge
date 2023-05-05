#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// min is for the minimum of dict order
int main()
{
    char s[120] = {0};
    int status[120] = {0};
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len-1; i++) {
        if (s[i+1] > s[i]) status[i] += 1;
        else if(s[i+1] == s[i]) {
        	int start = i;
            for (int j = i+1; j < len; j++) {
                if (s[j] > s[i]) {
                    for (int k = start; k < j; k++) {
                        status[k] += 1;
                    }
                    i = j-1;
                    break;
                }
                else if (s[j] < s[i]) {
                    i = j-1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < len; i++) {
        if (status[i]) printf("%c", s[i]);
        printf("%c", s[i]);
    }
    return 0;
}
