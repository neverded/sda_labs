#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main (void) {
    int n;
    double x;
    printf("=== Програма 2: Динамічне програмування ===\n");
    printf("Введіть натуральне число n (n >= 1): ");
    if (scanf("%d", &n) != 1 || n < 1){
        printf("Помилка: n має бути натуральним числом (n >= 1).\n");
        return 1;
    }
    printf("Ввведіть значення аргументу x(у радіанах): ");
    if (scanf("%lf", &x) != 1) {
        return 1;
    }
    for (int k = -n; k <= n; k++) {
        if (fabs(x + k * PI) < 1e-12) {
            printf("Помилка: знаменник перетворюється на нуль при i = %d.\n",k);
            return 1;
        }
    }
    long long ops = 0;
    double P = 0.5;
    ops += 1;
    double signed_sum = -n * PI;
    ops += 3;
    int i= -n;
    ops += 2;
    while(1) {
        ops +=1;
        if (!(i <= n)) {
            break;
        }
        double num = 2.0 * x - signed_sum;
        ops +=3;
        double den =x + signed_sum;
        ops += 2;
        P *= num / den;
        ops += 3;
        signed_sum += PI;
        ops += 2;
        i++;
        ops += 1;
    }
    double exact = cos(x);
    double error = fabs(P - exact);
    printf("Наближене значення P (cos(%.4f)) = %.7lf\n", x, P);
    printf("Точне значення cos(%.4f) = %.7lf\n", x, exact);
    printf("Абсолютна похибка |P - cos(x)| = %.7lf\n", error);
    printf("Кількість виконаних операцій = %lld\n", ops);
    return 0;
}