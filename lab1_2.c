#include <stdio.h>

int main() {
    double x, y;

    printf("Введіть значення x: ");
    scanf("%lf", &x);

    if(x > 0 && x <=5) {
        y = x * x * x - 5 * x * x;
        printf("y(x) = %.lf\n", y);
    } else if ((x >= -32 && x < - 20 ) || x > 10) {
        y = x * x - 3;
        printf("y(x) = %.lf\n", y);
    } else {
        printf("Функція не визначенна для заданого x.\n");
    }
    return 0;
}