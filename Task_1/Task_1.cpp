#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Функция для проверки упорядоченности массива по убыванию
bool isSortedDescending(const vector<int>& arr) {
    return is_sorted(arr.rbegin(), arr.rend());
}

// Функция для отображения контекстного меню
void showContextMenu() {
    cout << "\n--- Контекстное меню ---\n";
    cout << "Задание: Определить, упорядочены ли элементы массива по убыванию.\n";
    cout << "Бедункевич Павел Михайлович\n";
    cout << "Вариант: 4\n";
    
}

int main() {
    while (true) {
        // Отображение контекстного меню
        showContextMenu();

        // Ввод размера массива
        int k;
        cout << "Введите размер массива (целое число > 0): ";
        cin >> k;

        // Проверка корректности ввода размера массива
        if (cin.fail() || k <= 0) {
            cin.clear(); // Очистка состояния ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорирование некорректного ввода
            cout << "Ошибка: введите положительное целое число!\n";
            continue;
        }

        // Динамическое выделение памяти для массива
        vector<int> arr(k);

        // Ввод элементов массива
        cout << "Введите элементы массива (целые числа): ";
        for (int i = 0; i < k; ++i) {
            cin >> arr[i];
            // Проверка корректности ввода элемента массива
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка: введите только целые числа!\n";
                i--; // Повторный ввод текущего элемента
            }
        }

        // Проверка упорядоченности массива
        bool sorted = isSortedDescending(arr);

        // Вывод результата
        cout << "\nИсходный массив: ";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << "\nРезультат: ";
        if (sorted)
            cout << "Массив упорядочен по убыванию.\n";
        else
            cout << "Массив не упорядочен по убыванию.\n";

        // Повторное выполнение программы
        char choice;
        cout << "\nХотите повторить? (y/n): ";
        cin >> choice;
        if (tolower(choice) != 'y') {
            cout << "Программа завершена.\n";
            break;
        }
    }

    return 0;
}

