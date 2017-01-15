#include "header.h"

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

int     find_rotation(t_list *l1, t_list *l2, int n)
{
    t_list *f;
    t_list *s;

    f = l1;
    s = l2;
    while(1)
    {
        if(f->ord == n)
            return(1);
        f = f->next;
        if(s->ord == n)
            return(2);
        s = s->prev;
    }
}

void    make_rotation(t_list **list, int n)
{
    int res;
    
    res = find_rotation(list[0], list[1], n);
    if(res == 1)
    {
        while(list[0]->ord != n)
        {
            rotate_list(&list[0], &list[1]);
            ft_putstr("ra\n");
        }
    }
    else if(res == 2)
    {
         while(list[0]->ord != n)
        {
            reverse_rotate_list(&list[0], &list[1]);
            ft_putstr("rra\n");
        }
    }
    push_between(&list[0], &list[2], &list[3]);
    ft_putstr("pb\n");
    ++n;
    solve_puzzle(list, n);
}

void    get_them_back(t_list **list)
{
    while(list[2])
    {
         push_between(&list[2], &list[0], &list[1]);
         ft_putstr("pa\n");
    }
    free_list(&list[0], &list[2]);
    exit(0);
}

void    sort_two(t_list **list)
{
    if(list[0]->data > list[0]->next->data)
    {
        swap_list(&list[0]);
        ft_putstr("sa\n");
    }
    get_them_back(list);
}
