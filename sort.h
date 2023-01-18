#ifndef SORT_H
#define SORT_H

#include<stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
		const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Project Functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* Helper Functions */
int *lickity_split(int *array, int lo, int hi, int size);
void freaky_friday(int *array, int jamie, int lindsay);

/* Phi Sig Functions */
void merge_sort(int *array, size_t size);
void print_my_array(int *array, int start, int end);
void copy_array(int *array, int start, int end, int *tmp_arr);
void recur_split(int *tmp_arr, int start, int end, int *array);
void time_to_merge(int *array, int start, int mid, int end, int *tmp_arr);

void swap(int *a, int *b);
void heapify(int *arr, int size_int, int i, size_t size);
void heap_sort(int *array, size_t size);

#endif /* SORT */
