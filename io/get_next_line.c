/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:56:33 by abelov            #+#    #+#             */
/*   Updated: 2023/11/20 21:56:35 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	makebuf(t_fp *fp)
{
	void	*p;

	p = malloc(BUFFER_SIZE);
	if (!p)
	{
		fp->_flags |= UN_BUF;
		fp->ptr = fp->nbuf;
		fp->sbf._base = fp->ptr;
		fp->sbf._size = 1;
		fp->_flags |= FOUND_ERR;
		return (-1);
	}
	fp->_flags |= MBF;
	fp->ptr = (unsigned char *)p;
	fp->sbf._base = p;
	fp->sbf._size = BUFFER_SIZE;
	return (0);
}

int	refill(t_fp *fp)
{
	if (!fp->sbf._base && makebuf(fp))
		return (EOF);
	fp->ptr = fp->sbf._base;
	fp->_r = read(fp->_file, (char *)fp->ptr, fp->sbf._size);
	fp->_flags &= ~SMOD;
	if (fp->_r <= 0)
	{
		if (fp->_r == 0)
			fp->_flags |= FOUND_EOF;
		else
		{
			fp->_r = 0;
			if (fp->_flags & MBF)
			{
				free(fp->lbf._base);
				fp->lbf._base = NULL;
				fp->lbf._size = 0;
			}
			fp->_flags |= FOUND_ERR;
		}
		return (EOF);
	}
	return (0);
}

t_fp	*sfp(int fd, t_fp *ptr)
{
	t_fp	*fp;

	if (!ptr)
	{
		fp = (t_fp *) malloc(sizeof(t_fp) * 1);
		if (!fp)
			return (NULL);
		fp->ptr = NULL;
		fp->_file = fd;
		fp->_flags = 1;
		fp->_r = 0;
		fp->sbf._base = NULL;
		fp->sbf._size = 0;
		ptr = fp;
	}
	ptr->lbf._base = NULL;
	ptr->lbf._size = 0;
	return (ptr);
}

/**
 * We have to copy the current buffered data to the line buffer making sure
 * there is room for more bytes. Copy data from string buffer to line buffer,
 * refill file and look for newline.
 * The loop stops only when we find a newline or EOF.
 *
 * OPTIMISTIC is length that we (optimistically) expect will
 * accommodate the `rest' of the string, on each trip through the
 * loop below.
 */
char	*ft_fgetln(t_fp *fp)
{
	size_t			len;
	size_t			offset;

	if (fp->_r <= 0 && refill(fp))
		return (NULL);
	offset = 0;
	len = fp->_r;
	if (get_str(fp, len, offset))
		return ((char *)fp->lbf._base);
	while (fp->_r > 0)
	{
		if ((lbchange(fp, len + OPTIMISTIC, !DO_SHRINK)
				|| ft_memcpy(fp->lbf._base + offset, fp->ptr, len - offset))
			&& (refill(fp) && (fp->_flags & FOUND_ERR)))
			return (NULL);
		offset = len;
		if (fp->_flags & FOUND_EOF)
			break ;
		if (get_str(fp, len, offset))
			return ((char *)fp->lbf._base);
		len += fp->_r;
	}
	if (lbchange(fp, len + 1, DO_SHRINK))
		return (NULL);
	return ((char *)fp->lbf._base);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static t_fp	*fp = NULL;

	if (fd < 0 || fd > SHRT_MAX)
		return (NULL);
	fp = sfp(fd, fp);
	if (!fp)
		return (NULL);
	buf = ft_fgetln(fp);
	if (!buf)
	{
		if (fp->_flags & MBF)
		{
			free(fp->sbf._base);
			fp->sbf._base = NULL;
			fp->sbf._size = 0;
		}
		free(fp->lbf._base);
		fp->lbf._base = NULL;
		fp->lbf._size = 0;
		free(fp);
		fp = NULL;
	}
	return (buf);
}
