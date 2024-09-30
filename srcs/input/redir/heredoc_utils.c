/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:10:56 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/30 09:30:43 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_heredoc	*new_heredoc(void)
{
	t_heredoc	*heredoc;

	heredoc = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (!heredoc)
		return (NULL);
	heredoc->eof = NULL;
	heredoc->filename = NULL;
	heredoc->expend_var = TRUE;
	heredoc->next = NULL;
	return (heredoc);
}

void	add_heredoc_list(t_heredoc **list, t_heredoc *heredoc)
{
	t_heredoc	*last;

	if (!(*list))
		*list = heredoc;
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		last->next = heredoc;
	}
}

char	*heredoc_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	else
	{
		res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
				* sizeof(char));
		if (!res)
			return (NULL);
		i = 0;
		j = 0;
		while (s1[j])
			res[i++] = s1[j++];
		j = 0;
		while (s2[j])
			res[i++] = s2[j++];
		res[i] = '\0';
		free(s1);
		return (res);
	}
}

// ! FIXME: delete this function later
void	print_heredoc(t_heredoc *heredoc)
{
	ft_printf("heredocs:\n");
	while (heredoc)
	{
		ft_printf("eof: $%s$\n", heredoc->eof);
		ft_printf("filename: $%s$\n", heredoc->filename);
		ft_printf("expend_var: $%d$\n", heredoc->expend_var);
		heredoc = heredoc->next;
	}
}

void	free_heredoc(t_heredoc *heredoc)
{
	if (heredoc->eof)
		free(heredoc->eof);
	if (heredoc->filename)
		free(heredoc->filename);
	free(heredoc);
}

void	free_heredoc_list(t_heredoc **list)
{
	t_heredoc	*heredoc;

	while (list && *list)
	{
		heredoc = *list;
		*list = (*list)->next;
		free_heredoc(heredoc);
	}
	*list = NULL;
}
