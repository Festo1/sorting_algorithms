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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	/* Check for invalid input or an already sorted array. */
	if (array == NULL || size < 2)
		return;

	/* Continue sorting until no more swaps are needed. */
	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{

		/* If the current element is greater than the next element, swap them. */
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				/* Print the array after each swap. */
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
