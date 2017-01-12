#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "header.h"
#include "merge.c"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *c)
{
    int i;

    i = -1;
    while(*(c + ++i))
        ft_putchar(*(c + i));
}

int     check_repeat(int *n, int size)
{
    int i;

    merge_sort(n, size);
    i = -1;
    while(++i < size - 1)
    {
        if(n[i] == n[i + 1])
            return (0);
    }
    return (1);
}

long     check_number(char *str, int *i)
{
    long num;
    short sign;

    sign = 1;
    num = 0;
    if(*(str + *i) == '-')
        sign = -1;
    *i = *i + 1;
    while(*(str + *i))
    {
        if(*(str + *i) >= '0' && *(str + *i) <= '9')
        {
            num = num * 10;
            num+= (*(str + *i) - '0')*sign; 
        }
        else
            exit(print_error());
        if(sign == -1 && num > 0)
            num = -num;
        if(*i == 12)
            exit(print_error());
        *i = *i + 1;
    }
    return (num);
}

int     add_push_number(char *str, t_list **new, t_list **now, int *tab)
{
    int i;
    int n;
    short sign;
    long temp;

    i = -1;
    if(*str == '-')
        i++;
    temp = check_number(str, &i);
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

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while (*(s1 + i) && *(s1 + i) == *(s2 + i))
        i++;
    return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
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
int    compare_string(char *str, t_list **list)
{
    if(!ft_strcmp(str, "sa"))
        swap_list(&list[0]);
    else if(!ft_strcmp(str, "sb"))
        swap_list(&list[2]);
    else if(!ft_strcmp(str, "ss"))
        swap_both(&list[0], &list[2]);
    else if(!ft_strcmp(str, "pa"))
        push_between(&list[2], &list[0], &list[1]);
    else if(!ft_strcmp(str, "pb"))
        push_between(&list[0], &list[2], &list[3]);
    else if(!ft_strcmp(str, "ra"))
        rotate_list(&list[0], &list[1]);
    else if(!ft_strcmp(str, "rb"))
        rotate_list(&list[2], &list[3]);
    else if(!ft_strcmp(str, "rr"))
        rotate_both(&list[0], &list[1], &list[2], &list[3]);
    else if(!ft_strcmp(str, "rra"))
        reverse_rotate_list(&list[0], &list[1]);
    else if(!ft_strcmp(str, "rrb"))
        reverse_rotate_list(&list[2], &list[3]);
    else if(!ft_strcmp(str, "rrr"))
        reverse_both(&list[0], &list[1], &list[2], &list[3]);
    else 
        return(0);
    return(1);
}
void     check_solved(t_list **list)
{
    t_list *try;
    int temp;

    if(list[2] != NULL)
    {
        ft_putstr("KO\n");
        return ;
    }
    try = list[0];
    temp = try->data;
    while(try)
    {
       if(try->data < temp)
       {
           ft_putstr("KO\n");
           return ;
       }
       temp = try->data;
       try = try->next;
    }
    ft_putstr("OK\n");
}

int     print_error(void)
{
        write(1, AC_RED, 5);
        ft_putstr("Error\n");
        write(1, AC_RESET, 4);
        return(0);
}
void    reset_tails(t_list **my_vars)
{
    my_vars[1] = NULL;
    my_vars[2] = NULL;
    my_vars[3] = NULL;
}

void    try_add(char **split, t_list **my_vars, int *arr)
{
     while(*split)
        {
            if(!add_push_number(*split, &my_vars[0], &my_vars[1], arr))
                exit(print_error());
            split++;
        }
}

void   cont_help(int *count, int *temp)
{
    *count = *count + 1;
    *temp = 0;
}
int    count_words(char **argv)
{
    int i;
    int j;
    int count;
    int temp;

    i = 0;
    count = 0;
    while(*(argv + ++i))
    {
        j = -1;
        temp = 0;
        while(argv[i][++j])
        {
            if(argv[i][j] != ' ' && argv[i][j] != '\t')
            {
                if(!argv[i][j+1])
                    count++;
                temp++;
            }
            else if(temp != 0)
                cont_help(&count, &temp);
        }
    }
    return(count);
}

/*int     main(int argc, char **argv)
{
    t_list  **my_vars;
    char    *str;
    char    **split;    
    int *arr;
    int n;

    n = count_words(argv);
    my_vars = (t_list**)malloc(sizeof(t_list*)*4);
    reset_tails(my_vars);
    arr = malloc(sizeof(int)*n);
    if (argc < 2)
        return(0);
    while(*(++argv))
    {
        split = ft_split_whitespaces(*argv);
        try_add(split, my_vars, arr);
    }
    if(!check_repeat(arr, n))
            return(print_error());
    while(str = get_next_line(0))
        if(!compare_string(str, my_vars))
            return(print_error());
    check_solved(my_vars);
}*/
