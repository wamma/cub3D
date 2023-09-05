/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:18:43 by eoh               #+#    #+#             */
/*   Updated: 2023/09/05 10:44:15 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*gnl_strdup(char *src);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char *s, int start, int end);
int		gnl_strchr(char *s, int c);
int		gnl_strlen(char *s);

#endif