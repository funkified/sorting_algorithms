#include "sort.h"
/**
 * partition - lomu partion
 * @array: array to be sorted
 * @size: size of the array
 * @min: first postion
 * @max: last
 * Return: index
 */)
int partition(int *array, int min, int max, size_t size)
{
	int pivot = array[max];
	int i = min - 1;
	int j;

	for (j = min; j <= max; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	return (i);
}
/**
 * quick_sort - sort using quick_sort algorithhm
 * @array: array to be sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{

	int min, max;

	if (array == NULL || size < 2)
		return;
	min = 0;
	max = size - 1;
	quick_recursion(array, min, max, size);
}
/**
 * quick_recursion - recursion helper to sort
 * @array: array
 * @size: size
 * @min: min
 * @max: max
 */
void quick_recursion(int *array, size_t min, size_t max, size_t size)
{
	size_t i;

	if (min < max)
	{
		i = partition(array, min, max, size);
		if (i > min)
			quick_recursion(array, min, i - 1, size);
		if (i < max)
			quick_recursion(array, i + 1, max, size);
	}
}
/**
 * swap - swap values f array
 * @array: array
 * @i: postion
 * @j: postion
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
