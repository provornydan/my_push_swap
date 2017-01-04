
#ifndef HEADER_H
# define HEADER_H

typedef struct  s_list 
{
    struct s_list   *prev;
    struct s_list   *next;
    int             data;
    int             ord;
}               t_list;
#endif
