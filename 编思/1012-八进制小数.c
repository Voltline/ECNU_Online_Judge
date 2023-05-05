#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nums[200];
    int point;
    int size;
} frac;

int toDigit(char c)
{
    return c - '0';
}

int find_not_zero(int frac[])
{
    for (int i = 199; i >= 0; i--) {
        if (frac[i] != 0) {
            return i;
        }
    }
    return -1; // If all zero, return -1;
}

int check_is_zero(const char* input)
{
    for (int i = 2; i < strlen(input); i++) {
        if (input[i] != '0') return 0;
    }
    return 1; // if no non-zero in input, return 1;
}

void init_frac(frac* in_frac, const char* oct)
{
    memset(in_frac->nums, 0, 200 * sizeof(int));
    in_frac->nums[0] = 0;
    in_frac->point = 1;
    in_frac->size = strlen(oct);
    for (int j = 2; j < strlen(oct); j++) {
        in_frac->nums[j-1] = toDigit(oct[j]);
    }
}

void FracPlus(frac* dec_frac, int d)
{
    dec_frac->nums[0] += d;
}

void FracTimes(frac* dec_frac) // dec_frac * 0.125
{
    int N_nums[200] = {0};
//    printf("----------\n");
//    for (int i = 0; i < dec_frac->size; i++) {
//        printf("%d ", dec_frac->nums[i]);
//    }
//    printf("\n");
    for (int i = 1; i < dec_frac->size; i++) { // * 0.1
        N_nums[i] += dec_frac->nums[i-1];
    }

    for (int i = 2; i < dec_frac->size+2; i++) { // * 0.02
        N_nums[i] += 2 * dec_frac->nums[i-2];
    }

    for (int i = 3; i < dec_frac->size+3; i++) { // * 0.05
        N_nums[i] += 5 * dec_frac->nums[i-3];
    }

    int N_size = find_not_zero(N_nums);
    for (int j = N_size; j >= 1; j--) {
        if (N_nums[j] >= 10) {
            N_nums[j-1] += N_nums[j] / 10;
            N_nums[j] %= 10;
        }
    }
    N_size = find_not_zero(N_nums);
    memcpy(dec_frac->nums, N_nums, 200 * sizeof(int));
    dec_frac->size = N_size+2;
}

void OctToDec(frac* oct_frac, frac* dec_frac)
{
    memset(dec_frac->nums, 0, sizeof(int) * 200);
    dec_frac->point = 1;
    dec_frac->size = 3;
    for (int i = oct_frac->size - 2; i >= 1; i--) {
        FracPlus(dec_frac, oct_frac->nums[i]);
        FracTimes(dec_frac);
        dec_frac->size = find_not_zero(dec_frac->nums);
        if (dec_frac->size == -1) dec_frac->size = 3;
        else dec_frac->size += 2;
    }
}

void Print(frac F)
{
    for (int i = 0; i < F.size; i++) {
        if (i == 0) {
            printf("%d", F.nums[i]);
        }
        else if (i == 1) printf(".");
        else printf("%d", F.nums[i-1]);
    }
    printf("\n");
}

int main()
{
    int T = 0;
    char oct[70] = {0};
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%s", oct);
        frac dec, oct_frac;
        init_frac(&oct_frac, oct);
        //Print(oct_frac);
        OctToDec(&oct_frac, &dec);
        printf("case #%d:\n", i);
        Print(dec);
    }
    return 0;
}
