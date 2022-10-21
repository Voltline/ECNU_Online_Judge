#include <stdio.h>
#include <math.h>

#define MAX 1000

typedef struct {
    int x, y, z;
} Point;

//********** Specification of NearPoints **********
int NearPoints(Point *p, int n);
/* PreCondition: p 指向一个点的数组，n 是范围为 2-100 的点的个数
    PostCondition: 返回距离原点小于 100 的点的个数
*/

/***************************************************************/
int main() {
    int n, i;
    Point p[MAX];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
    printf("%d\n", NearPoints(p, n));
    return 0;
}

int NearPoints(Point *p, int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (sqrt(pow(p[i].x, 2) + pow(p[i].y, 2) + pow(p[i].z, 2)) < 100) {
			cnt++;
		}
	}
	return cnt;
}