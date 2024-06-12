/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmolnya <asmolnya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:25:09 by asmolnya          #+#    #+#             */
/*   Updated: 2024/06/12 20:59:06 by asmolnya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "my_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>

void	handle_signal(int sig);
void	send_char(int pid, char c);

#endif