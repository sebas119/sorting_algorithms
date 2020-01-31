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
 * bubble_sort - Implementation of the Buble sort algorithm
 * @array: unordered array of integers
 * @size: size of the array given
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j > 0; j--)
		{
			if (array[j] < array[j - 1])
			{
				swap_int(&array[j], &array[j - 1]);
				print_array(array, size);
			}
		}
	}
}
