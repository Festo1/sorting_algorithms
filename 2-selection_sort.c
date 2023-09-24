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
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min; /* Pointer to the minimum element in the array. */
	size_t i, j; /* Loop counters */

	/* Check for edge cases: empty array or array with only one element. */
	if (array == NULL || size < 2)
		return;

	/* Outer loop to iterate through the array. */
	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		/* Inner loop to find the actual minimum element in the remaining part.*/
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		/* If the minimum element is not the current element, swap them.*/
		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
