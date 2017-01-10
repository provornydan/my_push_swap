
#ifndef HEADER_H
# define HEADER_H

typedef struct  s_list 
{
    struct s_list   *prev;
    struct s_list   *next;
    long long       data;
    int             ord;
}               t_list;

int     my_len(char *);
char    *my_realloc(char *,int);
char    *get_next_line(const int);
#endif
