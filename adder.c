#include "header.h"

void    try_add(char **split, t_list **my_vars, int *arr)
{
     while(*split)
        {
            if(!add_push_number(*split, &my_vars[0], &my_vars[1], arr))
                exit(print_error(&my_vars[0], &my_vars[2]));
            split++;
        }
}

void    push_list(t_list **head, t_list **start, int data)
{
    if(*start == NULL)
    {
        *head = NULL;
        *start = (t_list*)malloc(sizeof(t_list));
        (*start)->prev = NULL;
        (*start)->next = NULL;
        (*start)->data = data;
        (*start)->ord = 0;
        *head = *start;
    }
    else
    {
        (*start)->next = (t_list *)malloc(sizeof(t_list));
        (*start)->next->prev = *start;
        *start = (*start)->next;
        (*start)->data = data;
        (*start)->ord = (*start)->prev->ord + 1;
        (*start)->next = NULL;
    }
}

void    swap_both(t_list **one, t_list **two)
{
    swap_list(one);
    swap_list(two);
}
void    rotate_both(t_list **o, t_list **t, t_list **f, t_list **p)
{
    rotate_list(o, t);
    rotate_list(f, p);
}
void    reverse_both(t_list **o, t_list **t, t_list **f, t_list **p)
{
    reverse_rotate_list(o, t);
    reverse_rotate_list(f, p);
}
