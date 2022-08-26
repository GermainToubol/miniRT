/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_frame_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:00:02 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/26 14:47:51 by gtoubol          ###   ########.fr       */
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

static void	write_ifd_entries(int fd)
{
	t_entry		entry[13];
	int			offset;

	offset = 3 * WIDTH * HEIGHT
		+ sizeof(t_tiff_header)
		+ sizeof(uint16_t)
		+ 13 * sizeof(t_entry);
	entry[0] = (t_entry){0x100, 0x3, 0x1, WIDTH};
	entry[1] = (t_entry){0x101, 0x3, 0x1, HEIGHT};
	entry[2] = (t_entry){0x102, 0x3, 0x3, offset};
	entry[3] = (t_entry){0x103, 0x3, 0x1, 1};
	entry[4] = (t_entry){0x106, 0x3, 0x1, 2};
	entry[5] = (t_entry){0x111, 0x4, 0x4, offset + 38};
	entry[6] = (t_entry){0x115, 0x3, 0x1, 3};
	entry[7] = (t_entry){0x116, 0x3, 0x1, 0x80};
	entry[8] = (t_entry){0x117, 0x4, 0x4, offset + 22};
	entry[9] = (t_entry){0x11a, 0x5, 0x1, offset + 6};
	entry[10] = (t_entry){0x11b, 0x5, 0x1, offset + 14};
	entry[11] = (t_entry){0x128, 0x03, 0x1, 1};
	entry[12] = (t_entry){0x0, 0x0, 0x0, 0x0};
	write(fd, &entry, 13 * sizeof(t_entry));
}

static void	write_ifd_values(int fd)
{
	char		buffer[54];
	uint16_t	i;
	uint32_t	j;

	i = 0x8;
	ft_memcpy(buffer, &i, 2);
	ft_memcpy(buffer + 2, &i, 2);
	ft_memcpy(buffer + 4, &i, 2);
	j = 0x12c;
	ft_memcpy(buffer + 6, &j, 4);
	j = 0x1;
	ft_memcpy(buffer + 10, &j, 4);
	j = 0x12c;
	ft_memcpy(buffer + 14, &j, 4);
	j = 0x1;
	ft_memcpy(buffer + 18, &j, 4);
	j = 0x43800;
	ft_memcpy(buffer + 22, &j, 4);
	ft_memcpy(buffer + 26, &j, 4);
	ft_memcpy(buffer + 30, &j, 4);
	j = 0x32a00;
	ft_memcpy(buffer + 34, &j, 4);
	j = 0x8;
	ft_memcpy(buffer + 38, &j, 4);
	j = 0x43808;
	ft_memcpy(buffer + 42, &j, 4);
	j = 0x87008;
	ft_memcpy(buffer + 46, &j, 4);
	j = 0xca808;
	ft_memcpy(buffer + 50, &j, 4);
	write(fd, buffer, 54);
}

static void	write_ifd(int fd)
{
	uint16_t	i;

	i = 12;
	write(fd, &i, 2);
	write_ifd_entries(fd);
	write_ifd_values(fd);
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
	write_ifd(fd);
	close(fd);
	return (0);
}
