#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "header.h"
#include "merge2.c"

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
    temp = check_number(str, &i);
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
                exit(print_error());
            split++;
        }
}

void    change_ord(t_list **head, sss *arr, int size)
{
    int i;
    t_list *t;

    i = -1;
    t = *(head);
    while(++i < size)
    {
        t->ord = arr[i].ord;
        t = t->next;
    }
}

int     main(int argc, char **argv)
{
    t_list  **my_vars;
    char    *str;
    char    **split;    
    sss *arr;
    int n;

    n = count_words(argv);
    my_vars = (t_list**)malloc(sizeof(t_list*)*4);
    reset_tails(my_vars);
    arr = malloc(sizeof(sss)*(n));
    if (argc < 2)
        return(0);
    while(*(++argv))
    {
        split = ft_split_whitespaces(*argv);
        try_add_s(split, my_vars, arr);
    }
    if(!check_repeat_s(arr, n))
        return(print_error());
    t_list *try = my_vars[0];
/*    while(try)
    {
        printf("val:%10d  ord:%10d\n",try->data,try->ord);
        try = try->next;
    }*/
    printf("\n\n\n\n");
    for(int i =0; i<n; i++)
    {
        printf("val:%10d  ord:%10d\n",arr[i].val,arr[i].ord);
    }
    change_ord(&my_vars[0], arr, n);
    try = my_vars[0];
/*    while(try)
    {
        printf("val:%10d  ord:%10d\n",try->data,try->ord);
        try = try->next;
    }*/
}
