#include <stdio.h>
#include <string.h>

typedef unsigned long long int ull;

#define SIZE 500

typedef struct {
	int cnt, v[SIZE];
} BIGINT;

void printBIG(BIGINT b) {
	for (int i = 0; i < b.cnt; i++)
		printf("%d", b.v[b.cnt - 1 - i]);
	printf("\n");
}

BIGINT int2BIG(int x) {
	BIGINT r = {0, {0}};
	int flag = 0; //对0特判，但是没做0的add和mul
	while (x) {
		r.v[r.cnt++] = x % 10;
		x /= 10;
		flag = 1;
	}
	if (flag == 0) r.cnt = 1;
	return r;
}

BIGINT string2BIG(char *s) {
	BIGINT r = {0, {0}};
	r.cnt = strlen(s);
	for (int i = 0; i < r.cnt; i++)
		r.v[r.cnt - 1 - i] = s[i] - '0';
	return r;
}

BIGINT mul(BIGINT S, BIGINT T) {
	if (S.cnt == 0 || T.cnt == 0)
		return int2BIG(0);
	BIGINT R = {S.cnt + T.cnt, {0}};
	for (int i = 0; i < T.cnt; i++) {
		int t, k, j;
		int carry = 0;
		for (j = 0; j < S.cnt; j++) {
			t = S.v[j] * T.v[i] + carry + R.v[i + j];
			R.v[i + j] = t % 10;
			carry = t / 10;
		}
		k = i + j;
		while (carry) {
			t = carry + R.v[k];
			R.v[k] = t % 10;
			carry = t / 10;
			k++;
		}
	}
	if (R.v[S.cnt + T.cnt - 1] == 0)
		R.cnt--;
	return R;
}

BIGINT add(BIGINT S, BIGINT T) {
	BIGINT R = {0, {0}};
	int i, carry = 0;
	for (i = 0; i < S.cnt && i < T.cnt; i++) {
		int temp = (S.v[i] + T.v[i] + carry);
		R.v[i] = temp % 10;
		carry = temp / 10;
	}
	while (i < S.cnt) {
		int temp = S.v[i] + carry;
		R.v[i++] = temp % 10;
		carry = temp / 10;
	}
	while (i < T.cnt) {
		int temp = T.v[i] + carry;
		R.v[i++] = temp % 10;
		carry = temp / 10;
	}
	if (carry)
		R.v[i++] = carry % 10;
	R.cnt = i;
	return R;
}

//ull hash[101] = {0};
BIGINT hash[101];


void DP()
{
	for (int i = 0; i < 101; i++) {
		if (i <= 1)
			//hash[i] = 1;
			hash[i] = int2BIG(1);
		else if (i == 2)
			//hash[i] = 2;
			hash[i] = int2BIG(2);
		else if (i == 3)
			//hash[i] = 4;
			hash[i] = int2BIG(4);
		else if (i == 4)
			//hash[i] = 8;
			hash[i] = int2BIG(8);
		else {
			//hash[i] = hash[i - 1] + hash[i - 2] + hash[i - 3] + hash[i - 4];
			BIGINT r1 = add(hash[i - 1], hash[i - 2]);
			BIGINT r2 = add(hash[i - 3], hash[i - 4]);
			hash[i] = add(r1, r2);
		}
	}
}

// one dp
void solve(int a, int b, int x1, int y1, int x2, int y2)
{
    DP();
    if (x1 == x2) {
        int delta = y2 - y1;
        if (delta > 0) {
            if (b < y1) printBIG(hash[delta]);
            else {
                if (a >= y1) {
                    if (b < y2) {
                        printBIG(add(hash[delta], mul(hash[y2-b], mul(hash[b-a], hash[a-y1]))));
                    }
                    else printBIG(hash[delta]);
                }
                else {
                    printBIG(hash[delta]);
                }
            }
        }
        else printf("0\n");
    }
    else {
        BIGINT l1 = {0,{0}}, l2 = {0,{0}}, r1 = {0,{0}}, r2 = {0,{0}};
        if (y1 > y2) printf("0\n");
        else {
            if (y1 == y2 && (y1 == a || y1 == b)) printf("1\n");
            else {
                int delta1 = a - y1, delta2 = b - y1;
                if (delta1 >= 0) l1 = hash[delta1];
                if (delta2 >= 0) l2 = hash[delta2];
                if (delta1 == 0) l1 = int2BIG(1);
                if (delta2 == 0) l2 = int2BIG(1);

                int delta3 = y2 - a, delta4 = y2 - b;
                if (delta3 > 0) r1 = hash[delta3];
                if (delta4 > 0) r2 = hash[delta4];
                printBIG(add(mul(l1, r1), mul(l2, r2)));
            }
        }
    }
}



int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int ptA, ptB; //path A/B
		int stB, stS; //Start Building/Step
		int edB, edS; //End Building/Step
		scanf("%d %d %d %d %d %d", &ptA, &ptB, &stB, &stS, &edB, &edS);
		printf("case #%d:\n", i);
		solve(ptA, ptB, stB, stS, edB, edS);
	}
	return 0;
}
