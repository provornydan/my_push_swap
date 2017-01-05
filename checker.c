#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void    push_list(t_list **, t_list **, int);
void    swap_list(t_list **);
void    push_between(t_list **, t_list **);
void    rotate_list(t_list **, t_list **);

void    rotate_list(t_list **head, t_list **tail)
{
   if((*head)->next != NULL)
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
    if((*head)->next != NULL)
    {
        *tail = (*tail)->prev;
        (*head)->prev = (*tail)->next;
        (*tail)->next->prev = NULL;
        (*tail)->next->next = *head;
        *head = (*tail)->next;
        (*tail)->next = NULL;
    }
}

void    push_between(t_list **source, t_list **dest)
{
    t_list *create;

    if(*source != NULL)
    {
        create = (t_list *)malloc(sizeof(t_list));
        create->data = (*source)->data;
        create->ord = (*source)->ord;
        create->next = *dest;
        create->prev = NULL;
        if(*dest != NULL)
            (*dest)->prev = create;
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
}

void    swap_list(t_list **head)
{
    if((*head)->next != NULL)
    {
        *head = (*head)->next;
        (*head)->prev->next = (*head)->next;
        (*head)->prev->prev = *head;
        (*head)->next = (*head)->prev;
        (*head)->prev = NULL;

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
        *head = *start;
    }
    else
    {
        (*start)->next = (t_list *)malloc(sizeof(t_list));
        (*start)->next->prev = *start;
        *start = (*start)->next;
        (*start)->data = data;
        (*start)->next = NULL;
    }
}

int     main(int argc, char **argv)
{
    t_list *new;
    t_list *now;
    t_list *second_new;
    t_list *second_now;
    now = NULL;
    second_now = NULL;
    push_list(&new, &now, 7);
    push_list(&new, &now, 11);
    reverse_rotate_list(&new, &now);
    reverse_rotate_list(&new, &now);
    reverse_rotate_list(&new, &now);
 //   rotate_list(&new, &now);
    t_list *try = new;
    while(try)
    {
        printf("%d  ", try->data);
        try = try->next;
    } 

    if (argc < 2)
        return(0);  
}
