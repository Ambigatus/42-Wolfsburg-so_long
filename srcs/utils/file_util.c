/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:15:24 by ddzuba            #+#    #+#             */
/*   Updated: 2022/12/11 19:10:25 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "so_long.h"

static char	*read_file(t_data *data, char *filename);
static char	*ft_str_concat(char *dest, char *src);

void	load_file(t_data *data, char *filename)
{
	char	*filepath;
	char	*file;

	filepath = ft_strjoin("maps/", filename);
	file = read_file(data, filepath);
	data->map.filedata = file;
	free(filepath);
}

static char	*read_file(t_data *data, char *filename)
{
	int		fd;
	int		ret;
	char	*buf;
	char	*file;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_game(data, ERROR_FILE_OPEN, "file not found.");
	if (!validate_file_ext(filename))
		error_game(data, ERROR_FILE_OPEN, "file extension is not `.ber`");
	buf = ft_calloc((BUF_SIZE + 1), sizeof(char));
	file = ft_calloc(sizeof(char), 10000);
	ret = read(fd, buf, BUF_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		ft_str_concat(file, buf);
		ret = read(fd, buf, BUF_SIZE);
	}
	free(buf);
	close(fd);
	return (file);
}

static char	*ft_str_concat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(dest + i))
		i++;
	while (*src)
	{
		*(dest + i) = *src;
		i++;
		src++;
	}
	*(dest + i) = '\0';
	return (dest);
}
