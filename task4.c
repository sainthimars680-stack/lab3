#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n;

    printf("Введіть розмір масиву N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некоректний розмір масиву!\n");
        return 1;
    }

    int arr[n];  /* масив розміром N (VLA) */

    srand((unsigned)time(NULL));

    /* Заповнення масиву випадковими числами (тільки через вказівник) */
    for (int *p = arr; p < arr + n; p++)
        *p = rand() % 100;

    /* 1. Початковий масив та адреси елементів */
    printf("\n=== 1. Початковий масив ===\n");
    for (int *p = arr; p < arr + n; p++)
        printf("Елемент %3ld: значення = %d | адреса = %p\n",
               (long)(p - arr), *p, (void *)p);

    /* Пошук мінімального та максимального елементів */
    int *min_ptr = arr;
    int *max_ptr = arr;
    for (int *p = arr + 1; p < arr + n; p++) {
        if (*p < *min_ptr) min_ptr = p;
        if (*p > *max_ptr) max_ptr = p;
    }

    /* 2. Результати пошуку */
    printf("\n=== 2. Результати пошуку ===\n");
    printf("Мінімальний елемент: значення = %d | адреса = %p\n",
           *min_ptr, (void *)min_ptr);
    printf("Максимальний елемент: значення = %d | адреса = %p\n",
           *max_ptr, (void *)max_ptr);

    /* Обмін значеннями через розіменування */
    int tmp  = *min_ptr;
    *min_ptr = *max_ptr;
    *max_ptr = tmp;

    /* 3. Результуючий масив */
    printf("\n=== 3. Результуючий масив після обміну ===\n");
    for (int *p = arr; p < arr + n; p++)
        printf("Елемент %3ld: значення = %d | адреса = %p\n",
               (long)(p - arr), *p, (void *)p);

    return 0;
}