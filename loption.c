/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loption.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlecuyer <hlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 10:54:32 by hlecuyer          #+#    #+#             */
/*   Updated: 2015/05/18 12:58:04 by hlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>

void		print_type(struct stat stat)
{
	ft_putstr((S_ISDIR(stat.st_mode)) ? "d" : "");
	ft_putstr((S_ISREG(stat.st_mode)) ? "-" : "");
	ft_putstr((S_ISLNK(stat.st_mode)) ? "l" : "");
	ft_putstr((S_ISCHR(stat.st_mode)) ? "c" : "");
	ft_putstr((S_ISSOCK(stat.st_mode)) ? "s" : "");
	ft_putstr((S_ISFIFO(stat.st_mode)) ? "p" : "");
	ft_putstr((S_ISLNK(stat.st_mode)) ? "s" : "");
	ft_putstr((stat.st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr((stat.st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr((stat.st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr((stat.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr((stat.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr((stat.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr((stat.st_mode & S_IROTH) ? "r" : "-");
    ft_putstr((stat.st_mode & S_IWOTH) ? "w" : "-");
    ft_putstr((stat.st_mode & S_IXOTH) ? "x" : "-");
}


void        print_l_line(char * path, struct stat stat)
{
	struct passwd	*user;
	struct group		*groupe;

	user = getpwuid(stat.st_uid);
	groupe = getgrgid(stat.st_gid);
	print_type(stat);
	ft_putstr(" ");
	ft_putstr(ft_itoa(stat.st_nlink));
	ft_putstr(" ");
	ft_putstr(user->pw_name);
	ft_putstr(" ");
	ft_putstr(groupe->gr_name);
	ft_putstr(" ");
	ft_putstr(ft_itoa(stat.st_size));
	ft_putstr(" ");
	ft_putstr(ctime(&stat.st_mtime));
	ft_putstr(" ");
	ft_putstr(path);


	ft_putendl("");
}
