/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:26:24 by abelov            #+#    #+#             */
/*   Updated: 2023/11/20 17:48:03 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Counts the number of nodes in a list.
 */
int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

/**
 * Takes as a parameter a node and frees the memory of the node's content using
 * the function 'del' given as a parameter and free the node.
 * The memory of 'next' must not be freed.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/**
 * Deletes and frees the given node and every successor of that node,
 * using the function 'del' and free(3).
 * Finally, the pointer to the list must be set to NULL.
 *
 * Parameters:
 * 		lst: The address of a pointer to a node.
 * 		del: The address of the function used to delete the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}

/**
 * Iterates the list 'lst' and applies the function 'f' on the content
 * of each node.
 *
 * Parameters:
 * 		lst: The address of a pointer to a node.
 * 		f: The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}

/**
 * Iterates the list 'lst' and applies the function 'f' on the content of
 * each node. Creates a new list resulting of the successive applications of
 * the function 'f'.
 * The 'del' function is used to delete the content of a node if needed.
 *
 * Parameters:
 * 		lst: The address of a pointer to a node.
 * 		f: The address of the function used to iterate on the list.
 * 		del: The address of the function used to delete the content
 * 			of a node if needed.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	current = lst;
	new = ft_lstnew(f(current->content));
	if (!new)
		return (NULL);
	head = new;
	current = lst->next;
	while (current)
	{
		new->next = ft_lstnew(f(current->content));
		if (!new->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new = new->next;
		current = current->next;
	}
	return (head);
}
