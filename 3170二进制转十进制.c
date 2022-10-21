#include <stdio.h>
#include <math.h>
unsigned b2i(char s[])
/* PreCondition:  s 是由 0 和 1 组成的字符串，且字符串长度不超 32
   PostCondition: 返回与字符串 s 对应的十进制数
*/
{ //TODO: your function definition
	int cnt = 0, i = 0;
	for (i = 0; s[i] != '\0'; i++) {}
	cnt = i - 1;
	unsigned int ans = 0;
	for (i = cnt; i >= 0; i--) {
		ans += ((int)s[i] - 48) * (unsigned int)pow(2, cnt - i);
	}
	return ans;
}
/***************************************************************/

#define N 32
int main()
{   char s[N+1];
    scanf("%s",s);
//********** b2i is called here ********************
    printf("%u\n",b2i(s));
//**************************************************
return 0;
}