//
// Created by Valera on 05.05.2020.
//


/**Функция заполнения элемента массива случайным числом*/

int random(int range_min, int range_max) {
    return rand() % (range_max - range_min + 1) + range_min;
}