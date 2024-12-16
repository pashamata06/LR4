#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Функция для вывода меню
void printMenu() {
    cout << "=== Меню ===" << endl;
    cout << "1. Ввести размерность и элементы массива" << endl;
    cout << "2. Показать массив" << endl;
    cout << "3. Создать массив из четных элементов главной диагонали" << endl;
    cout << "4. Показать произведение элементов нового массива" << endl;
    cout << "5. Показать задание и автора" << endl;
    cout << "6. Выход" << endl;
    cout << "============" << endl;
}

// Функция для безопасного ввода чисел
int safeInput() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Попробуйте снова: ";
        } else {
            return value;
        }
    }
}

void enterMatrix(vector<vector<int>>& matrix, int& n, int& k) {
    cout << "Введите количество строк (n): ";
    n = safeInput();
    cout << "Введите количество столбцов (k): ";
    k = safeInput();

    matrix.resize(n, vector<int>(k));
    cout << "Введите элементы массива (построчно):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            matrix[i][j] = safeInput();
        }
    }
}

void displayMatrix(const vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        cout << "Матрица ещё не введена." << endl;
        return;
    }
    cout << "Матрица:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

void createDynamicArray(const vector<vector<int>>& matrix, vector<int>& dynamicArray, int n) {
    if (matrix.empty()) {
        cout << "Сначала нужно ввести матрицу." << endl;
        return;
    }
    dynamicArray.clear();
    for (int i = 0; i < n; ++i) {
        if (matrix[i][i] % 2 == 0) {
            dynamicArray.push_back(matrix[i][i]);
        }
    }
    if (dynamicArray.empty()) {
        cout << "На главной диагонали нет чётных элементов." << endl;
    } else {
        cout << "Динамический массив создан." << endl;
    }
}

void calculateAndDisplayProduct(const vector<int>& dynamicArray) {
    if (dynamicArray.empty()) {
        cout << "Динамический массив пуст." << endl;
        return;
    }
    long long product = 1;
    for (int elem : dynamicArray) {
        product *= elem;
    }
    cout << "Произведение элементов динамического массива: " << product << endl;
}

void displayInfo() {
    cout << "Задание: Создать динамический массив из чётных элементов главной диагонали." << endl;
    cout << "Автор: Иван Иванов." << endl;
    cout << "Вариант: 5." << endl;
}

int main() {
    vector<vector<int>> matrix;
    vector<int> dynamicArray;
    int n = 0, k = 0;

    while (true) {
        printMenu();
        cout << "Выберите пункт меню: ";
        int choice = safeInput();

        switch (choice) {
            case 1:
                enterMatrix(matrix, n, k);
                break;
            case 2:
                displayMatrix(matrix);
                break;
            case 3:
                createDynamicArray(matrix, dynamicArray, n);
                break;
            case 4:
                calculateAndDisplayProduct(dynamicArray);
                break;
            case 5:
                displayInfo();
                break;
            case 6:
                cout << "Выход из программы." << endl;
                return 0;
            default:
                cout << "Некорректный пункт меню. Попробуйте снова." << endl;
        }
    }
}
