#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum {
		red,
		orange,
		yellow,
		green,
		blue,
		violet
}color;

const char * colors[] = {
		"red",
		"orange",
		"yellow",
		"green",
		"blue",
		"violet"
};

#define LEN 30

int main(void)
{
	char choice[LEN];
	bool color_is_found = false;

	puts("Enter a color(empty line to quit):");
	while(gets(choice) != NULL && choice[0] != '\0'){
		for (color = red; color <= violet; color++){
			if(strcmp(choice, colors[color]) == 0){
				color_is_found = true;
				break;
			}
		}

		if(color_is_found)
			switch(color){
				case red: puts("Rose are red."); break;
				case orange: puts("Poppies are orange."); break;
				case yellow: puts("Sunflower are yellow."); break;
				case green: puts("Grass is green."); break;
				case blue: puts("Bluebell is blue."); break;
				case violet: puts("Violets is violet."); break;
			}
		else
			printf("I do not know about the color %s.\n", choice);
		
		color_is_found = false;
		puts("Enter a next string(empty a line to auit):");
	}

	puts("Goobye!");

	return 0;
}
