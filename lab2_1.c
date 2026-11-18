#include <stdio.h>
#include <math.h>
#ifdef _WIN32
#include <windows.h>
#endif
#define PI 3.14159265358979323846
int main(void) {
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n;
    double x;
    printf("=== Програма 1: Вкладені цикли (варіант 2) ===\n");
    printf("Введіть натурральне число n (n >= 1):");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Помилка: n має бути натуральним числом(n >= 1).\n");
        return 1;
    }
    printf("Введіть значення аргументу x (у радіанах):");
    if (scanf("%lf",&x) != 1) {
        printf("Помилка некоректного введення x.\n");
        return 1;
    }
    for (int k = -n; k <= n; k++) {
        if (fabs(x + k * PI) < 1e-12) {
            printf("Помилка: знаменник перетворюється на нуль при i = %d.\n", k);
            return 1;
        }
    }
    long long ops = 0;
    double P = 0.5;
    ops += 1;
    int i = -n;
    ops += 2;
    while (1) {
        ops += 1;
        if (!(i <= n)) {
            break;
        }
        int sgn, abs_i;
        ops += 1;
        if (i < 0) {
            sgn = -1;
            abs_i = -i;
            ops += 4;
        } else {
            ops += 1;
            if (i > 0) {
                sgn = 1;
                abs_i = i;
                ops += 2;
            } else {
                sgn = 0;
                abs_i = 0;
                ops += 2;
            }
        }
        double sum_pi = 0.0;
        ops += 1;
        int j = 1;
        ops += 1;
        while(1) {
            ops += 1;
            if (!(j <= abs_i)) {
                break;
            }
            sum_pi += PI;
            ops += 2;
            j++;
            ops += 1;
        }
        double num = 2.0 * x -sgn * sum_pi;
        ops += 4;
        double den = x +sgn * sum_pi;
        ops += 3;
        P*= num /den;
        ops += 3;
        i++;
        ops += 1;
    }
    double exact = cos(x);
    double error = fabs(P-exact);
    printf("Наближене значення P (cos(%.4f)) = %.7lf\n", x, P);
    printf("Еочне значення cos(%.4f) = %.7lf\n", x, exact);
    printf("Абсолютна похибка |P - cos(x)| = %.7lf\n", error);
    printf("Кількість виконаних операцій: %lld\n", ops);
    return 0;
}