#include <stdio.h>
#include <math.h>
int isPrime(int n);
int getPrimeCnts(int a, int b);
int main()
{
    int N = 0, M = 0;
    while (scanf("%d %d", &N, &M) != -1) {
        printf("%d\n", getPrimeCnts(N, M));
    }
    return 0;
}

int isPrime(int n)
{
    int ans = 1;
    if (n == 1) {
    	ans = 0;
	}
	else {
		for (int i = 2; i < (int)sqrt(n) + 1; i++) {
		    if (n % i == 0) {
		        ans = 0;
		        break;
		    }
		}
	}

    return ans;
}

int getPrimeCnts(int a, int b)
{
    int ans = 0;
    for (int i = a; i < b; i++) {
        if (isPrime(i)) {
            ans++;
        }
    }
    return ans;
}