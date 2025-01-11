/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:13:35 by abelov            #+#    #+#             */
/*   Updated: 2024/07/27 19:13:36 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H
# include <search.h>

typedef __compar_fn_t		t_cmpf;
typedef struct s_object_arr	t_obj_arr;
struct s_object_arr
{
	void	*base;
	size_t	total_elems;
	size_t	elem_size;
	t_cmpf	cmp_fun;
};

int		ft_atoi(const char *str);
char	*ft_itoa(int nb);
int		ft_nblen(int nbr);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_buf(int nb, char *buf, size_t length);
char	*ft_uitoa_buf(unsigned int nb, char *buf, size_t length);

void	ft_bsort(void *const base, size_t total_elems,
			size_t size, __compar_fn_t cmp);
void	ft_qsort(void *const base, size_t total_elems,
			size_t size, __compar_fn_t cmp);
void	*ft_bsearch_obj(const void *key, t_obj_arr *obj);
void	ft_qsort_obj(t_obj_arr *obj);

#endif //FT_STDLIB_H
