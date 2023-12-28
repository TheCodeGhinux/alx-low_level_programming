#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in an array of
 * integers using the Jump search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: jump of the number
 */

/**
 * jump_search - Searches for a value in a sorted array
 *               of integers using jump search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first jump where the value is located.
 *          Else, -1 If the value is not present or the array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	int jump, a, b, prev;

	if (array == NULL || size == 0)
		return (-1);

	a = (int)sqrt((double)size);
	b = 0;
	prev = jump = 0;

	do
	{
		printf("Value checked array[%d] = [%d]\n", jump, array[jump]);

		if (array[jump] == value)
			return (jump);
		k++;
		prev = jump;
		jump = a * b;
	} while (jump < (int)size && array[jump] < value);

	printf("Value %d found at index %d\n", prev, jump);

	for (; prev <= jump && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}