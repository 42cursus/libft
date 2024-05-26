/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:05:48 by abelov            #+#    #+#             */
/*   Updated: 2024/05/21 03:05:49 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

typedef struct s_list	t_list;
struct s_list
{
	void	*data;
	t_list	*next;
};

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_list_push_front(t_list **list, void *data);
int		ft_list_size(t_list *list);
t_list	*ft_list_last(t_list *list);
void	ft_list_push_back(t_list **list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_clear(t_list *list, void (*del_fun)(void *));
t_list	*ft_list_at(t_list *list, unsigned int nbr);
void	ft_list_reverse(t_list **list);
void	ft_list_foreach(t_list *list, void (*f)(void *));
void	ft_list_foreach_if(t_list *list, void (*f)(void *), void *data_ref,
						   int (*cmp)(void *, void *));
t_list	*ft_list_find(t_list *list, void *data_ref,
						int (*cmp)(void *, void *));
void	ft_list_remove_if(t_list **list, void *data_ref,
						  int (*cmp)(void *, void *), void (*del_fun)(void *));
void	ft_list_merge(t_list **list1, t_list *list2);
void	ft_list_sort(t_list **list, int (*cmp)(void *, void *));
void	ft_list_reverse_fun(t_list *list);
void	ft_sorted_list_insert(t_list **list, void *data,
							  int (*cmp)(void *, void *));
void	ft_sorted_list_merge(t_list **list1, t_list *list2,
							 int (*cmp)(void *, void *));

#endif //FT_LST_H
