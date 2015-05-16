/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 10:50:26 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/05/15 11:58:05 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
		ft_putendl(file->d_name);
		err = lstat("libft", &stat);
		if (err==-1)
		{
			ft_putendl("error");
			return (0);
		}
		ft_putendl(ft_itoa((int)stat.st_dev));
		ft_putendl(ft_itoa((int)stat.st_mode));
		ft_putendl(ft_itoa((int)stat.st_uid));
		ft_putendl(ft_itoa((int)stat.st_gid));
		ft_putendl(ft_itoa((int)stat.st_nlink));
		ft_putendl(ft_itoa((int)stat.st_size));
		ft_putendl("-------------------------");
	}
	return (0);
}
