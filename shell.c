#include <stdio.h>

// Функция сортировки методом Шелла
void shellSort(int arr[], int n){
    for(int gap = n/2; gap > 0; gap /= 2){
        // Проходим по каждому элементу массива
        for(int i = gap; i < n; i++){
            int temp = arr[i];
            int j;
            // Сдвигаем элементы, чтобы найти правильное место для вставки текущего элемента
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            // Вставляем текущий элемент в правильное место
            arr[j] = temp;
        }
    }
}

int main(){
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите элементы массива: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    shellSort(arr, n);

    printf("Отсортированный массив: ");
    for(int i=0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
