/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:06 by lwoiton           #+#    #+#             */
/*   Updated: 2023/08/07 12:33:01 by lwoiton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int file_des);
char	*read_and_concat_buff(int filde_des, char *buff);
char	*realloc_buff(char *buff, char *ln_break);
char	*ft_strjoin_gnl(char *left_str, char *buff);
char	*ft_substr_gnl(char *s, char *ln_break);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen_gnl(char const *c);
size_t	ft_strlcpy_gnl(char *dst, char *src, size_t size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef MAX_FILE_DES
#  define MAX_FILE_DES 1024
# endif
#endif
