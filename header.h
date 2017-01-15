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
#include <unistd.h>
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
long     check_number(char *, int *, t_list **);
int     check_repeat(int *, int);
void    ft_putchar(char);
void    ft_putstr(char *);
int     ft_strcmp(char *, char *);
void    check_solved(t_list **list);
int     compare_string(char *str, t_list **list);
void    swap_both(t_list **one, t_list **two);
void    rotate_both(t_list **o, t_list **t, t_list **f, t_list **p);
void    reverse_both(t_list **o, t_list **t, t_list **f, t_list **p);
int     print_error(t_list **, t_list **);
void    reset_tails(t_list **my_vars);
void    try_add(char **split, t_list **my_vars, int *arr);
void   cont_help(int *count, int *temp);
int    count_words(char **argv);
void    free_list(t_list **list1, t_list **list2);
void    reverse_rotate_list(t_list **head, t_list **tail);
int 	notations_s(int *n, int *mid, int *i);
void merge_s(sss *a,sss *l,int arr[2],sss *r);
void merge_sort_s(sss *a, int n);
int notations(int *n, int *mid, int *i);
void merge(int *a,int *l,int arr[2],int *r);
void merge_sort(int *a,int n);
void    solve_puzzle(t_list **list, int n);
int     check_repeat_s(sss *n, int size);
int     add_push_number_s(char *str, t_list **new, t_list **now, sss *tab);
void    try_add_s(char **split, t_list **my_vars, sss *arr);
void    change_ord(t_list **head, sss *arr, int size);
int     find_rotation(t_list *l1, t_list *l2, int n);
void    make_rotation(t_list **list, int n);
void    get_them_back(t_list **list);
int    check_done(t_list *head);
void    sort_two(t_list **list);
void    copy_arr(sss *arr, int n);

#endif
