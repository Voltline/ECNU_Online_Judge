#include <stdio.h>
int main()
{
	int size = 0, line = 0, length_last = 0, length_max = 0;
	char temp;
	while (scanf("%c", &temp) != EOF) {
		if (temp != '\n') {
			size++;
			length_last++;
		}
		else {
			line++;
			if (length_last > length_max)
			length_max = length_last;
			length_last = 0;
		}
	}
	printf("%d,%d,%d\n",size,line,length_max);
	return 0;
}