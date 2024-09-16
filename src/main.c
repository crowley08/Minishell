/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria < saandria@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:01 by saandria          #+#    #+#             */
/*   Updated: 2024/09/16 15:08:15 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token *create_token(t_tokentype type, char *value, int *i)
{
	t_token    *new_token;

    new_token = (t_token *)malloc(sizeof(t_token));
    if (!new_token)
        return (NULL);
    new_token->type = type;
    new_token->value = ft_strdup(value);
    new_token->next = NULL;
    return (new_token);
}

t_token	*tokenizer(char *s)
{
	t_token	*head;
	t_token	*current;
	t_token	*new_token;
	t_token	*token;
	int i;

	i = 0;
	head = NULL;
	current = NULL;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        {
			i++;
			continue ;
        }
        else if (s[i] == '|')
		{
			new_token = create_token(TOK_PIPE, "|", &i);
		}
		if (head == NULL)
		{
			head = new_token;
			current = head;
		}
		else if (current == NULL)
		{
			current = new_token;
            head = current;
		}
        else
            i++;
	}
	return (token)
}

int	main(int ac, char **av, char **env)
{
	char	*s;

	ms_signal();
	while (42)
	{
		s = readline("\033[1;91m$>\033[0m ");
		if (!s)
		{
			free(s);
			return (0);
		}
		if (ft_strcmp(s, "exit") == 0)
			break ;
		else if (ft_strcmp(s, "pwd") == 0)
			s = getcwd(NULL, 0);
		printf("%s\n", s);
		add_history(s);
		free(s);
	}
	return (0);
}
