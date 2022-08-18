/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tiff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:04:54 by gtoubol           #+#    #+#             */
/*   Updated: 2022/08/18 14:02:17 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_tiff_img
{
	int32_t		size;
	uint8_t		*content;
	uint16_t	width;
	uint16_t	height;
}	t_tiff_img;

typedef struct s_entry
{
	uint16_t	tag;
	uint16_t	type;
	uint32_t	count;
	uint32_t	offset;
}	t_entry;

int	load_tiff_img(char *filename, t_tiff_img *img);

#endif /* PARSE_TIFF_H */
