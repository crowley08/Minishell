/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:02:40 by saandria          #+#    #+#             */
/*   Updated: 2024/10/14 15:04:46 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*msh_strjoin(char *s1, char *s2)
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

t_bool	is_empty_line(char *line)
{
	while (line && *line)
	{
		if (!ft_isspace(*line))
			return (F);
		line++;
	}
	return (T);
}

void	exit_msh_exit(t_msh *msh, char *input)
{
	free_msh(msh);
	free(input);
	free(msh);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
