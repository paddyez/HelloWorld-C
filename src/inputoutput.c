#include <stdio.h>

void print_hello_world(void) {
	printf("Hello, world\n");
}

void print_table_line(float initial, float converted) {
	printf("%6.2f\t| %6.4f\n", initial, converted);
}
