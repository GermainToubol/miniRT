/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_frame_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:00:02 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/18 22:56:59 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "ft.h"
#include "minirt.h"
#include "mlx_int.h"
#include "parse_tiff.h"

static void	write_img(int fd, t_img *img)
{
	int		x;
	int		y;
	char	color[3];

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			color[0] = img->data[y * img->size_line + x * 4 + 2];
			color[1] = img->data[y * img->size_line + x * 4 + 1];
			color[2] = img->data[y * img->size_line + x * 4 + 0];
			write(fd, color, 3);
		}
	}
}

static void	write_flags(int fd)
{
	t_entry		entry;
	int			offset;
	uint16_t	i;
	uint32_t	j;

	i = 12;
	write(fd, &i, 2);
	offset = WIDTH * HEIGHT * 3 + sizeof(t_tiff_header) + sizeof(uint16_t) + sizeof(t_entry) * (i + 1);
	entry = (t_entry){0x100, 0x3, 0x1, WIDTH};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x101, 0x3, 0x1, HEIGHT};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x102, 0x3, 0x3, offset};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x103, 0x3, 0x1, 1};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x106, 0x3, 0x1, 2};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x111, 0x4, 0x4, 0x8};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x115, 0x3, 0x1, 3};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x116, 0x3, 0x1, 0x800};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x117, 0x4, 0x4, offset + 22};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x11a, 0x5, 0x1, offset + 6};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x11b, 0x5, 0x1, offset + 14};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x128, 0x03, 0x1, 1};
	write(fd, &entry, sizeof(entry));
	entry = (t_entry){0x0, 0x0, 0x0, 0x0};
	write(fd, &entry, sizeof(entry));
	i = 0x8;
	write(fd, &i, 2);
	write(fd, &i, 2);
	write(fd, &i, 2);
	j = 0x12c;
	write(fd, &j, 4);
	j = 0x1;
	write(fd, &j, 4);
	j = 0x12c;
	write(fd, &j, 4);
	j = 0x1;
	write(fd, &j, 4);
	j = 0x43800;
	write(fd, &j, 4);
	write(fd, &j, 4);
	write(fd, &j, 4);
	j = 0x32a00;
	write(fd, &j, 4);
}

int	print_frame_buffer(t_data *data)
{
	int				fd;
	t_img			*img;
	t_tiff_header	header;

	img = (t_img *)data->frame_buffer;
	if (img->bpp != 32)
		return (ft_putstr_fd("Unable to convert the img\n", 2), -1);
	fd = open("render.tiff", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (ft_putstr_fd("Unable to save the img\n", 2), -1);
	header = (t_tiff_header){0x4949, 42, HEIGHT * WIDTH * 3 + sizeof(header)};
	write(fd, &header, sizeof(header));
	write_img(fd, img);
	write_flags(fd);
	close(fd);
	return (0);
}
