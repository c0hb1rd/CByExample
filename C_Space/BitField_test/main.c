#include <stdio.h>

/* open or close */
#define YES 1
#define NO  0

/* boder style */
#define SOLID 0
#define DOTTED 1
#define DASHED 2

/* three source color */
#define BLUE 4
#define GREEN 2
#define RED 1

/* group colors */
#define BLACK (RED & GREEN & BLUE)
#define YELLOW (RED | GREEN)
#define WHITE (RED | GREEN | BLUE)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)

typedef char * String;
const String colors[8] = {
		"black", "red", "green", "yellow", 
		"blue", "magenta", "cyan", "white"
	};

struct box_props {
	unsigned int opaque     : 1;
	unsigned int fill_color : 3;
	unsigned int            : 4;
	unsigned int show_boder : 1;
	unsigned int boder_color: 3;
	unsigned int boder_style: 2;
	unsigned int            : 2;
};

void show_settings(const struct box_props *);

int main(void)
{
	struct box_props box = {YES, YELLOW, YES, GREEN, DASHED};

	printf("Original box setting:\n");

	show_settings(&box);

	box.opaque = NO;
	box.fill_color = WHITE;
	box.boder_color = MAGENTA;
	box.boder_style = SOLID;
	puts("Modified box settings:");
	show_settings(&box);

	return 0;
}

void show_settings(const struct box_props * ps)
{
	printf("Box is %s.\n", ps->opaque == YES ? "opaque" : "transparent");
	printf("The fill color is %s.\n", colors[ps->fill_color]);
	printf("Boder %s.\n", ps->show_boder == YES ? "shown" : "not shown");
	printf("The boder color is %s.\n", colors[ps->boder_color]);
	printf("The boder style is ");

	switch(ps->boder_style)
	{
		case SOLID: printf("solid.\n"); break;
		case DOTTED: printf("dotted.\n"); break;
		case DASHED: printf("dashed.\n"); break;
		default: printf("unknow type.\n"); 
	}

	puts("");
}
