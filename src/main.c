#include <stdio.h>
#include <stdlib.h>
#include <main.h>

int main(int argc, char *argv[]) {
	if (argc < 4) {
		fprintf(stderr, "usage: %s <celsius start> <celsius stop> <increment>\n", argv[0]);
  		exit(0);
	}
	/*
	print_hello_world();
	*/
	float start = (float)atof(argv[1]);
	float stop = (float)atof(argv[2]);
	float increment = (float)atof(argv[3]);
	printf("arguments: %d %6.2f\t%6.2f\t%6.2f\n", argc, start, stop, increment);
	create_celsius_conversion_table(start, stop, increment);
	return EXIT_SUCCESS;
}
