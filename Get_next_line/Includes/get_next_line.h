/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:06:47 by nimorel           #+#    #+#             */
/*   Updated: 2024/11/20 13:26:28 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_PGET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
ssize_t read(int fd, void *buf, size_t count);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif