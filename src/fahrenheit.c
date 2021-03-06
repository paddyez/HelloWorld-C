#include "fahrenheit.h"
#include "inputoutput.h"
#include "temperature.h"
#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
	float fahrenheit = (celsius * NINE_FIFTHS) + THIRTY_TWO;
	return fahrenheit;
}

void create_celsius_conversion_table(float start, float end, float increment) {
	float current = start;
	printf("----\n");
	printf("°C\t| °F\n");
	while(current <= end) {
		float fahrenheit = celsius_to_fahrenheit(current);
		print_table_line(current, fahrenheit);
		current += increment;
	}
}
