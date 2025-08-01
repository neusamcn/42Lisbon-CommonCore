/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:40:04 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/01 17:39:28 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_read_to_nl_vars
{
	int		i;
	int		buf_len_nl;
	ssize_t	bytesread;
}			t_read_to_nl_vars;

void		*ft_calloc(size_t nmemb, size_t size);

char		*append_line(char *s1, char const *buf);
char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
char		*read_until_nl(int fd, char *buf, char *line);

size_t		ft_strlen_nl(const char *s);

#endif