#include "sort.h"
/**
 * hoare_partition - lomu partion
 * @array: array to be sorted
 * @size: size of the array
 * @min: first postion
 * @max: last
 * Return: index
 */
int hoare_partition(int *array, int min, int max, size_t size)
{
	int pivot = array[max];
	int i = min;
	int j = max;

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
			i++;
			j--;
		}
	}
	return (j);
}
/**
 * quick_sort_hoare - sort using quick_sort algorithhm
 * @array: array to be sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_recursion(array, 0, size - 1, size);
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
		i = hoare_partition(array, min, max, size);
		quick_recursion(array, min, i, size);
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
