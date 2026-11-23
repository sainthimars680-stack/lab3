#include <stdio.h>
#include <math.h>

#define SIZE 5

/* Виведення масиву у форматі [a b c ...] */
void print_array(const char *title, const double *arr, int size)
{
    printf("%s: [", title);
    for (int i = 0; i < size; i++) {
        printf("%g", arr[i]);
        if (i < size - 1)
            printf(" ");
    }
    printf("]\n");
}

int main(void)
{
    /* Значення з завдання 1 (ті самі, що й у task1.c) */
    int    group   = 75;
    int    variant = 7;
    double course  = 3;

    /* Обчислення із завдання 1 */
    int    sum     = group + variant + (int)course;
    int    product = group * variant * (int)course;
    double trig    = (variant % 2 == 0) ? sin(sum) : cos(product);

    int    group_old = group;    /* зберігаємо початкові номери групи і курсу */
    double course_old = course;

    group   = sum;
    variant = product;
    course  = trig;

    /* Скорочене оголошення масиву: розмір визначається за кількістю елементів */
    double arr[] = {1, 2, group, variant, course};

    print_array("Масив до змін", arr, SIZE);

    /* Перезаписуємо перші два елементи: номер групи та номер курсу */
    arr[0] = group_old;
    arr[1] = course_old;

    /* Додаємо до кожного елемента номер варіанту (початковий, з журналу) */
    for (int i = 0; i < SIZE; i++)
        arr[i] += 7;   /* 7 - номер вашого варіанту */

    print_array("Масив після змін", arr, SIZE);

    return 0;
}