/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:21:52 by saandria          #+#    #+#             */
/*   Updated: 2024/03/24 15:24:40 by saandria         ###   ########.fr       */
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
