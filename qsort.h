//
// Created by Valera on 05.05.2020.
//

/**Функция быстрой сортировки*/

void qsort(int *array_B, int left, int right) {
    int pivot;
    int l_hold=left;
    int r_hold=right;
    pivot=array_B[left];
    while (left<right) {
        while ((array_B[right] >= pivot) && (left < right)) {
            right--;
        }
        if (left != right) {
            array_B[left] = array_B[right];
            left++;
        }
        while ((array_B[left] <= pivot) && (left < right)) {
            left++;
        }
        if (left != right) {
            array_B[right] = array_B[left];
            right--;
        }
    }
    array_B[left]=pivot;
    pivot=left;
    left=l_hold;
    right=r_hold;
    if (left < pivot) {
        qsort(array_B, left, pivot - 1);
    }
    if (right > pivot) {
        qsort(array_B, pivot + 1, right);
    }
}