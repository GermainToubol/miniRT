#ifndef PARSE_TIFF_H
# define PARSE_TIFF_H

# include <stdint.h>

# define TIFF_HEADER_SIZE 8

typedef struct s_tiff_header
{
	uint16_t	endian;
	uint16_t	magic;
	uint32_t	offset;
}	t_tiff_header;

typedef struct s_img
{
	int32_t		size;
	char		*content;
	uint16_t	width;
	uint16_t	height;
}	t_img;

typedef struct s_entry
{
	uint16_t	tag;
	uint16_t	type;
	uint32_t	count;
	uint32_t	offset;
}	t_entry;

#endif /* PARSE_TIFF_H */
