/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:24:05 by saandria          #+#    #+#             */
/*   Updated: 2024/10/11 16:31:31 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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

t_bool	create_file_heredoc(t_heredoc *list, t_env *envp)
{
	int	fd;

	while (list)
	{
		fd = open(list->filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (FALSE);
		if (!fill_file_input(fd, *list, envp))
		{
			unlink(list->filename);
			return (FALSE);
		}
		close(fd);
		list = list->next;
	}
	return (TRUE);
}
