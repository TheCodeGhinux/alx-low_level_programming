#include "search_algos.h"

/**
 * advanced_binary_recursive - Searches recursively for a value in a sorted
 *                             array of integers using binary search.
 * @array: input array
 * @size: size of the array
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: the index where the value is located.
 *         Else, -1 If the value is not present
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t a;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (a = left; a < right; a++)
		printf("%d, ", array[a]);
	printf("%d\n", array[a]);

	a = left + (right - left) / 2;
	if (array[a] == value && (a == left || array[a - 1] != value))
		return (a);
	if (array[a] >= value)
		return (advanced_binary_recursive(array, left, a, value));
	return (advanced_binary_recursive(array, a + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array
 *                   of integers using advanced binary search.
 * @array: input array
 * @size: size of the array
 * @value: The value to search for.
 *
 * Return: the first index where the value is located.
 *         Else -1, If the value is not present or the array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
