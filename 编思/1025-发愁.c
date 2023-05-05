#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int score;
	int victory;
	int defeat;
	int index;
} team;

int cmp(const void* a1, const void* b1)
{
	team a = *(team*)a1, b = *(team*)b1;
	if (a.score != b.score) {
		return b.score - a.score;
	}
	else {
		if (a.victory != b.victory) {
			return b.victory - a.victory;
		}
		else {
			if (a.defeat != b.defeat) {
				return a.defeat - b.defeat;
			}
			else {
				return a.index - b.index;
			}
		}
	}
}

int main()
{
	int n = -1, m = -1;
	while (n != 0) {
		scanf("%d%d", &n, &m);
		if (n != 0) {
			team v[11];
			for (int i = 0; i < n; i++) {
				v[i].index = i+1;
				v[i].score = 0;
				v[i].victory = 0;
				v[i].defeat = 0;
			}
			for (int i = 0; i < m; i++) {
				int a = 0, b = 0, c = 0;
				scanf("%d%d%d", &a, &b, &c);
				if (c == 1) {
					v[a-1].victory++;
					v[a-1].score += 3;
					v[b-1].defeat++;
					v[b-1].score -= 1;
				}
				else if (c == -1) {
					v[b-1].victory++;
					v[b-1].score += 3;
					v[a-1].defeat++;
					v[a-1].score -= 1;
				}
				else {
					v[a-1].score++;
					v[b-1].score++;
				}
			}
			qsort(v, n, sizeof(team), cmp);
			for (int i = 0; i < n; i++) {
				if (i != n-1) {
					printf("%d ", v[i].index);
				}
				else printf("%d\n", v[i].index);
			}
		}
	}
	return 0;
}