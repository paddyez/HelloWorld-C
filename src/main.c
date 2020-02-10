#include <errno.h>
#include <main.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		fprintf(stderr, "usage: %s <start> <stop> <increment>\n", argv[0]);
  		exit(0);
	}
	/*
	print_hello_world();
	*/
	errno = 0;
	char *endptrstart;
	char *endptrstop;
	char *endptrincrement;
	float start = strtof(argv[1], &endptrstart);
	float stop = strtof(argv[2], &endptrstop);
	float increment = strtof(argv[3], &endptrincrement);
	if((*endptrstart != '\0' || *endptrstop != '\0' || *endptrincrement != '\0') || errno != 0) {
		if(errno == 0) {
			errno = EINVAL;
		}
		error("Error parsing arguments expected three numbers of type float");
	} else if (start > stop) {
		error("stop must be smaller than start");
	} else if (increment <= 0) {
		error("increment must be greater than 0");
	} else {
		printf("start: %6.2f\tstop: %6.2f\tincrement: %6.2f\n", start, stop, increment);
		create_celsius_conversion_table(start, stop, increment);
		create_fahrenheit_conversion_table(start, stop, increment);
	}
	return EXIT_SUCCESS;
}

void error(const char *msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}
