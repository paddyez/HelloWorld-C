#include <stdio.h>
#include <stdlib.h>
#include <main.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		fprintf(stderr, "usage %s param1 param2\n", argv[0]);
  		exit(0);
	}
	print_hello_world();
	return EXIT_SUCCESS;
}
