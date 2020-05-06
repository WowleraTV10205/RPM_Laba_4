#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <windows.h>
#include "qsort.h"
#include "random.h"
#include "psort.h"


using namespace std;

const int limit=100;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    unsigned int n_P, n_B;
    ofstream puzirek_gen, fast_gen, puzirek_res, fast_res;
    puzirek_gen.open("puzirek_gen.txt");
    if (!puzirek_gen.is_open()) {
        return 11; // выход в случае неудачи открытия файла для записи первого исходного массива
    }
    cout << "Размерность массива для метода пузырька: " << endl;
    cin >> n_P;
    int *array_P = new int[n_P];
    srand(static_cast<unsigned int>(time(NULL)));
    for(int i=0; i<n_P; i++) {
        /**
         Вызов функции заполнения массива рандомным числом
         */
        array_P[i] = random(-limit, limit);
    }
    puzirek_gen << "Создать массив для сортировки методом пузырька: " << endl;
    for (int i=0; i<n_P; i++) {
        puzirek_gen << array_P[i] << " ";
    }
    puzirek_gen.close();
    double t1 = clock();
    /**
     Вызов функции сортировки пузырьком
     */
    psort(array_P, n_P);
    cout << "Затраченное время на выполнение сортировки методом пузырька: " << (clock()-t1) / CLOCKS_PER_SEC << endl;
    puzirek_res.open("puzirek_res.txt");
    if (!puzirek_res.is_open()) {
        return 12; // выход в случае неудачи открытия файла для записи результата сортировки пузырьком
    }
    puzirek_res << "Массив, отсортированный методом пузырьком: " << endl;
    for (int i=0; i<n_P; i++) {
        puzirek_res << array_P[i] << " ";
    }
    puzirek_res.close();
    delete [] array_P;
    cout << "Размерность массива для быстрой сортировки: " << endl;
    cin >> n_B;
    int *array_B = new int[n_B];
    for(int i=0; i<n_P; i++) {
        /**
         Вызов функции заполнения массива рандомным числом
         */
        array_B[i] = random(-limit, limit);
    }
    fast_gen.open("fast_gen.txt");
    if (!fast_gen.is_open()) {
        return 13; // выход в случае неудачи открытия файла для записи второго исходного массива
    }
    fast_gen << "Создать массив для быстрой сортировки: " << endl;
    for (int i=0; i<n_B; i++) {
        fast_gen << array_B[i] << " ";
    }
    fast_gen.close();
    double t2 = clock();
    /**
     Вызов функции быстрой сортировки
     */
    qsort(array_B, 0, n_B-1);
    cout << "Затраченное время на выполнение быстрой сортировки: " << (clock()-t2) / CLOCKS_PER_SEC << endl;
    fast_res.open("fast_res.txt");
    if (!fast_res.is_open()) {
        return 14; // выход в случае неудачи открытия файла для записи результата быстрой сортировки
    }
    fast_res << "Массив, отсортированный быстрой сортировкой: " << endl;
    for (int i=0; i<n_P; i++) {
        fast_res << array_P[i] << " ";
    }
    fast_res.close();
    delete [] array_B;
    return 0;
}