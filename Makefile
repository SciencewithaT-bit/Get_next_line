# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saaboudo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 19:15:12 by saaboudo          #+#    #+#              #
#    Updated: 2023/12/13 19:16:40 by saaboudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
INCLUDES = libft.h 

SOURCES =  	get_next_line.c \
			get_next_line_utils.c \
