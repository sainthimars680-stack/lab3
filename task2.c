#include <stdio.h>

/* Рекурсивне обчислення суми цифр числа (без циклів) */
int sum_of_digits(int n)
{
    /* Від'ємне число: працюємо з модулем */
    if (n < 0)
        return sum_of_digits(-n);

    /* Базовий випадок: число однозначне - сума цифр дорівнює йому самому */
    if (n < 10)
        return n;

    /* Крок рекурсії: остання цифра + сума цифр числа без останньої цифри */
    return n % 10 + sum_of_digits(n / 10);
}

int main(void)
{
    int n;

    printf("Введіть ціле число: ");
    if (scanf("%d", &n) != 1) {
        printf("Помилка введення!\n");
        return 1;
    }

    printf("Сума цифр числа %d дорівнює: %d\n", n, sum_of_digits(n));

    return 0;
}