/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:13:56 by arakotom          #+#    #+#             */
/*   Updated: 2024/09/26 01:13:10 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

char	*get_input(void);
t_bool	is_empty(char *str);
t_bool	is_pipe_start_end(char *str);
t_bool	is_quote_opened(char *str);
t_bool	is_have_dbl_pipe_succ(char *str);
t_bool	set_input_error(t_error_stt *curr_error, t_error_stt error);
t_bool	input_valid(t_data *data);

#endif
