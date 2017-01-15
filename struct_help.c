#include "header.h"

int     check_repeat_s(sss *n, int size)
{
    int i;

    merge_sort_s(n, size);
    i = -1;
    while(++i < size - 1)
    {
        if(n[i].val == n[i + 1].val)
            return (0);
    }
    return (1);
}

int     add_push_number_s(char *str, t_list **new, t_list **now, sss *tab)
{
    int i;
    int n;
    short sign;
    long temp;

    i = -1;
    if(*str == '-')
        i++;
    temp = check_number(str, &i, new);
    if(sign)
        n = -n;
    if(temp > 2147483647 || temp < -2147483648)
        return(0);
    n = (int)temp;
    push_list(new, now, n);
    tab[(*now)->ord].val = n;
    tab[(*now)->ord].ord = (*now)->ord;
    return (1);
}

void    try_add_s(char **split, t_list **my_vars, sss *arr)
{
     while(*split)
        {
            if(!add_push_number_s(*split, &my_vars[0], &my_vars[1], arr))
                exit(print_error(&my_vars[0], &my_vars[2]));
            split++;
        }
}

void    copy_arr(sss *arr, int n)
{
    sss *temp;
    int i;

    i = -1;
    temp = malloc(sizeof(sss)*(n));
    while(++i < n)
        temp[i] = arr[i];
    i = -1;
    while(++i < n)
        arr[temp[i].ord].ord = i;
}

int    check_done(t_list *head)
{
    t_list *temp;

    temp = head;
    while(temp->next)
    {
        if(temp->data > temp->next->data)
            return(0);
        temp = temp->next;
    }
    return(1);
}
