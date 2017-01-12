#ifndef HEADER_H
# define HEADER_H
#define AC_RED     "\x1b[31m"
#define AC_GREEN   "\x1b[32m"
#define AC_YELLOW  "\x1b[33m"
#define AC_BLUE    "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN    "\x1b[36m"
#define AC_RESET   "\x1b[0m"

#include <stdlib.h>
typedef struct  s_list 
{
    struct s_list   *prev;
    struct s_list   *next;
    int       data;
    int             ord;
}               t_list;

typedef struct  arrn
{
	int val;
	int ord; 
}				sss;

int     		my_len(char *);
char    		*my_realloc(char *,int);
char 			*get_next_line(const int);
int		fft_is_delimeter(char c);
char	*fft_strcpy(char *dest, char *src);
int		fft_advance(char **str);
void	fft_advance_whitespace(char **str);
char	**ft_split_whitespaces(char *str);
void    push_list(t_list **, t_list **, int);
void    swap_list(t_list **);
void    push_between(t_list **, t_list **, t_list **);
void    rotate_list(t_list **, t_list **);
int     add_push_number(char *, t_list **, t_list **, int *);
long     check_number(char *, int *);
int     check_repeat(int *, int);
void    ft_putchar(char);
void    ft_putstr(char *);
int     ft_strcmp(char *, char *);
void    check_solved(t_list **list);
int     compare_string(char *str, t_list **list);
void    swap_both(t_list **one, t_list **two);
void    rotate_both(t_list **o, t_list **t, t_list **f, t_list **p);
void    reverse_both(t_list **o, t_list **t, t_list **f, t_list **p);
int     print_error(void);
void    reset_tails(t_list **my_vars);
void    try_add(char **split, t_list **my_vars, int *arr);
void   cont_help(int *count, int *temp);
int    count_words(char **argv);
#endif
