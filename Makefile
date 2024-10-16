# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbergero <jbergero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 02:57:44 by jbergero          #+#    #+#              #
#    Updated: 2024/10/16 02:57:49 by jbergero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs
RM = rm -f

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = char/ft_isalpha.c char/ft_isdigit.c char/ft_isalnum.c char/ft_tolower.c \
            char/ft_isascii.c char/ft_isprint.c char/ft_toupper.c \
            mem/ft_memset.c mem/ft_bzero.c mem/ft_memcpy.c mem/ft_memmove.c \
            mem/ft_memchr.c mem/ft_memcmp.c mem/ft_calloc.c \
            str/ft_strlen.c str/ft_strlcpy.c str/ft_strlcat.c str/ft_strchr.c \
            str/ft_strrchr.c str/ft_strncmp.c str/ft_strnstr.c str/ft_atoi.c \
            str/ft_strdup.c str/ft_substr.c str/ft_strjoin.c str/ft_strtrim.c \
            str/ft_split.c str/ft_itoa.c str/ft_strmapi.c str/ft_striteri.c \
            put/ft_putchar_fd.c put/ft_putstr_fd.c put/ft_putendl_fd.c put/ft_putnbr_fd.c \
            printf/ft_printf.c printf/ft_print_char.c printf/ft_print_hex.c printf/ft_print_int.c \
            printf/ft_print_ptr.c printf/ft_print_str.c printf/ft_print_uint.c \
            gnl/get_next_line.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re