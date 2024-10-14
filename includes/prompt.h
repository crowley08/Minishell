/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:01:01 by arakotom          #+#    #+#             */
/*   Updated: 2024/10/14 07:55:13 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
#define PROMPT_H

// prompt_split_pipe
int count_pipe(char *input);
int set_next_pipe(char **tab, char *input, int tab_index);
t_bool pipe_splitted(char **tab, char *input);
char **split_pipe(char *input);
void print_prompt_splitted(char **tab);

// init_prompt
void test_split_pipe(char *input);

#endif