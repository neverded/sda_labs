#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#define MAX 50
typedef struct {
    char a[MAX];
    int top;
} Stack;
void init(Stack *s) {
    s->top = -1;
}
bool is_empty(Stack *s) {
    return s->top == -1;
}
bool is_full(Stack *s) {
    return s->top == MAX - 1;
}
bool push(Stack *s, char c) {
    if (is_full(s)) {
        printf("Помилка: стек повний\n");
        return false;
    }
    s->a[++s->top] = c;
    return true;
}
bool pop(Stack *s, char *c) {
    if (is_empty(s)) {
        printf("Помилка: стек порожній\n");
        return false;
    }
    if (c) *c = s->a[s->top];
    s->top--;
    return true;
}
bool peak (Stack *s, char *c) {
    if (is_empty(s)) {
        printf("Помилка: стек порожній\n");
        return false;
    }
    if (c) *c = s->a[s->top];
    return true;
}
void clear(Stack *s) {
    s->top = -1;
}
bool check(const char *str, int *max) {
    Stack s;
    init(&s);
    int d = 0;
    *max = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            if (!push(&s, '(')) {
                clear(&s);
                return false;
            }
            d++;
            if (d > *max) *max = d;
        } else if (str[i] == ')') {
            char c;
            if (!pop(&s, &c)) {
                clear(&s);
                return false;
            }
            d--;
        }
    }
    bool ok = is_empty(&s);
    clear(&s);
    return true;
}
int main(void) {
    SetConsoleOutputCP(65001);
    const char *tests [] = {
        "((a + b) * (c - (d / (e + f))))",
        "(a + b)) * c",
        "((a + b) * c",
    };
    for (int i = 0; i < 3; i++){ 
        int max = 0;
        printf("Рядок: %s ->", tests[i]);
        if (check(tests[i], &max)) 
            printf("Коректно (глибина: %d)\n", max);
        else 
            printf("Некоректно\n");
        }
        printf("\n Тест граничних випадків:\n");
        Stack s;
        char c;
        init(&s);
        pop(&s, &c);
        int count = 0;
        for (int i = 0; i < 52; i++) {
            if (push(&s, '(')) count++;
        }
        printf("Додано елементів: %d\n", count);
        clear(&s);
        return 0;
    }
