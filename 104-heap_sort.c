#include "sort.h"

void swap_int(int *a, int *b, int *array, size_t size);
void buildMaxHeap(int *array, size_t sizeHeap, size_t i, size_t fixedSize);


/**
 * heap_sort - Implementation of the Heap Sort algorithm
 * @array: Array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int fixedSize = size;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		buildMaxHeap(array, size, i, fixedSize);

	for (i = size - 1; i >= 0; i--)
	{
		swap_int(&array[0], &array[i], array, size);
		buildMaxHeap(array, i, 0, fixedSize);
	}
}

/**
 * buildMaxHeap - Build a max heap from an array
 *
 * @array: Array of integers
 * @sizeHeap: Size of the heap
 * @i: Index of the root of subtree
 * @fixedSize: Size fixed of the array
 */
void buildMaxHeap(int *array, size_t sizeHeap, size_t i, size_t fixedSize)
{
	size_t largest = i;
	size_t left = (2 * i) + 1;
	size_t right = (2 * i) + 2;

	if (left < sizeHeap && array[left] > array[largest])
		largest = left;

	if (right < sizeHeap && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap_int(&array[i], &array[largest], array, fixedSize);
		buildMaxHeap(array, sizeHeap, largest, fixedSize);
	}
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
