#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);
	clock_t start, end;
	double cpu_time_used;

	print_array(array, n);
	printf("\n");
	start = clock();
	bubble_sort(array, n);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\n");
	print_array(array, n);
	printf("\n%f seconds\n", cpu_time_used);
	return (0);
}
