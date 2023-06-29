#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN(a, b) ((a) < (b)) ? (a) : (b)

const int IMAX = 2147483647;
int all_xy[120][2] = {{0, 0}};
int dir[][2] =
{
   {0,  1}, {0, -1},
   {-1, 0}, {1,  0}
};

void init(const char* seq)
{
	int len = strlen(seq);
	int x = 0, y = 0;
	for (int i = 0; i < len; i++) {
		int k = 0;
		switch (seq[i]) {
        case 'U': k = 0; break;
        case 'D': k = 1; break;
        case 'L': k = 2; break;
        case 'R': k = 3; break;
		}
        x += dir[k][0];
        y += dir[k][1];
        all_xy[i+1][0] = x;
        all_xy[i+1][1] = y;
	}
}

int reachable(int a, int dx, int dis_max)
{
	if (dis_max == 0 && a == dx) {
		return -2; //reach every time;
	}
	else if (dis_max > 0 && a >= dx && (a - dx) % dis_max == 0) {
		return (a-dx) / dis_max;
	}
	else if (dis_max < 0 && a <= dx && (a - dx) % dis_max == 0) {
		return (a-dx) / dis_max;
	}
	else return -1;
}

void solve(const char* seq, int a, int b)
{
    int len = strlen(seq);
    int r_a = a, r_b = b;
    int r_1 = 0, r_2 = 0;
	
	int ans = 0;
    for (int i = 0; i <= len; i++) {
		int reach_a = reachable(a, all_xy[i][0], all_xy[len][0]);
    	int reach_b = reachable(b, all_xy[i][1], all_xy[len][1]);
    	if (reach_a == -1 || reach_b == -1) {
    		ans = 0;
		}
		else if (reach_a == -2 || reach_b == -2) {
			ans = 1;
		}
		else if (reach_a == reach_b) {
			ans = 1;
		}
		else ans = 0;
		if (ans) break;
	}
	if (ans) printf("Yes\n");
	else printf("No\n");
}

int main()
{
    char seq[120] = {0};
    int a = 0, b = 0;
    scanf("%s", seq);
    init(seq);
    int q = 0;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &a, &b);
        solve(seq, a, b);
    }
    return 0;
}
