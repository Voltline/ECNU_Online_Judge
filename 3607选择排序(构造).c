#include <stdio.h>
#include <time.h>

clock_t start, stop;

double duration;

void typical_selection(int a[], int n) {
	int minIndex;
	for (int i = 0; i < n - 1; i++) {
	    minIndex = i; // 无序区的最小数据数组下标
	    for (int j = i + 1; j < n; j++)
	        // 在无序区中找到最小数据并保存其数组下标
	        if (a[j] < a[minIndex])
	            minIndex = j;
	    int t = a[i];
	    a[i] = a[minIndex];
	    a[minIndex] = t;
	}
}

void slow_selection(int a[], int n) {
	for (int i = 0; i < n; ++i) {
	    for (int j = i + 1; j < n; ++j) {
	        if (a[i] > a[j]) {
		        int t = a[i];
		        a[i] = a[j];
		        a[j] = t;
	        }
		}
	}
}

int main()
{
	int array1[80000] = {0}, array2[80000] = {0};
	for (int i = 80000; i >= 1; i--) {
		array1[80000-i] = i;
		array2[80000-i] = i;
	}
	start = clock();
	typical_selection(array1, 80000);
	stop = clock();
	duration = ((double)(stop - start))/(CLK_TCK);
	printf("typical_selection occupies %6.2e s\n", duration);
	
	start = clock();
	slow_selection(array2, 80000);
	stop = clock();
	duration = ((double)(stop - start))/(CLK_TCK);
	printf("slow_selection occupies %6.2e s\n", duration);
	
	return 0;
}
