#include "header.h"

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

long     check_number(char *str, int *i, t_list **new)
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
            exit(print_error(new, new));
        if(sign == -1 && num > 0)
            num = -num;
        if(*i == 12)
            exit(print_error(new, new));
        *i = *i + 1;
    }
    return (num);
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