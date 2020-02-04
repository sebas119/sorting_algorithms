#include "sort.h"

void swap_int(int *a, int *b);
void buildMaxHeap(int *array, size_t size, size_t i);

void heap_sort(int *array, size_t size)
{
    int i;

    for (i = size / 2 - 1; i >= 0; i--)
        buildMaxHeap(array, size, i);

    for (i = size - 1; i >= 0; i--)
    {
        swap_int(&array[0], &array[i]);
        buildMaxHeap(array, i, 0);
    }
}

void buildMaxHeap(int *array, size_t size, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap_int(&array[i], &array[largest]);
        buildMaxHeap(array, size, largest);
    }
}

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