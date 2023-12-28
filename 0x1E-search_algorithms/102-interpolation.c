#include "search_algos.h"

/**
 * interpolation_search - searches for a value in an array of
 * integers using the Interpolation search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */

/**
 * interpolation_search - Searches for a value in a sorted array
 *                        of integers using interpolation search.
 * @array: Input array to search
 * @size: Size of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where the value is located.
 *          Else, -1 If the value is not present or the array is NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t a, b, c;
	double f;

	if (array == NULL)
		return (-1);

	b = 0;
	c = size - 1;

	while (size)
	{
		f = (double)(c - b) / (array[c] - array[b]) * (value - array[b]);
		a = (size_t)(b + f);
		printf("Value checked array[%d]", (int)a);

		if (a >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[a]);
		}

		if (array[a] == value)
			return ((int)a);

		if (array[a] < value)
			b = a + 1;
		else
			c = a - 1;

		if (b == c)
			break;
	}

	return (-1);
}