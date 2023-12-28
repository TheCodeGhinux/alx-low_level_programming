#include "search_algos.h"

/**
 * _binary_search - Searches for a value in a sorted array
 *                  of integers using binary search.
 * @array: Pointer to first element of array
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: the index where the value is located.
 *         Else -1, If the value is not present or the array is NULL
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t a;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (a = left; a < right;a++)
			printf("%d, ", array[a]);
		printf("%d\n", array[a]);

		a = left + (right - left) / 2;
		if (array[a] == value)
			return (a);
		if (array[a] > value)
			right = a - 1;
		else
			left = a + 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array
 *                      of integers using exponential search.
 * @array: Pointer to first element of array
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: the index where the value is located.
 *         Else -1, If the value is not present or the array is NULL
 *
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t a = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (a = 1; a < size && array[a] <= value; a = a * 2)
			printf("Value checked array[%ld] = [%d]\n", a, array[a]);
	}

	right = a < size ? a : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", a / 2, right);
	return (_binary_search(array, a / 2, right, value));
}