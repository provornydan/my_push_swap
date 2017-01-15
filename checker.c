#include "header.h"

int     main(int argc, char **argv)
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
            return(print_error(&my_vars[0], &my_vars[2]));
    while(str = get_next_line(0))
        if(!compare_string(str, my_vars))
            return(print_error(&my_vars[0], &my_vars[2]));
    check_solved(my_vars);
    free(arr);
    free_list(&my_vars[0], &my_vars[2]);
}
