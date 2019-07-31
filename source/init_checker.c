#include "header.h"

void    reset_tails(t_list **my_vars)
{
    my_vars[0] = NULL;
    my_vars[1] = NULL;
    my_vars[2] = NULL;
    my_vars[3] = NULL;
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