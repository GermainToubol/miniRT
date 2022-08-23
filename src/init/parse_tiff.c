/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tiff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:02:40 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/23 15:49:48 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "ft.h"
#include "parse_tiff.h"

/* Made using https://www.itu.int/itudoc/itu-t/com16/tiff-fx/docs/tiff6.pdf **/

static int	tiff_getheader(int fd, t_tiff_header *header)
{
	if (read(fd, header, sizeof(*header)) != sizeof(*header))
		return (-1);
	if (header->magic != 42 || header->endian != 0x4949)
		return (-1);
	return (0);
}

static int	tiff_readentry(int fd, t_tiff_img *img)
{
	t_entry	entry;

	if (read(fd, &entry, sizeof(entry)) != sizeof(entry))
		return (-1);
	if (entry.tag == 0x103 && entry.offset != 0x1)
		return (-1);
	if (entry.tag == 0x100)
	{
		if (entry.type == 0x4 || entry.offset == 0)
			return (-1);
		img->width = (uint16_t)entry.offset;
	}
	if (entry.tag == 0x101)
	{
		if (entry.type == 0x4 || entry.offset == 0)
			return (-1);
		img->height = (uint16_t)entry.offset;
	}
	if (entry.tag == 0x115 && entry.offset != 3)
		return (-1);
	return (0);
}

static int	tiff_getcontent(int fd, t_tiff_img *img)
{
	uint16_t	n_entries;
	uint16_t	i;

	if (read(fd, img->content, img->size) != img->size)
		return (-1);
	if (read(fd, &n_entries, sizeof(n_entries)) != sizeof(n_entries))
		return (-1);
	i = 0;
	while (i < n_entries)
	{
		if (tiff_readentry(fd, img) != 0)
			return (-1);
		i++;
	}
	if (i != n_entries
		|| img->size < (int32_t)img->width * (int32_t)img->height)
		return (-1);
	return (0);
}

int	load_tiff_img(char *filename, t_tiff_img *img)
{
	int				fd;
	t_tiff_header	header;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (tiff_getheader(fd, &header) != 0)
		return (close(fd), -1);
	img->size = header.offset - TIFF_HEADER_SIZE;
	img->width = 0;
	img->height = 0;
	img->content = ft_calloc(img->size, sizeof(*img->content));
	if (img->content == NULL)
		return (close(fd), -1);
	if (tiff_getcontent(fd, img) != 0)
		return (close(fd), -1);
	close(fd);
	return (0);
}
