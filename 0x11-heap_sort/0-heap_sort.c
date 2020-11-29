#include "sort.h"
/**
 * check_tree - swiftdown check
 * @arr: pointer to array
 * @size: size of the pointer
 * @size_i: original size of the array
 * @i: index as a root of the tree
 *
 **/
void check_tree(int *arr, size_t size_i, size_t size, size_t i)
{

	int n, brch1, brch2, c1, c2;
	size_t br1, br2;

	br1 = i * 2 + 1;
	br2 = br1 + 1;
	brch1 = arr[br1];
	brch2 = arr[br2];
	(void) c1;
	(void) c2;

	c1 = (br1 < size) && (br2 < size) && (brch1 >= brch2 && brch1 > arr[i]);
	c2 = (br1 == size - 1) && brch1 > arr[i];

	if (c1 || c2)
	{
		n = arr[i];
		arr[i] = brch1;
		arr[br1] = n;
		print_array(arr, size_i);
	}


	if ((br1 < size) && (br2 < size) && (brch2 > brch1 && brch2 > arr[i]))
	{
		n = arr[i];
		arr[i] = brch2;
		arr[br2] = n;
		print_array(arr, size_i);
	}


	if (br1 < size - 1)
		check_tree(arr, size_i, size, br1);

	if (br2 < size - 1)
		check_tree(arr, size_i, size, br2);
}
/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap
 * sort algorithm
 * @array: pointer to array
 * @size: size of the pointer
 *
 **/
void heap_sort(int *array, size_t size)
{
	size_t i, size_i = size;
	int n;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, size_i, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_i - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_i);
		check_tree(array, size_i, size - i - 1, 0);
	}

}
