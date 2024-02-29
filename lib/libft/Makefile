# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppinedo- <ppinedo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 16:53:19 by ppinedo-          #+#    #+#              #
#    Updated: 2024/02/08 13:01:10 by ppinedo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME = libft.a
B_NAME = NONE
INCLUDE = include/
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources
	
SRC_FILES = ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_toupper \
			ft_tolower \
			ft_strlen \
			ft_strncmp \
			ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memmove \
			ft_strlcpy \
			ft_strlcat \
			ft_strchr \
			ft_strrchr \
			ft_strnstr \
			ft_memcmp \
			ft_atoi \
			ft_calloc \
			ft_strdup \
			ft_substr \
			ft_strjoin \
			ft_putstr_fd \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_itoa \
			ft_strmapi \
			ft_striteri \
			ft_memchr \
			ft_strtrim \
			ft_split \
			ft_lstnew_bonus \
			ft_lstadd_front_bonus \
			ft_lstsize_bonus \
			ft_lstlast_bonus \
			ft_lstadd_back_bonus \
			ft_lstdelone_bonus \
			ft_lstclear_bonus \
			ft_lstiter_bonus \
			ft_lstmap_bonus \
			ft_printf \
			ft_putchar \
			ft_putstr \
			ft_putnbr \
			ft_putptr \
			ft_putunbr \
			ft_puthex \
			ft_strlen \
			get_next_line \
			get_next_line_bonus \

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF = .cache_exists

###

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar -rc $@ $?
			@echo "$(GREEN)✅$(NAME) COMPILED!✅$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -I./$(INCLUDE) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(B_SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -I./$(INCLUDE) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@rm -rf $(OBJ_DIR)
			@echo "$(BLUE)🧼$(NAME) object files cleaned!🧼$(DEF_COLOR)"

fclean:		
			@rm -rf $(OBJ_DIR)
			@rm -f $(NAME)
			@rm -f $(B_NAME)
			@echo "$(BLUE)🧼$(NAME) executable cleaned!🧼$(DEF_COLOR)"

re:			fclean all
			@echo "$(MAGENTA)📦$(NAME) recompiled!📦$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(B_SRC) $(INCLUDE) $(LIBFT)
			@echo "$(GREEN) ✅NORMINETTE OK!✅$(DEF_COLOR)"

.PHONY: all clean fclean re norm bonus
