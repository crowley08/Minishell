/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:21:52 by saandria          #+#    #+#             */
/*   Updated: 2024/09/26 11:01:54 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (size != 0 && count > ((size_t)-1 / size))
		return (0);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return ((void *)ptr);
}
