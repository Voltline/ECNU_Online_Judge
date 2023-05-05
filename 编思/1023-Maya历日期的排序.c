#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char months[][20] = {"pop", "no", "zip", "zotz",
        "tzec", "xul", "yoxkin", "mol", "chen",
        "yax", "zac", "ceh", "mac", "kankin",
        "muan", "pax", "koyab", "cumhu", "uayet"};

int find_month(const char* s)
{
    for (int i = 0; i < 20; i++) {
        if (strcmp(s, months[i]) == 0) return i;
    }
}

typedef struct
{
    int year;
    int month;
    int day;
} Date;

int cmp(const void* a, const void* b)
{
    Date d1 = *(Date*)a, d2 = *(Date*)b;
    if (d1.year != d2.year) {
        return d1.year - d2.year;
    }
    else {
        if (d1.month != d2.month) {
            return d1.month - d2.month;
        }
        else return d1.day - d2.day;
    }
    return 0;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int N = 0;
        int temp_day = 0, temp_year = 0;
        char temp_month[20] = {0};
        scanf("%d", &N);
        Date* dates = (Date*)malloc(N * sizeof(Date));
        for (int j = 0; j < N; j++) {
            scanf("%d.", &temp_day);
            scanf("%s", temp_month);
            scanf("%d", &temp_year);
            dates[j].day = temp_day;
            dates[j].month = find_month(temp_month);
            dates[j].year = temp_year;
        }
        qsort(dates, N, sizeof(Date), cmp);
        printf("case #%d:\n", i);
        for (int j = 0; j < N; j++) {
            printf("%d. %s %d\n", dates[j].day, months[dates[j].month], dates[j].year);
        }
        free(dates);
    }
    return 0;
}
