#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int *t;
    int max_size;
    int size;
}tab;

void    resize(tab *arr, int new_size)
{
    arr->t = realloc(arr->t, sizeof(int) * new_size);
    arr->max_size = new_size;
}

void    append(tab *arr, int value)
{
    if (arr->size + 1 > arr->max_size)
    {
        resize(arr, arr->max_size * 2);
    }
    (arr->t)[arr->size] = value;
    arr->size++;
}

int     len(tab *arr)
{
    return (arr->size);
}

void    ft_remove(tab *arr)
{
    arr->size--;
}

int     pop(tab *arr)
{
    arr->size--;
    return ((arr->t)[arr->size]);
}

void    show_tab(tab *arr)
{
    printf("[ ");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", (arr->t)[i]);
    }
    printf("]\n");
}

int     main(void)
{
    tab array = (tab){malloc(sizeof(int) * 4), 4, 0};
    for (int i = 1; i <= 20; i++)
    {
        append(&array, i);
    }
    printf("%d\n", len(&array));
    show_tab(&array);
    ft_remove(&array);
    show_tab(&array);
    printf("%d\n", pop(&array));
    show_tab(&array);
    free(array.t);
}
