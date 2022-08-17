#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "parse_tif.h"

/* Made using https://www.itu.int/itudoc/itu-t/com16/tiff-fx/docs/tiff6.pdf **/

int	tiff_getheader(int fd, t_tiff_header *header)
{
	if (read(fd, header, sizeof(*header)) != sizeof(*header))
		return (-1);
	if (header->magic != 42 || header->endian != 0x4949)
		return (-1);
	return (0);
}

int tiff_readentry(int fd, t_img *img)
{
	t_entry	entry;

	if (read(fd, &entry, sizeof(entry)) != sizeof(entry))
		return (-1);
	if (entry.tag == 0x103 && entry.offset != 0x1)
		return (dprintf(2, "Can read compressed file... "), -1);
	if (entry.tag == 0x100)
	{
		if (entry.type == 0x4)
			return (dprintf(2, "Size too big... "), -1);
		img->width = (uint16_t)entry.offset;
	}
	if (entry.tag == 0x101)
	{
		if (entry.type == 0x4)
			return (dprintf(2, "Size too big... "), -1);
		img->height = (uint16_t)entry.offset;
	}
	if (entry.tag == 0x102 && entry.offset != 0x1614)
		return (dprintf(2, "Bad color format... %x ", entry.offset), -1);
	return (0);
}

int	tiff_getcontent(int fd, t_img *img)
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
	return (0);
}

int main(void)
{
	int				fd;
	t_tiff_header	header;
	t_img			img;

	fd = open("lama.tif", O_RDONLY);
	if (fd < 0)
		return (dprintf(2, "Bad opening\n"), -1);
	if (tiff_getheader(fd, &header) != 0)
		return (close(fd), dprintf(2, "Not valid tiff file\n"), -1);
	printf("endian: %d\nmagic: %d\noffset %d\n",
		   header.endian,
		   header.magic,
		   header.offset);
	img.size = header.offset - TIFF_HEADER_SIZE;
	img.width = 0;
	img.height = 0;
	img.content = malloc(sizeof(*img.content) * img.size);
	if (img.content == NULL)
		return (close(fd), dprintf(2, "Allocation error\n"), -1);
	if (tiff_getcontent(fd, &img) != 0)
		dprintf(2, "Bad read\n");
	close(fd);
	printf("Size: %d x %d\n", img.width, img.height);
	free(img.content);
}
