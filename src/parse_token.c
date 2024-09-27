/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:26:27 by saandria          #+#    #+#             */
/*   Updated: 2024/09/27 15:20:21 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
static void	child_process(t_msh *msh)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec(&msh->token, msh->envc);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ms_pipe(t_msh *msh)
{
	int	pipe;

	pipe = count_pipe(msh);
	if (pipe == 0)
	    exec(&msh->token, msh->envc);
	while (pipe > 0)
	{
        child_process(msh);
        msh->token = msh->token->next;
		pipe--;
    }
}
*/

static int	count_token_word(t_token *token)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = token;
	while (tmp && tmp->type == TOK_WORD)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static t_node	*init_node(t_nodetype type)
{
	t_node    *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
		error();
	new_node->cmd = NULL;
	new_node->type = type;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

static t_node	*dup_token(t_token *token)
{
	t_node	*node;
	int		i;
	int		j;

	i = count_token_word(token);
//	printf("tainalika\n");
	node = init_node(CMD_NODE);
	node->cmd = malloc(sizeof(char *) * (i + 1));
	j = 0;
	while (token && token->type == TOK_WORD)
	{
		node->cmd[j] = ft_strdup(token->value);
        j++;
        token = token->next;
	}
	return (node);
}

static t_node	*parse_token(t_token **token)
{
	t_node	*left;
	t_node	*pipe;

	left = dup_token(*token);
	if (*token && (*token)->type == TOK_PIPE)
	{
		pipe = init_node(PIPE_NODE);
		pipe->left = left;
		*token = (*token)->next;
		pipe->right = parse_token(token);
		return (pipe);
	}
	return (left);
}

t_node	*parse(t_token *token)
{
	t_node	*node;

	node = parse_token(&token);
	return (node);
}

void	print_ast(t_node **node)
{
	if (!*node)
		return ;
	printf("type : %d\n", (*node)->type);
	if ((*node)->cmd)
		printf("%s\n", (*node)->cmd[0]);
	print_ast(&(*node)->left);
	print_ast(&(*node)->right);
}