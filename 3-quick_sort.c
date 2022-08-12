#include "sort.h"

/**
 *partition - Devides an array into two partition
 *@array: The array to be partitioned
 *@lb: partition lower bound
 *@ub: Partition upper bound
 *@n: Array size
 *Return: The upper bound/end index
 */

size_t partition(int *array, size_t n, size_t lb, size_t ub)
{
	int pivot = array[lb], temp;
	size_t start = lb, end = ub;

	while (start < end)
	{
		while (array[start] <= pivot)
			start++;
		while (array[end] > pivot)
			end--;
		if (start < end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
			print_array(array, n);
		}
	}
	temp = array[lb];
	array[lb] = array[end];
	array[end] = temp;
	print_array(array, n);

	return (end);
}

/**
 *quicksort - Implement the quick sort algorithm
 *@array: Array being sorted
 *@lb: Array lower bound
 *@ub: Array upper bound
 *@n: Array size
 *Return: Nothing
 */

void quicksort(int *array, size_t n,  size_t lb, size_t ub)
{
	size_t end_posi;

	if (lb < ub)
	{
		end_posi = partition(array, n, lb, ub);
		quicksort(array, n, lb, end_posi - 1);
		quicksort(array, n,  end_posi + 1, ub);
	}
}

/**
 *quick_sort - sorts an array of integers in ascending order
 *using the Quick sort algorithm
 *@array: Array to be sorted
 *@size: Size of array
 *Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	size_t lb, ub;

	lb = 0;
	ub = size - 1;

	quicksort(array, size,  lb, ub);
}
