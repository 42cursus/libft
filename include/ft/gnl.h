/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:57:29 by abelov            #+#    #+#             */
/*   Updated: 2023/11/20 21:57:31 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif //BUFFER_SIZE

# define OPTIMISTIC 80
# define DO_SHRINK	0x0001		/* line buffered */
# define UN_BUF	0x0002		/* unbuffered */
# define FOUND_EOF	0x0020		/* found EOF */
# define FOUND_ERR	0x0040		/* found error */
# define MBF	0x0080		/* _buf is from malloc */
# define SMOD	0x2000		/* true => fgetln modified _p text */

/* stdio buffers */
typedef struct s_buf
{
	unsigned char	*_base;
	int				_size;
}	t_buf;

typedef struct s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}	t_gnl;

/*
 * _IO_FILE object type capable of recording all the information needed to
 * control a stream, including its file position indicator, a pointer to its
 * associated buffer (if any), an error indicator that records whether a
 * read/write error has occurred, and an end-of-file indicator that records
 * whether the end of the file has been reached;
 */
typedef struct s_io_file
{
	int				_r;
	void			*_cookie;
	int				(*_close)(void*);
	int				(*_read)(void*, char*, int);
	unsigned char	*ptr;
	short			_flags;
	short			_file;
	unsigned char	nbuf[1];
	t_buf			sbf;
	t_buf			lbf;
}							t_fp;

char	*get_next_line(int fd);
int		ft_getline(const int fd, char **line);
int		get_str(t_fp *fp, size_t len, size_t offset);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		lbchange(t_fp *fp, size_t newsize, int flag);
void	*ft_reallocarray(void *ptr,
			size_t oldnmemb, size_t newnmemb, size_t size);

#endif //GNL_H
