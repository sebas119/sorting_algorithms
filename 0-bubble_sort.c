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
 * bubble_sort - Implementation of the Bubble sort algorithm
 * @array: unordered array of integers
 * @size: size of the array given
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = size, j, newn = 1;

	if (array == NULL || size < 2)
		return;

	while (newn >= 1)
	{
		newn = 0;
		for (j = 1; j < n; j++)
		{
			if (array[j - 1] > array[j])
			{
				swap_int(&array[j - 1], &array[j]);
				print_array(array, size);
				newn = j;
			}
		}
		n = newn;
	}
}
