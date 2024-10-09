/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:25:23 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/09 14:24:31 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *get_path(char *cmd, t_env *envp)
{
	t_env *env_path;
	int i;
	char **paths;
	char *path;

	env_path = get_env("PATH", envp);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path->value, ':');
	i = 0;
	while (paths && paths[i])
	{
		path = ft_strjoin(paths[i++], "/");
		path = heredoc_strjoin(path, cmd);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
			break;
		free(path);
		path = NULL;
	}
	ft_free_tab_str(paths);
	return (path);
}

void exec_one_prompt(t_prompt *prompt, t_env *envp)
{
	char *path;
	char **arg;
	char **env;

	if (!(prompt->cmd))
		return;
	path = get_path(prompt->cmd->cmd, envp);
	if (path)
	{
		//? leak memory
		arg = set_arg_execve(prompt->cmd);
		env = set_env_execve(envp);
		ft_printf("Path for %s: %s\n", prompt->cmd->cmd, path);
		if (execve(path, arg, env) == -1)
		{
			//! exit
			ft_printf("Failed to exec\n");
			ft_free_tab_str(arg);
			ft_free_tab_str(env);
			free(path);
		}
	}
	else
		ft_printf("Path not found for %s\n", prompt->cmd->cmd);
}

void exec_prompt(t_prompt *prompt, t_env *envp)
{
	pid_t pid;
	(void)envp;
	(void)prompt;
	pid = fork();
	if (pid == -1)
	{
		ft_printf("Fork failed ---------------\n\n");
		return;
	}
	if (pid == 0)
		exec_one_prompt(prompt, envp);
	wait(NULL);
	ft_printf("Fork succeeded +++++++++++++++\n\n");
}

void set_redir_in(t_redir_in *redir, int fd[2])
{
	int fd_file;
	if (redir)
	{
		while (redir->next)
			redir = redir->next;
		fd_file = open(redir->file, O_RDONLY);
		if (!fd_file)
			return;
		dup2(fd_file, fd[0]);
	}
}

void set_redir_out(t_redir_out *redir, int fd[2])
{
	int fd_file;
	if (redir)
	{
		while (redir->next)
		{
			if (redir->type == REDIR_APPEND)
				fd_file = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
			else if (redir->type == REDIR_TRUNC)
				fd_file = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (!fd_file)
				return;
			close(fd_file);
			redir = redir->next;
		}
		if (redir->type == REDIR_APPEND)
			fd_file = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (redir->type == REDIR_TRUNC)
			fd_file = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (!fd_file)
			return;
		dup2(fd_file, fd[1]);
	}
}

//! FIXME: this function
void exec_list_prompt(t_prompt *prompt, t_env *envp)
{
	int fd[2];
	int fd_std_in;
	int fd_std_out;

	if (pipe(fd) == -1)
	{
		ft_printf("Pipe failed ---------------\n\n");
		return;
	}
	fd_std_in = dup(STDIN_FILENO);
	fd_std_out = dup(STDOUT_FILENO);
	while (prompt)
	{
		if (check_redir_error(prompt->redir_in, prompt->redir_out))
			break;
		exec_prompt(prompt, envp);
		prompt = prompt->next;
	}
	dup2(fd_std_in, STDIN_FILENO);
	dup2(fd_std_out, STDOUT_FILENO);
}
