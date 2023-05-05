#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* w;
} word;

word vocabulary[510] = {NULL};

int find(const char* s, int size)
{
    for (int i = 0; i < size; i++) {
        if (strcmp(vocabulary[i].w, s) == 0) {
            return i;
        }
    }
    return -1;
}

int cmp(const void* a, const void* b)
{
    word w1 = *(word*)a, w2 = *(word*)b;
    return strcmp(w1.w, w2.w);
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    char input[600] = {0};
    getchar();
    for (int i = 0; i < T; i++) {
        int cnt = 0;
        gets(input);
        int len = strlen(input);
        for (int k = 0; k < len; k++) {
            if (input[k] > 122 || input[k] < 97) {
                if (k != len-1) input[k] = ' ';
            	else input[k] = 0;
			}
        }
        char single[510] = {0};
        char* p = input;
        while (sscanf(p, "%s", single) != EOF) {
            int idx = find(single, cnt);
            if (idx == -1) {
                vocabulary[cnt].w = (char*)malloc((strlen(single)+2) * sizeof(char));
                strcpy(vocabulary[cnt].w, single);
                cnt++;
            }
            p += strlen(single)+1;
        	while (*p == ' ') p++;
        }

        qsort(vocabulary, cnt, sizeof(word), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < cnt; j++) {
            if (j != cnt-1) printf("%s ", vocabulary[j].w);
            else printf("%s", vocabulary[j].w);
            free(vocabulary[j].w);
            vocabulary[j].w = NULL;
        }
        printf("\n");
        memset(input, 0, 600*sizeof(char));
    }
    return 0;
}
