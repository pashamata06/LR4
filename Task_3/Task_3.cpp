#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для отображения контекстного меню
void showContextMenu() {
    cout << "\n--- Контекстное меню ---\n";
    cout << "Задание: упорядочить её строки по возрастанию наибольших элементов в\nстроках матрицы.\n";
    cout << "Выполнил: Бедункевич Павел Михайлович\n";
    cout << "Вариант: 4\n";
    cout << "-------------------------\n";
}

// Функция для нахождения максимального элемента в строке
double findMaxInRow(const vector<double>& row) {
    return *max_element(row.begin(), row.end());
}

// Функция для сравнения строк
bool compareRows(const vector<double>& row1, const vector<double>& row2) {
    return findMaxInRow(row1) < findMaxInRow(row2);
}

// Основная программа
int main() {
    showContextMenu();

    int n, m;
    cout << "Введите количество строк (N): ";
    cin >> n;
    cout << "Введите количество столбцов (M): ";
    cin >> m;

    vector<vector<double> > matrix(n, vector<double>(m));

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Сортировка строк матрицы по возрастанию максимального элемента в строке
    sort(matrix.begin(), matrix.end(), compareRows);

    // Вывод упорядоченной матрицы
    cout << "\nУпорядоченная матрица:\n";
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

