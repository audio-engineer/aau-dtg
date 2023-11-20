#include <stdio.h>
#include <stdlib.h>

void Merge(int unsorted_list[], int left, int middle, int right) {
  int sublist_one_length = middle - left + 1;
  int sublist_two_length = right - middle;

  int sublist_one[sublist_one_length];
  int sublist_two[sublist_two_length];

  for (int i = 0; i < sublist_one_length; i++) {
    sublist_one[i] = unsorted_list[left + i];
  }

  for (int j = 0; j < sublist_two_length; j++) {
    sublist_two[j] = unsorted_list[middle + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < sublist_one_length && j < sublist_two_length) {
    if (sublist_one[i] <= sublist_two[j]) {
      unsorted_list[k] = sublist_one[i];
      i++;
    } else {
      unsorted_list[k] = sublist_two[j];
      j++;
    }
    k++;
  }

  while (i < sublist_one_length) {
    unsorted_list[k] = sublist_one[i];
    i++;
    k++;
  }

  while (j < sublist_two_length) {
    unsorted_list[k] = sublist_two[j];
    j++;
    k++;
  }
}

void MergeSort(int unsorted_list[], int left, int right) {
  if (left < right) {
    int middle = left + (right - left) / 2;

    MergeSort(unsorted_list, left, middle);
    MergeSort(unsorted_list, middle + 1, right);

    Merge(unsorted_list, left, middle, right);
  }
}

void PrintList(int list[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", list[i]);
  }

  printf("\n");
}

int main() {
  int list[] = {5, 3, 8, 1, 6, 10, 7, 2, 4, 9};
  int list_size = sizeof(list) / sizeof(list[0]);

  printf("Given the list:\n");
  PrintList(list, list_size);

  MergeSort(list, 0, list_size - 1);

  printf("The sorted list is:\n");
  PrintList(list, list_size);

  return EXIT_SUCCESS;
}
