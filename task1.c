#include <stdio.h>
#include <math.h>

/*
 * Функція отримує АДРЕСИ трьох змінних з main (вказівники),
 * тому, змінюючи значення через розіменування (*), вона змінює
 * саме оригінальні змінні з main.
 */
void Calculations(int *group, int *variant, double *course)
{
    int    sum     = *group + *variant + (int)(*course);
    int    product = *group * *variant * (int)(*course);
    double trig;

    /* Парний варіант - синус суми, непарний - косинус добутку */
    if (*variant % 2 == 0)
        trig = sin(sum);
    else
        trig = cos(product);

    /* Записуємо результати у вихідні змінні через розіменування */
    *group   = sum;      /* група   -> сума       */
    *variant = product;  /* варіант -> добуток    */
    *course  = trig;     /* курс    -> sin/cos    */
}

int main(void)
{
    int    group   = 79;  
    int    variant = 16;   
    double course  = 4;  

    printf("Початкові значення: група = %d, варіант = %d, курс = %g\n",
           group, variant, course);

    Calculations(&group, &variant, &course);

    printf("Нові значення: група = %d, варіант = %d, курс = %f\n",
           group, variant, course);

    return 0;
}