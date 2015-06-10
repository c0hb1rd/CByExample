#include <stdio.h>

/* macro */
#define PF_S(X) printf("This is test about " #X " : %s\n", X)
#define PF_LD(X) printf("This is test about " #X " : %ld\n", X)
#define PF_D(X) printf("This is test about " #X " : %d\n", X)

int main(void)
{
	PF_S(__FILE__);
	PF_S(__DATE__);
	PF_S(__TIME__);
	PF_LD(__STDC_VERSION__);
	PF_D(__LINE__);
	PF_S(__func__);
	
	puts("");

#line 10 "test.c"
	/* line number 10 */
	PF_S(__FILE__);
	PF_S(__DATE__);
	PF_S(__TIME__);
	PF_LD(__STDC_VERSION__);
	PF_D(__LINE__);
	PF_S(__func__);
	
	return 0;
}
