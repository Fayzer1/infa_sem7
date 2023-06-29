#include <stdio.h>
#include <stdlib.h>

// Функция для чтения строки
char* readString() {
    char* str = NULL; // Инициализируем указатель на строку как NULL
    char c;
    size_t size = 0;
    size_t len = 0;

    // Читаем символы до получения символа новой строки '\n'
    while ((c = getchar()) != '\n') {
        if (len + 1 >= size) {
            size *= 2; // Увеличиваем размер буфера в два раза

            // Выделяем новую память для увеличенного буфера
            char* newStr = (char*)malloc(size * sizeof(char));
            if (newStr == NULL) {
                free(str);
                return NULL;
            }

            // Копируем имеющиеся символы в новый буфер
            for (size_t i = 0; i < len; i++) {
                newStr[i] = str[i];
            }

            free(str); // Освобождаем старую память
            str = newStr; // Обновляем указатель на строку
        }

        str[len++] = c; // Добавляем символ в строку
    }

    // Создаем финальную строку с нулевым символом в конце
    char* newStr = (char*)malloc((len + 1) * sizeof(char));
    if (newStr == NULL) {
        free(str);
        return NULL;
    }
    for (size_t i = 0; i < len; i++) {
        newStr[i] = str[i];
    }
    newStr[len] = '\0'; // Добавляем нулевой символ в конец
    free(str);

    return newStr; // Возвращаем полученную строку
}

int main() {
    printf("Введите строку: ");
    char* str = readString(); // Читаем строку

    printf("Полученная строка: %s", str); // Выводим полученную строку

    free(str); // Освобождаем память

    return 0;
}
