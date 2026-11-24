#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
typedef struct Node {
    char c;
    struct Node* next;
} Node;
typedef struct {
    Node* top;
} Stack;
void init(Stack *s) {
    s->top = NULL;
}
bool is_empty(Stack *s) {
    return s->top == NULL;
}
bool is_full(Stack *s) {
    return s == NULL;
}
bool push(Stack *s, char c) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) {
        printf("Помилка: немає пам'яті!\n");
        return false;
    }
    p->c = c;
    p->next = s->top;
    s->top = p;
    return true;
}
bool pop(Stack *s, char *c) {
    if (is_empty(s)) {
        printf("Помилка: стек порожній!\n");
        return false;
    }
    Node *p = s->top;
    if (c) *c = p->c;
    s->top = p->next;
    free(p);
    return true;
}
bool peek (Stack *s, char *c) {
    if (is_empty(s)) {
        printf("Помилка: стек порожній!\n");
        return false;
    }
    if (c) *c = s->top->c;
    return true;
}
void clear(Stack *s) {
    char c;
    while (!is_empty(s)) {
        pop(s, &c);
    }
}
bool check(const char *str, int *max) {
    Stack s;
    init(&s);
    int d = 0;
    *max = 0;
    for (int i = 0; str [i] != '\0'; i++) {
        if (str[i] == '('){
            if (!push(&s, '(')) {
                clear(&s);
                return false;
            }
            d++;
            if(d > *max) *max = d;
        } else if (str[i] == ')'){
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
    return ok;
}
int main(void) {
    SetConsoleOutputCP(65001);
    const char *tests[] = {
        "((a + b) * (c - (d / (e + f))))",
        "(a + b)) * c",
        "((a + b) * c"
    };
    for (int i = 0; i < 3; i++){
        int max = 0;
        printf("Рядок: %s -> ", tests[i]);
        if (check(tests[i], &max)) 
            printf("Коректно (глибина: %d)\n", max);
        else 
            printf("Некоректно\n");
    }
    printf("\nТест граничних випадків:\n");
    Stack s;
    char c;
    init(&s);
    pop(&s, &c);
    int count = 0;
    for(int i = 0; i < 52; i++) {
        if (push(&s, '(')) count++;
    }
    printf("Додано елементів: %d\n", count);
    clear(&s);
    return 0;
}
