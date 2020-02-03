#include "sort.h"

int partition(int *array, int left, int right, size_t size);
void swap_int(int *a, int *b, int *array, size_t size);
void quicksort(int *array, int left, int right, size_t size);

/**
 * quick_sort - Implementation of the Quick Sort algorithm
 * @array: unordered array of integers
 * @size: size of the array given
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - Implementation of the quick Sort algorithm
 * @array: unordered array of integers
 * @left: Pointer to the left part of the array
 * @right: Poinrter to the right part of the array
 * @size: size of the array given
 */
void quicksort(int *array, int left, int right, size_t size)
{
	int index;

	if (left < right)
	{
		index = partition(array, left, right, size);
		quicksort(array, left, index - 1, size);
		quicksort(array, index + 1, right, size);
	}
}

/**
 * partition - Partition the array, rearrange the subarray
 * @array: unordered array of integers
 * @left: Pointer to the left part of the array
 * @right: Poinrter to the right part of the array
 * @size: size of the array given
 *
 * Return: Return a new index of the subarray (integer)
 */
int partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left, j;

	for (j = left; j < right; j++)
	{
		if (array[j] < pivot)
		{
			swap_int(&array[i], &array[j], array, size);
			i++;
		}
	}
	swap_int(&array[i], &array[right], array, size);
	return (i);
}

/**
 * swap_int - Swap the values of two integers
 *
 * @a: Pointer of integer variable
 * @b: Pointer of integer variable
 * @array: Array of integers
 * @size: size of the array
 */
void swap_int(int *a, int *b, int *array, size_t size)
{
	int temp;

	if (*a == *b)
		return;

	temp = *a;
	*a = *b;
	*b = temp;

	print_array(array, size);
}
