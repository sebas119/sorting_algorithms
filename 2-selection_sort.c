#include "sort.h"

/**
 * swap_int - Swap the values of two integers
 *
 * @a: Pointer of integer variable
 * @b: Pointer of integer variable
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Implementation of the Selection Sort algorithm
 * @array: unordered array of integers
 * @size: size of the array given
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (i != min)
		{
			swap_int(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
