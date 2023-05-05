#include <stdio.h>
#include <string.h>
#define abs(x) ((x) >= 0) ? (x) : -(x)

int gcd(int a, int b) 
{
	if (a % b) return gcd(b, a % b);
	else return b;
}

int find_point(char* num)
{
	for (int i = 0; i < strlen(num); i++) {
		if (num[i] == '.') return i;
	}
	return strlen(num);
}

int TriToDec(char c)
{
	switch (c) {
	case '0': return 0;
	case '1': return 1;
	case '2': return -1;
	}
}

int main()
{
	char tri_num[40] = {0};
	scanf("%s", tri_num);
	int pos = find_point(tri_num);
	long long power = 1;
	long long A = 0, B = 0, C = 1;
	for (int i = pos-1; i >= 0; i--) {
		A += power * TriToDec(tri_num[i]);
		power *= 3;
	}
	if (pos != strlen(tri_num)) {
		for (int j = pos+1; j < strlen(tri_num); j++) {
			B *= 3;
			B += TriToDec(tri_num[j]);
			C *= 3;
		} 
		
		if (A * B < 0) {
			if (B < 0) {
				while (B < 0) {
					A--;
					B += C;
				}
			}
			else {
				B = C - B;
				A++;
			}
		}
		else {
			if (A != 0 && B < 0) B = -B;
		}
		int n = abs(gcd(B, C));
		
		if (A != 0) {
			printf("%lld ", A);
		}
		printf("%lld %lld", B/n, C/n);
	}
	else {
		printf("%lld", A);
	}
	
	return 0;
}