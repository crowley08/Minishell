/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+		+:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:++#+        */
/*                                                +#+#+#+#+#++#+           */
/*   Created: 2024/03/05 11:06:46 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/22 12:19:34 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
