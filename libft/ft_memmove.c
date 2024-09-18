/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:25:07 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/26 11:16:24 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (!dst && !src)
		return (0);
	if (src < dst)
		while (n-- > 0)
			*(tmp_dst + n) = *(tmp_src + n);
	else
		while (n-- > 0)
			*(tmp_dst++) = *(tmp_src++);
	return (dst);
}
