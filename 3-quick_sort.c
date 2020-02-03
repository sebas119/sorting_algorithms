#include "sort.h"

int partition(int *array, int left, int right, size_t size);
void swap_int(int *a, int *b);
void quicksort(int *array, int left, int right, size_t size);

void quick_sort(int *array, size_t size)
{
    quicksort(array, 0, size - 1, size);
}

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

int partition(int *array, int left, int right, size_t size)
{
    int pivot = array[right];
    int i = left, j;

    for (j = left; j <= right; j++)
    {
        if (array[j] < pivot)
        {
            swap_int(&array[i], &array[j]);
            print_array(array, size);
            i++;
        }
    }
    swap_int(&array[i], &array[right]);

    return (i);
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
