#include "header.h"

void    solve_puzzle(t_list **list, int n)
{
    if(check_done(list[0]))
        get_them_back(list);
    if(list[0]->next == NULL)
        return ;
    if(list[0]->next->next == NULL)
        sort_two(list);
    else
        make_rotation(list, n);
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
        return(print_error(&my_vars[0], &my_vars[2]));
    copy_arr(arr, n);
    change_ord(&my_vars[0], arr, n);
    solve_puzzle(my_vars, 0);
    free(arr);
    free_list(&my_vars[0], &my_vars[2]);
}
