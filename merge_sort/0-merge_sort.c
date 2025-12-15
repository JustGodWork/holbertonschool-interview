#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* merge_range - merge two sorted
* subarrays of @array using @aux
* @array: array to sort
* @aux: auxiliary buffer (same size as array)
* @left: starting index (inclusive)
* @mid: middle index
* @right: ending index (exclusive)
*/
static void merge_range(int *array, int *aux, size_t left,
size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;
	size_t left_size = mid - left;
	size_t right_size = right - mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, left_size);
	printf("[right]: ");
	print_array(array + mid, right_size);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			aux[k++] = array[i++];
		else
			aux[k++] = array[j++];
	}

	while (i < mid)
		aux[k++] = array[i++];

	while (j < right)
		aux[k++] = array[j++];

	/* copy back to original array */
	for (k = left; k < right; k++)
		array[k] = aux[k];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
* merge_sort_rec - recursive top-down merge sort
* @array: array to sort
* @aux: auxiliary buffer
* @left: starting index (inclusive)
* @right: ending index (exclusive)
*/
static void merge_sort_rec(int *array, int *aux,
	size_t left, size_t right)
{
	if (right - left < 2)
		return;

	/* left size should be <= right size */
	size_t mid = left + (right - left) / 2;

	merge_sort_rec(array, aux, left, mid);
	merge_sort_rec(array, aux, mid, right);
	merge_range(array, aux, left, mid, right);
}

/**
* merge_sort - sorts an array of integers
* in ascending order using
* the Merge Sort algorithm (top-down)
* @array: array to sort
* @size: number of elements in @array
*
* Only one malloc/free is used for the auxiliary buffer.
*/
void merge_sort(int *array, size_t size)
{
	int *aux;

	if (!array || size < 2)
		return;

	aux = malloc(sizeof(int) * size);
	if (!aux)
		return;

	merge_sort_rec(array, aux, 0, size);

	free(aux);
}
