/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 07:47:58 by abelov            #+#    #+#             */
/*   Updated: 2024/06/02 07:47:59 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_cont	t_cont;
struct s_cont
{
	int		fd;
	int		size;
	char	*str;
	t_cont	*next;
};

int	read_from_fd(char *buf, char **save_ptr, t_cont **list, int fd);
int	put_buffer_into_line(char *line_buf,
		char **save_ptr, t_cont **list, int fd);
int	line_memory_allocation(char **line, int size);
int	save_remainder_into_list(t_cont **list, int fd, char *buf, int iter);

int	get_next_line2(int fd, char **save_ptr)
{
	int				err_code;
	char			*line_buf;
	static t_cont	*list;
	t_cont			*curr;
	t_cont			*cont;

	if ((fd < 0) || (save_ptr == NULL))
		err_code = -1;
	else
	{
		*save_ptr = NULL;
		cont = list;
		curr = list;
		while (cont != NULL && (fd != cont->fd))
		{
			curr = cont;
			cont = cont->next;
		}
		if (cont == NULL)
			err_code = read_from_fd(NULL, save_ptr, &list, fd);
		else
		{
			if (curr == cont)
				list = list->next;
			line_buf = ft_strdup(cont->str);
			curr->next = cont->next;
			free(cont->str);
			free(cont);
			err_code = put_buffer_into_line(line_buf, save_ptr, &list, fd);
		}
	}
	return (err_code);
}

int	read_from_fd(char *buf, char **save_ptr, t_cont **list, int fd)
{
	int		error_code;
	char	*line_buf;

	if (buf != NULL)
		free(buf);
	line_buf = (char *)malloc(0x3e9);
	if (line_buf == NULL)
		error_code = -1;
	else
	{
		error_code = read(fd, line_buf, 1000);
		if ((error_code < 1) || (*line_buf == '\0'))
		{
			free(line_buf);
			if (error_code < 0)
				error_code = (-1);
			else
			{
				if (((error_code == 0) && (*save_ptr != NULL))
					&& ft_strlen(*save_ptr) != 0)
					return (1);
				error_code = 0;
			}
		}
		else
		{
			line_buf[error_code] = '\0';
			error_code = put_buffer_into_line(line_buf, save_ptr, list, fd);
		}
	}
	return (error_code);
}

int	put_buffer_into_line(char *line_buf, char **save_ptr, t_cont **list, int fd)
{
	int	error_code;
	int	iter;

	iter = 0;
	while (((line_buf[iter] != '\n' && (line_buf[iter] != -1))
			&& (line_buf[iter] != '\0')))
		iter = iter + 1;
	error_code = line_memory_allocation(save_ptr,
			(line_buf[iter] == '\n') + iter);
	if (error_code != -1)
	{
		ft_strncpy(*save_ptr + error_code, line_buf,
			iter + (uint)(line_buf[iter] == '\n'));
		if (line_buf[iter] == '\n')
			error_code = save_remainder_into_list(list, fd, line_buf, iter);
		else
		{
			if (line_buf[iter] == '\0')
				error_code = read_from_fd(line_buf, save_ptr, list, fd);
			else
			{
				free(line_buf);
				error_code = 1;
			}
		}
	}
	return (error_code);
}

int	line_memory_allocation(char **line, int size)
{
	char	*str;
	size_t	new_size;

	new_size = 0;
	if (*line != NULL)
	{
		str = ft_strdup(*line);
		if (str == NULL)
			return (-1);
		free(*line);
		new_size = ft_strlen(str);
		*line = ft_calloc(new_size + size, 1);
		if (*line == NULL)
			return (-1);
		ft_strcpy((char *) *line, str);
		free(str);
	}
	else
	{
		*line = ft_calloc(size, 1);
		if (*line == NULL)
			return (-1);
	}
	return ((int)new_size);
}

int	save_remainder_into_list(t_cont **list, int fd, char *buf, int iter)
{
	char	*str;
	t_cont	*curr;
	t_cont	*content;

	curr = *list;
	while (((curr != NULL && (curr->next != NULL)) && (fd != curr->fd)))
		curr = curr->next;
	if (!((curr == NULL) || (fd != curr->fd)) && buf[iter + 1] != '\0')
	{
		str = ft_strdup(buf + iter + 1);
		curr->str = str;
	}
	else
	{
		if (buf[iter + 1] != '\0')
		{
			content = (t_cont *) malloc(0x18);
			if (content == NULL)
				return (-1);
			content->str = ft_strdup(buf + (long) iter + 1);
			content->fd = fd;
			content->next = NULL;
			if (*list == NULL)
				*list = content;
			else
				curr->next = content;
		}
	}
	free(buf);
	return (1);
}
