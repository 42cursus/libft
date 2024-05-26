/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:57:00 by abelov            #+#    #+#             */
/*   Updated: 2023/11/20 21:57:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	lbchange(t_fp *fp, size_t newsize, int flag)
{
	unsigned char	*ptr;
	size_t			diff;

	if ((newsize <= (size_t)fp->lbf._size) && !flag)
		return (0);
	else if (!flag)
	{
		diff = newsize - (size_t) fp->lbf._size;
		if (diff > OPTIMISTIC)
			newsize = (size_t)fp->lbf._size + (diff * 3);
		else
			newsize += OPTIMISTIC;
	}
	ptr = (unsigned char *)ft_reallocarray(fp->lbf._base,
			fp->lbf._size, newsize, sizeof(char));
	if (!ptr)
	{
		fp->lbf._base = NULL;
		fp->lbf._size = 0;
		return (-1);
	}
	fp->lbf._base = ptr;
	fp->lbf._size = newsize;
	fp->lbf._base[newsize - 1] = '\0';
	return (0);
}

void	*ft_reallocarray(void *ptr,
						size_t oldnmemb, size_t newnmemb, size_t size)
{
	void			*new_ptr;
	const size_t	newsize = newnmemb * size;
	const size_t	oldsize = oldnmemb * size;

	if (!ptr)
	{
		ptr = malloc(newsize);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if ((oldsize / size) != oldsize || ((newsize / size) != newsize))
		return (NULL);
	new_ptr = malloc(newsize);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (newsize > oldsize)
		ft_memcpy(new_ptr, ptr, oldsize);
	else
		ft_memcpy(new_ptr, ptr, newsize);
	free(ptr);
	return (new_ptr);
}

int	get_str(t_fp *fp, size_t len, size_t offset)
{
	unsigned char	*p;

	p = ft_memchr(fp->ptr, '\n', fp->_r);
	if (!p)
		return (0);
	len = ++p - fp->ptr;
	if (lbchange(fp, offset + len + 1, DO_SHRINK))
		return (-1);
	(void)ft_memcpy(fp->lbf._base + offset, fp->ptr, len);
	fp->lbf._base[offset + len] = '\0';
	fp->_r -= (int)(p - fp->ptr);
	fp->ptr = p;
	return (1);
}
