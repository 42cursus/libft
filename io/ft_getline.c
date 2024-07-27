/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:52:18 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 23:52:19 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "ft_string.h"

int	read_from_fd(char *buffer, char **line, t_gnl **list, int fd);

int	save_remainder_into_list(t_gnl **list, int fd, char *buffer, int i)
{
	t_gnl		*current;
	t_gnl		*new;

	new = NULL;
	current = *list;
	while (current && current->next && current->fd != fd)
		current = current->next;
	if (current && current->fd == fd && buffer[i + 1] != '\0')
		current->str = ft_strdup(buffer + i + 1);
	else if (buffer[i + 1] != '\0')
	{
		new = (t_gnl *)malloc(sizeof(*new));
		if (!new)
			return (-1);
		new->str = ft_strdup(buffer + i + 1);
		new->fd = fd;
		new->next = NULL;
		if (!*list)
			*list = new;
		else
			current->next = new;
	}
	free(buffer);
	return (1);
}

int	line_memory_allocation(char **line, int new_length)
{
	char			*tmp;
	size_t			ret_val;

	ret_val = 0;
	if (!*line)
	{
		*line = ft_strnew(new_length);
		if (!(*line))
			return (-1);
	}
	else
	{
		tmp = ft_strdup(*line);
		if (!tmp)
			return (-1);
		free(*line);
		ret_val = ft_strlen(tmp);
		*line = ft_strnew(new_length + ret_val);
		if (!(*line))
			return (-1);
		ft_strcpy(*line, tmp);
		free(tmp);
	}
	return ((int)ret_val);
}

int	put_buffer_into_line(char *buffer, char **line, t_gnl **list, int fd)
{
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != EOF && buffer[i] != '\0')
		i++;
	j = line_memory_allocation(line, i + (buffer[i] == '\n'));
	if (j == -1)
		return (-1);
	ft_strncpy((*line) + j, buffer, i + (buffer[i] == '\n'));
	if (buffer[i] == '\n')
		return (save_remainder_into_list(list, fd, buffer, i));
	else if (buffer[i] == '\0')
		return (read_from_fd(buffer, line, list, fd));
	free(buffer);
	return (1);
}

int	read_from_fd(char *buffer, char **line, t_gnl **list, int fd)
{
	ssize_t	bytes_read;

	if (buffer)
		free(buffer);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0 || buffer[0] == '\0')
	{
		free(buffer);
		if (bytes_read < 0)
			return (-1);
		if (!bytes_read && *line && ft_strlen(*line) != 0)
			return (1);
		return (0);
	}
	buffer[bytes_read] = '\0';
	return (put_buffer_into_line(buffer, line, list, fd));
}

int	ft_getline(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*prev_or_curr[2];
	char			*buffer;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	prev_or_curr[1] = list;
	prev_or_curr[0] = prev_or_curr[1];
	while (prev_or_curr[1] != NULL && prev_or_curr[1]->fd != fd)
	{
		prev_or_curr[0] = prev_or_curr[1];
		prev_or_curr[1] = prev_or_curr[1]->next;
	}
	if (prev_or_curr[1] != NULL)
	{
		if (prev_or_curr[0] == prev_or_curr[1])
			list = list->next;
		buffer = ft_strdup(prev_or_curr[1]->str);
		prev_or_curr[0]->next = prev_or_curr[1]->next;
		free(prev_or_curr[1]->str);
		free(prev_or_curr[1]);
		return (put_buffer_into_line(buffer, line, &list, fd));
	}
	return (read_from_fd(buffer = NULL, line, &list, fd));
}
