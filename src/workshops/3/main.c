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

  int index_sublist_one = 0;
  int index_sublist_two = 0;
  int index_merged = left;

  while (index_sublist_one < sublist_one_length &&
         index_sublist_two < sublist_two_length) {
    if (sublist_one[index_sublist_one] <= sublist_two[index_sublist_two]) {
      unsorted_list[index_merged] = sublist_one[index_sublist_one];

      index_sublist_one++;
    } else {
      unsorted_list[index_merged] = sublist_two[index_sublist_two];

      index_sublist_two++;
    }

    index_merged++;
  }

  while (index_sublist_one < sublist_one_length) {
    unsorted_list[index_merged] = sublist_one[index_sublist_one];

    index_sublist_one++;
    index_merged++;
  }

  while (index_sublist_two < sublist_two_length) {
    unsorted_list[index_merged] = sublist_two[index_sublist_two];

    index_sublist_two++;
    index_merged++;
  }
}

// NOLINTNEXTLINE(misc-no-recursion)
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
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  int list[] = {5, 3, 8, 1, 6, 10, 7, 2, 4, 9};
  int list_size = sizeof(list) / sizeof(list[0]);

  printf("Given the list:\n");
  PrintList(list, list_size);

  MergeSort(list, 0, list_size - 1);

  printf("The sorted list is:\n");
  PrintList(list, list_size);

  return EXIT_SUCCESS;
}
