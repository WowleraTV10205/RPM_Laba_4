//
// Created by Valera on 05.05.2020.
//


/** Функция сортировки пузырком */

void psort(int *array_P, int n_P) {
    int temp;
    for (int i=0; i<n_P; i++) {
        for(int j=0; j<n_P; j++) {
            if(array_P[j] > array_P[j+1]) {
                temp = array_P[j];
                array_P[j] = array_P[j + 1];
                array_P[j + 1] = temp;
            }
        }
    }
}