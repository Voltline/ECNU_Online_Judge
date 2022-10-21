#include <stdio.h>
#include <math.h>
int isFalseNum(int n);
int main()
{
    for(int i = 0; i < 10000; i++) {
        if (isFalseNum(i)) {
            printf("%d\n",i);
        }
    }
    return 0;    
}
int isFalseNum(int n)
{
    int ans = 0;
    int digit[5] = {0};
    int cnt = 0, temp_n = n; 
    while (temp_n > 9) {
        temp_n /= 10;
        cnt++;
    }
    cnt++;
    temp_n = n;
    for (int i = 0; i < cnt; i++) {
        digit[4 - i] = temp_n % 10;
        temp_n /= 10;
    }
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += pow(digit[i], 4);
    }
    if (sum == n) {
        ans = 1;
    }
    return ans;
    
}
