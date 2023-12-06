/*Даны целые положительные числа M и N.
Сформировать целочисленную матрицу размера M × N,
у которой все элементы I -й строки имеют значение 10·I (I = 1, . . ., M ). */
#include <iostream>

int main() {
    using namespace std;
    setlocale(LC_ALL, "ru");
    int M, N;
    cout << "Введите количество строк M: ";
    cin >> M;
    cout << "Введите количество столбцов N: ";
    cin >> N;
    if (M <= 0 || N <= 0) {
        cerr << "Ошибка: некорректные значения M и N." << endl;
        return 1;
    }
    // Выделение памяти для матрицы
    int** matrix = new int* [M];

    // Заполнение первой строки матрицы
    matrix[0] = new int[N];
    for (int j = 0; j < N; ++j) {
        matrix[0][j] = 10 * (j+1);
    }

    // Заполнение остальных строк матрицы значением 0
    for (int i = 1; i < M; ++i) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = 0;
        }
    }

    // Вывод матрицы
    cout << "Сформированная матрица:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Освобождение выделенной памяти
    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
