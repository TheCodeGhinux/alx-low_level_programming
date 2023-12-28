#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array
 *                 of integers using linear search algorithm
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: The value to search.
 *
 * Return: the first index where the value is located
 *          Else -1, Null if value is not present in array
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
