#include <stdio.h>

static int chs[64] ={0};
int atoi(char *);
void binary(int);
int judge(char * str);

int main(int argc, char * argv[])
{
	if(argv[1] == NULL){
		puts("Error:Only accpet decimal!");
		puts("You can input \"--help\" to get the help menu");
		return 1;
	}

	if(judge(argv[1]))
		return 0;


	if(2 != argc || atoi(argv[1]) == 0){
		puts("Error:Only accpet decimal!");
		puts("You can input \"--help\" to get the help menu");
		return 1;
	}

	judge(argv[1]);

	int integer = atoi(argv[1]);
	
	binary(integer);

	int i;
	for(i = 1; i <= 64; i++) {
		printf("%d", chs[i - 1]);
		if(i % 8 == 0)
			printf(" ");
	}
	puts("");

	return 0;
}

int atoi(char * str)
{
	int index = 1, count = 0;

	while(*str == '1' ||
		*str == '2' ||
		*str == '3' ||
		*str == '4' ||
		*str == '5' ||
		*str == '6' ||
		*str == '7' ||
		*str == '8' ||
		*str == '9' ||
		*str == '0') {
		str++;
		count++;
		index *= 10;
	}

	index /= 10;

	str -= count;

	int temp[count];
	for (int i = 0; i < count; ++i, index /= 10){
		switch(*str++)
		{
			case '1':temp[i] = 1;break;
			case '2':temp[i] = 2;break;
			case '3':temp[i] = 3;break;
			case '4':temp[i] = 4;break;
			case '5':temp[i] = 5;break;
			case '6':temp[i] = 6;break;
			case '7':temp[i] = 7;break;
			case '8':temp[i] = 8;break;
			case '9':temp[i] = 9;break;
			case '0':temp[i] = 0;break;
		}
		temp[i] *= index;
	}

	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += temp[i];
	}

	return sum;
}

void binary(int num)
{
	static int count = 0;
	if(num >= 2)
		binary(num / 2);
	count++;
	char n = ('0' + num % 2);
	if(n == ('0' + 1))
		chs[64 - 1 - count] = 1;
	else if(n == ('0' + 0))
		chs[64 - 1 - count] = 0;
}

int judge(char * str)
{
	if(*str == '-')
		str++;
	else
		return 0;
	if(*str == '-')
		str++;
	else
		return 0;
	if(*str == 'h')
		str++;
	else
		return 0;
	if(*str == 'e')
		str++;
	else
		return 0;
	if (*str == 'l')
		str++;
	else
		return 0;
	if (*str == 'p')
		str++;
	else
		return 0;
	if(*str == '\0'){
		puts("Decimal <Option> : Option is a integer.");
		return 1;	
	}
	else
		return 0;
}
