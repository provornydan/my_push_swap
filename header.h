
#ifndef HEADER_H
# define HEADER_H
#define AC_RED     "\x1b[31m"
#define AC_GREEN   "\x1b[32m"
#define AC_YELLOW  "\x1b[33m"
#define AC_BLUE    "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN    "\x1b[36m"
#define AC_RESET   "\x1b[0m"

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
