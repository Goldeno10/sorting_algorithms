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
	while (gap <= (int)size / 3)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap  = gap / 3)
	{
		for (i = gap; i <= (int) size; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (array[j + gap] > array[j])
					break;
				else
				{
				temp = array[j];
				array [j] = array[j + gap];
				array[j + gap] = temp;
				}
			}
		}
		print_array(array, n);
	}
}	
