#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1000

typedef struct
{
	int v[MAXN];
	int iL;
	int fL;
	int sign;
} BF;

void bfCountLen(BF* a)
{
	int i = 0, L = MAXN / 2;
	while (i <= L && a->v[i] == 0) i++;
	if (i > L) {
		a->iL = 1;
	}
	else {
		a->iL = L - i + 1;
	}
	i = 2 * L;
	while (i > L && a->v[i] == 0) {
		i--;
	}
	a->fL = i-L;
}

int bfCompare(BF* a, BF* b)
{
	int L = MAXN / 2;
	if (a->iL > b->iL) {
		return 1;
	}
	else if (a->iL < b->iL) {
		return -1;
	}
	for (int i = 0; i < 2*L; i++) {
		if (a->v[i] > b->v[i]) {
			return 1;
		}
		else if (a->v[i] < b->v[i]) return -1;
	}
	return 0;
}

void Input(BF* bf)
{
	int L = MAXN / 2;
	char s[MAXN] = {0};
	scanf("%s", s);
	int i = 0, j, k;
	while (s[i] && s[i] != '.') i++;
	for (j = i-1, k = L; j >= 0; j--, k--) {
		bf->v[k] = s[j] - '0';
	}
	int len = strlen(s);
	for (j = i+1, k = L+1; j < len; j++, k++) {
		bf->v[k] = s[j] - '0';
	}
}

BF ADD(BF a, BF b, int N)
{
	int L = MAXN / 2;
	for (int i = 2*L; i > L+N; i--) {
		a.v[i] += b.v[i];
		a.v[i-1] += a.v[i] / 10;
		a.v[i] %= 10;
	}
	if (a.v[L+N+1] >= 5) a.v[L+N]++;
	for (int i = L+N; i > 0; i--) {
		a.v[i] += b.v[i];
		a.v[i-1] += a.v[i] / 10;
		a.v[i] %= 10;
	}
	return a;
}

BF SUB(BF a, BF b, int N){
	int i, L = MAXN/2;
	for(int i = 2*L; i > 0; i--){
		if(a.v[i] < b.v[i]){
			a.v[i] += 10 - b.v[i];
			a.v[i-1]--;
		}
		else{
			a.v[i] -= b.v[i];
		}
	}
	return a;
}

void output(int a[],int N)
{
	int i = 0, L = MAXN/2;
	while (i <= L && a[i] == 0) i++;
	if (i > L) printf("%d",0); 
	else
	{
		while(i <= L) printf("%d", a[i++]);
	}
	printf("%c",'.');
	while(i <= L+N) printf("%d", a[i++]);
	printf("\n");
}

int main()
{
	BF a = {{0},0,0,1}, b = {{0},0,0,1}, zero = {{0}, 1, 1, 1};
	memset(a.v, 0, MAXN*sizeof(int));
	memset(b.v, 0, MAXN*sizeof(int));
	Input(&a);
	Input(&b);
	bfCountLen(&a); bfCountLen(&b);
	int judge = bfCompare(&a, &b);
	int N; scanf("%d", &N);
	if(judge>0){
		a = SUB(a, b, N);
		a = ADD(a, zero, N);
	}
	else{
		a = SUB(b, a, N);
		a = ADD(a, zero, N);
	}
	if(judge<0){printf("-");}
	output(a.v, N);
	return 0; 
}