#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 * order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	/* Check for edge cases: empty array or array with only one element.*/
	if (array == NULL || size < 2)
		return;

	/* Determine the initial gap using the Knuth interval sequence.*/
	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	/* Loop over different gap sizes, reducing the gap in each iteration.*/
	for (; gap >= 1; gap /= 3)
	{
		/* Iterate over the elements starting from the current gap.*/
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		/* Print the array after each pass with the current gap.*/
		print_array(array, size);
	}
}
