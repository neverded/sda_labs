#include <stdio.h>

int main() {
    double x, y;

    printf("Введіть значення x: ");
    scanf("%lf", &x);

    if(x >10) {
        y = x * x - 3;
        printf("y(x) = %.lf\n", y);
    } else if (x > 5) {
        printf("Функція не визначенна для заданого x.\n");
    } else if (x >0) {
        y = x * x * x - 5 * x * x;
        printf("y(x) = %.lf\n", y);
    } else if (x >= -20) {
        printf("Функція не визначенна для заданого x.\n");
    } else if (x >= -32) {
        y = x * x - 3;
        printf("y(x) = %.lf\n", y);
    } 
    else {
        printf("Функція не визначенна для заданого x.\n");
    }

    return 0;
}