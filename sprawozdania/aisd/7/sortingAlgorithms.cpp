#include "sortingAlgorithms.h"

void bubble_sort(int *nums, const int nums_length) {
    int prev_number;

    for (int i = 0; i < nums_length - 1; i++) {
        for (int j = 0; j < nums_length - 1; j++) {
            if(nums[i] > nums[i + 1]) {
                prev_number = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = prev_number;
            }
        }
    }
}

void insertion_sort(int *nums, const int nums_length) {
    int i, j, key;
    for (i = 1; i < nums_length; i++) {
        key = nums[i];
        j = i - 1;

        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

int partition(int *nums, int start, int end) {
    int pivot = nums[end];
    int i = start - 1;

    for (int j = start; j <= end -1; j++) {
        if (nums[j] < pivot) {
            i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    i++;
    int temp = nums[i];
    nums[i] = nums[end];
    nums[end] = temp;

    return i;
}

void quick_sort(int *nums, int start, int end) {
    if (end <= start) return;

    int pivot = partition(nums, start, end);

    quick_sort(nums, start, pivot - 1);
    quick_sort(nums, pivot + 1, end);
}

void merge(int array[], int left, int middle, int right) {
    int first_subarray_length = middle - left + 1;
    int second_subarray_length = right - middle;

    int *left_array = new int[first_subarray_length], *right_array = new int[second_subarray_length];

    for (int i = 0; i < first_subarray_length; i++) {
        left_array[i] = array[left + i];
    }

    for (int j = 0; j < second_subarray_length; j++) {
        right_array[j] = array[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < first_subarray_length && j < second_subarray_length) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < first_subarray_length) {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < second_subarray_length) {
        array[k] = right_array[j];
        j++;
        k++;
    }

    delete[] left_array;
    delete[] right_array;
}
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
