#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char input[100000] = {0};
int isDouble();
void DisplayInt(unsigned int var_int, int depth);
void DisplayDouble(double var_double, int depth);

int main()
{
	while (scanf("%s", input) != EOF) {
		int var_int = 0;
		double var_double = 0.0;
		int check = isDouble();
		if (!check) {
			var_int = atoi(input);
			DisplayInt(var_int, 0);
			printf("\n");
		}
		else {
			var_double = atof(input);
			DisplayDouble(var_double, 0);
			printf("\n");
		}
	}
	return 0;
}

int isDouble()
{
	int n = strlen(input);
	for (int i = 0; i < n; i++) {
		if (input[i] == '.' || input[i] == 'e' || input[i] == 'E') {
			return 1;
		}
	}
	return 0;
}

void DisplayInt(unsigned int var_int, int depth)
{
	int display = ~(~0<<8) & var_int;
	if (depth < 4) {
		printf("%02x ", display);
		DisplayInt(var_int >> 8, depth+1);
	}
}

void DisplayDouble(double var_double, int depth)
{
	unsigned long long var_display_double = *(unsigned long long*)(&var_double);
	int display = ~(~0<<8) & var_display_double;
	if (depth < 8) {
		var_display_double >>= 8;
		double var_next_double = *(double*)(&var_display_double);
		printf("%02x ", display);
		DisplayDouble(var_next_double, depth+1);
	}
}
