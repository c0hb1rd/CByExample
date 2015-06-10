#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ALPHA "23456789<>,./?;:'\"{}[]|\\-=()`~!@#$\%^&*abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ"

int pow(int, int);
long int btoin(char *);
bool judge(char *);

int main(int argc, char *argv[])
{
	if(2 != argc){
		printf("Using as: %s [binary]\n", argv[0]);
		return 1;
	}	
	
	if(judge(argv[1]) || strpbrk(argv[1], ALPHA) != NULL){
		printf("Using as: %s [binary]\n", argv[0]);
		return 1;
	}

	printf("%ld\n", btoin(argv[1]));
	return 0;
}

long int btoin(char * str)
{
	int len	= strlen(str);

	int nums[len];
	long int num = 0;
	int i = 0;
	for(i = len - 1; i >= 0; i--, str++){
		switch(*str)
		{
			case '0': nums[i] = 0; break;
			case '1': nums[i] = 1; break;
		}
		
		nums[i] *= pow(2, i);	
	}
	
	for(i = 0; i < len; i++)
		num += nums[i];

	return num;	
}

int pow(int a, int b)
{
	int total = 1;
	while(b--){
		total *= a;
	}
	
	return total;
}

bool judge(char * str)
{
	int count = 0;
	int len = strlen(str);
	int i;
	for(i = 0; i < len; i++)
		if(isdigit(str[i]))
			count++;
	if(count == len)
		return false;
	else
		return true;
}
