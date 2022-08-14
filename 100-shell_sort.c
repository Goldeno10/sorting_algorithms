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
	size_t n = size;
	size_t gap = 1, j, i;
	int temp;

	while (gap <= n / 3)
		gap = n * 3 + 1;

	while (gap > 0)
	{
		for (j = gap; j < n; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] > array[1])
				{
					break;
				}
				else
				{
					temp = array[i + gap];
					array[i + gap] = array[i];
					array[i] = temp;
				}
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, n);
	}
}
