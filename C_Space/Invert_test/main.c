#include <stdio.h>

typedef char * String;
String itobs(int, String);
void show_bstr(String);
int invert_end(int num, int );

int main(void)
{
	char str[8 * sizeof(int) + 1];
	int number;

	puts("Enter integers and see them in binary.");
	puts("Non-numeric input terminates program.");
	while(scanf("%d", &number) == 1){
		itobs(number, str);
		printf("%d is ", number);
		show_bstr(str);
		puts("");
		number = invert_end(number, 4);
		printf("Invered number:");
		show_bstr(itobs(number, str));
		puts("");
	}

	puts("Bye!");

	return 0;
}

String itobs(int n, String ps)
{
	int i;
	static int size = 8 * sizeof(int);

	for(i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';

	return ps;
}

void show_bstr(String ps)
{
	int i = 0;
	while(ps[i]){
		putchar(ps[i]);
		if(++i % 4 == 0 && ps[i])
			putchar(' ');
	}
}

int invert_end(int num, int bits)
{
	int mask = 0;
	int bitval = 1;

	while(bits-- > 0){
		mask |= bitval;
		bitval <<= 1;
	}

	return num ^ mask;
}
