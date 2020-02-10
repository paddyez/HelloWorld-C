#include <stdio.h>
#include <temperature.h>

float fahrenheit_to_celsius(float fahrenheit) {
	float celsius = FIVE_NINETHS * (fahrenheit - THIRTY_TWO);
	return celsius;
}

void create_fahrenheit_conversion_table(float start, float end, float increment) {
	float current = start;
	printf("----\n");
	printf("°F\t| °C\n");
	while(current <= end) {
		float celsius = fahrenheit_to_celsius(current);
		print_table_line(current, celsius);
		current += increment;
	}
}
