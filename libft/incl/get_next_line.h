/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoiton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:08:06 by lwoiton           #+#    #+#             */
/*   Updated: 2023/07/07 22:58:20 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int file_des);
char	*read_and_concat_buff(int filde_des, char *buff);
char	*realloc_buff(char *buff, char *ln_break);
char	*ft_gnl_strjoin(char *left_str, char *buff);
char	*ft_gnl_substr(char *s, char *ln_break);
char	*ft_gnl_strchr(char *s, int c);
size_t	ft_gnl_strlen(char const *c);
size_t	ft_gnl_strlcpy(char *dst, char *src, size_t size);

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
