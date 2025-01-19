/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:05:48 by abelov            #+#    #+#             */
/*   Updated: 2024/06/02 09:22:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>

typedef struct s_list	t_list;
struct s_list
{
	union
	{
		char	*str;
		void	*data;
		void	*content;
		int		nbr;
	};
	t_list	*next;
};

typedef struct s_iterator
{
	int	i;
	int	j;
}					t_iter;

typedef struct s_list_swap
{
	t_list	*tmp;
	t_list	*el1;
	t_list	*el2;
}		t_list_swap;

typedef __compar_fn_t	t_cmp_fun;
typedef struct s_list_fun
{
	t_cmp_fun	cmp_fun;
	void		(*del_fun)(void *);
	void		*(*dup_fun)(void *);
}	t_list_fun;

t_list	*ft_lstnew(void *data);
t_list	*ft_list_create_elem(void *content);
void	ft_list_destroy(t_list **list, void (*del_fun)(void *));
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_list_dup(t_list *list);
t_list	*ft_list_dup_fun(t_list *list, void *(*dup_fun)(void *));
void	ft_list_push_front(t_list **list, void *data);
int		ft_list_size(t_list *list);
t_list	*ft_list_last(t_list *list);
void	ft_list_push_back(t_list **list, void *data);
t_list	*ft_list_push_strs(int size, const char **strs);
void	ft_list_clear(t_list *list, void (*del_fun)(void *));
t_list	*ft_list_at(t_list *list, unsigned int nbr);
void	ft_list_reverse(t_list **list);
void	ft_list_foreach(t_list *list, void (*f)(void *));
void	ft_list_foreach_if(t_list *list, void (*f)(void *), void *data_ref,
			int (*cmp)(void *, void *));
void	ft_list_foreach_ref(t_list *list,
			void (*f)(void *, void *), void *ref);
t_list	*ft_list_find(t_list *list, void *data_ref,
			int (*cmp)(void *, void *));
int		ft_list_starts_with(t_list *head, t_list *sub, __compar_fn_t cmp);
t_list	*ft_list_find_sublist(t_list *list, t_list *sub_list,
			__compar_fn_t cmp);
void	ft_list_remove_if(t_list **list, void *data_ref,
			int (*cmp)(void *, void *), void (*del_fun)(void *));
void	ft_list_prepend(t_list **lst, t_list *new);
void	ft_list_concat(t_list **list1, t_list *list2);
void	ft_list_sort(t_list **list, int (*cmp)(void *, void *));
void	ft_list_reverse_fun(t_list *list);
void	ft_sorted_list_insert(t_list **list, void *data,
			int (*cmp)(void *, void *));
void	ft_sorted_list_merge(t_list **list1, t_list *list2,
			int (*cmp)(void *, void *));
void	ft_list_reverse_fun(t_list *list);
void	ft_list_remove_sublist(t_list **list, t_list *sub_list,
			__compar_fn_t cmp, void (*del_fun)(void *));
void	ft_list_replace_sublist(t_list **list, t_list *to_find,
			t_list *to_replace_with, t_list_fun *lst_fun);
#endif //FT_LIST_H
