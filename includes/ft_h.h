#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

void				get_input(t_node **a, int ac, char *av[]);
int					is_sorted(t_node *list);
void				free_list(t_node **list);
void				print_error();

int					swap(t_node **list);
int					push(t_node **from, t_node **to);
int					shift_up(t_node **list);
int					shift_down(t_node **list);
int					pop(t_node **list);

int					ft_atoi(const char *str);
int					size(t_node *list);
void				push_back(t_node **list, int data);
void				push_front(t_node **list, int data);
void				divide_in_b_case3(t_node **a,
		t_node **b, t_node **in_b, int len);

int					get_pivot(t_node *list, int num);
int					get_max(t_node *list);
int					get_min(t_node *list);

void				divide_in_a(t_node **a, t_node **b, t_node **in_b, int len);
int					divide_in_b(t_node **a, t_node **b, t_node **in_b);
int					solve_less_than_3(t_node **list, int num);

char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *str);
#endif
