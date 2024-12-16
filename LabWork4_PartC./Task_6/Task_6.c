#include <stdio.h>

// Функция для отображения контекстного меню
void displayMenu() {
    printf("Лабораторная работа No4\n");
    printf("Выполнил: Бедункевич Павел Михайлович\n");
    printf("Группа: 453505\n");
    printf("Задание: Построить магический квадрат.\n");
    printf("===========================================\n");
}

// Функция для создания магического квадрата
void generate_magic_square(int n) {
    if (n % 2 == 0) {
        printf("Для четных чисел магический квадрат не построить.\n");
        return;
    }

    int magic_square[n][n];

    // Инициализация магического квадрата
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magic_square[i][j] = 0;
        }
    }

    int num = 1;
    int i = n / 2;
    int j = n - 1;

    while (num <= n * n) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n) {
                j = 0;
            }
            if (i < 0) {
                i = n - 1;
            }
        }

        if (magic_square[i][j] != 0) {
            j -= 2;
            i++;
            continue;
        } else {
            magic_square[i][j] = num++;
        }

        j++;
        i--;
    }

    // Печать магического квадрата
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", magic_square[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Отображение контекстного меню
    displayMenu();

    // Ввод размера магического квадрата
    printf("Введите размер магического квадрата : ");
    scanf("%d", &n);

    // Генерация магического квадрата
    generate_magic_square(n);

    return 0;
}