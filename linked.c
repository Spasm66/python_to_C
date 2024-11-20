#include <stdlib.h>
#include <stdio.h>

typedef struct linked {
    int             value;
    struct linked  *next;
} linked;

void show_list(linked *array) {
    linked *temp;

    temp = array;
    while (temp)
    {
        printf("%d\t", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void    link(linked *arr, int value)
{
    while (arr->next)
        arr = arr->next;
    arr->next = &(linked){value, NULL};
}

int main(void) {
    linked arr = (linked){1, &(linked){2, &(linked){3, NULL}}};
    link(&arr, 6);
    show_list(&arr);

    return 0;
}