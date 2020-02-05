#include "sort.h"

void merge(int *array, size_t size, int *tmp);

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge
 * sort algorithm
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *new = NULL;

	if (array == NULL || size < 2)
		return;
	new = malloc(size * sizeof(int));
	if (new == NULL)
		exit(98);

	merge(array, size, new);
	free(new);
}


/**
 * merge - Aux function for Merge sort. Divide an array in two parts and
 * orders.
 * @array: array (or sub-array) of integers to sort
 * @size: Size of the array
 * @tmp: Space of memory to save values temporarily
 */
void merge(int *array, size_t size, int *tmp)
{
	int half, *left, *right;
	unsigned int k = 0;

	if (size < 2)
		return;

	half = size / 2;
	left = array;
	right = array + half;

	merge(left, half, tmp);
	merge(right, size - half, tmp);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, half);
	printf("[right]: ");
	print_array(right, size - half);

	while (left < (array + half) || right < (array + size))
	{
		if (left < array + half && (*left <= *right || right >= array + size))
		{
			tmp[k++] = *left;
			left++;
		}
		if (right < array + size && (*right <= *left || left >= array + half))
		{
			tmp[k++] = *right;
			right++;
		}
	}
	for (k = 0; k < size; k++)
		array[k] = tmp[k];
	printf("[Done]: ");
	print_array(array, size);
}
