/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 10:50:26 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/05/18 12:12:32 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>

int	main()
{
	DIR* dir;
	struct dirent * file;
	struct stat    stat;
	int err = 0;
	dir = opendir(".");
	while((file = readdir(dir)))
	{
		
		err = lstat(file->d_name, &stat);
		if (err==-1)
		{
			ft_putendl("error");
			return (0);
		}
		print_l_line(file->d_name, stat);
	}
	return (0);
}
