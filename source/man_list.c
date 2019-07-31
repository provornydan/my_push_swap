#include "header.h"

int     add_push_number(char *str, t_list **new, t_list **now, int *tab)
{
    int i;
    int n;
    short sign;
    long temp;

    i = -1;
    if(*str == '-')
        i++;
    temp = check_number(str, &i, new);
    if(temp > 2147483647 || temp < -2147483648)
        return(0);
    n = (int)temp;
    push_list(new, now, n);
    tab[(*now)->ord] = n;
    return (1);
}

void    rotate_list(t_list **head, t_list **tail)
{
   if(*head != NULL && (*head)->next != NULL)
   {
       *head = (*head)->next;
       (*head)->prev->next = NULL;
       (*head)->prev->prev = *tail;
       (*tail)->next = (*head)->prev;
       (*head)->prev = NULL;
       *tail = (*tail)->next;
   }
}

void    reverse_rotate_list(t_list **head, t_list **tail)
{
    if(*head != NULL && (*head)->next != NULL)
    {
        *tail = (*tail)->prev;
        (*head)->prev = (*tail)->next;
        (*tail)->next->prev = NULL;
        (*tail)->next->next = *head;
        *head = (*tail)->next;
        (*tail)->next = NULL;
    }
}

void    push_between(t_list **source, t_list **dest, t_list **tail)
{
    t_list *create;

    if(*source == NULL)
        return;
        create = (t_list *)malloc(sizeof(t_list));
        create->data = (*source)->data;
        create->ord = (*source)->ord;
        create->next = *dest;
        create->prev = NULL;
        if(*dest != NULL)
            (*dest)->prev = create;
        else
            *tail = create;
        *dest = create;
        if((*source)->next == NULL)
        {
            free(*source);
            *source = NULL;
        }
        else
        {
            *source = (*source)->next;
            free((*source)->prev);
            (*source)->prev = NULL;
        }
}

void    swap_list(t_list **head)
{
    if(*head != NULL && (*head)->next != NULL)
    {
        *head = (*head)->next;
        (*head)->prev->next = (*head)->next;
        (*head)->prev->prev = *head;
        if((*head)->next)
            (*head)->next->prev = (*head)->prev;
        (*head)->next = (*head)->prev;
        (*head)->prev = NULL;
    }
}