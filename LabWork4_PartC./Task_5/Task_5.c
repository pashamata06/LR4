#include <stdio.h>

// Функция для отображения контекстного меню
void displayMenu() {
    printf("Лабораторная работа No4\n");
    printf("Выполнил: Бедункевич Павел Михайлович\n");
    printf("Группа: 453505\n");
    printf("Задание: Дополнить поле числами, как в оригинальной игре САПЕР.\n");
    printf("===========================================\n");
}

// Функция для проверки соседних клеток и подсчета бомб
int countBombs(char field[][100], int x, int y, int n, int m) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Смещения по строкам
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // Смещения по столбцам
    int count = 0;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && field[nx][ny] == '*') {
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;

    // Отображение контекстного меню
    displayMenu();

    // Ввод размеров поля
    printf("Введите размеры поля (n m): ");
    scanf("%d %d", &n, &m);

    char field[100][100];
    char result[100][100];

    // Ввод поля
    printf("Введите поле (строки с символами '.' и '*'):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", field[i]);
    }

    // Обработка поля
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                result[i][j] = '*';
            } else {
                result[i][j] = countBombs(field, i, j, n, m) + '0';
            }
        }
    }

    // Вывод результата
    printf("Результирующее поле:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
