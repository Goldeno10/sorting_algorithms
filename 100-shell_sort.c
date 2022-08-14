#include "sort.h"

/**
 *shell_sort - sorts an array of integers in ascending order
 *using the Shell sort algorithm, using the Knuth sequence
 *@array: Array being sorted
 *@size: Size of array
 *Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	int n = (int)size;
	int gap = 1, j, i;
	int temp;

	if (!array || size < 2)
		return;
	while (gap <= n / 3)
		gap = gap * 3 + 1;

	for (gap = 1; gap < (n / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < n; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				temp = array[j - gap];
				array[j - gap] = array[j];
				array[j] = temp;
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
