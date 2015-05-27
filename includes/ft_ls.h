/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/18 11:14:12 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/05/18 12:00:22 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

#ifndef FT_LS_H
# define FT_LS_H

void		print_l_line(char * path, struct stat stat);

#endif
