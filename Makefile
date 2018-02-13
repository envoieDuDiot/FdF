# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbryon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 08:42:33 by gbryon            #+#    #+#              #
#    Updated: 2018/02/13 09:25:05 by gbryon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = FdF

END=\033[0m
OKC=\033[32m
KOC=\033[31m

FLAG = -Wall -Wextra -Werror
FRAM = -lmlx -framework OpenGL -framework AppKit

OBJ_PATH = ./obj/
LFT_PATH = ./libft/
INC_PATH = ./include/
SRC_PATH = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fdf.h
SRC_NAME = main.c init.c draw.c stuff.c usefull.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		@echo
		@make -C $(LFT_PATH)
		@gcc -o $(NAME) $(FRAM) -L $(LFT_PATH) -lft $^ -o $@ 
		@echo "$(OKC)$(NAME) CREATED & READY$(END)"
		@echo "		            ZZZZZZZZZZZZZZZZZZZZZ\n		          ZZZZZ              ZZZZZZ\n		        ZZZZZ                    ZZZZ\n		      ZZZZZ                       ZZZZZ\n		    ZZZZZ                           ZZZZ\n		   ZZZZ                              ZZZZ\n		  ZZZ                                  ZZZ\n		 ZZZ                                    ZZZ\n		ZZZZ                                    ZZZ\n		ZZZ                                     ZZZ\n		ZZZ                                     ZZZ\n		ZZZ                                     ZZZ\n		ZZZ                             ZZ      ZZZ\n		ZZZ                           ZZZZZ     ZZZ\n		ZZZ                        ZZZZZZZZZ  ZZZZZ\n		ZZZZ    ZZZ              ZZZZZZZZZZZZ ZZZZ\n		ZZZZ   ZZZZZZ           ZZZZZZZZZZZZZ ZZZ\n		ZZZZ  ZZZZZZZZZZ       ZZZZZZZZZZZZZ  ZZ\n		ZZZZ  ZZZZZZZZZZZ      ZZZZZZZZZZZZ   ZZ\n		 ZZZ   ZZZZZZZZZZZ      ZZZZZZZZZZ    ZZ\n		 ZZZ    ZZZZZZZZZ ZZZZZ   ZZZZZZ    ZZZZ\n		  ZZZ    ZZZZZZZ  ZZZZZZ           ZZZZ\n		   ZZZZZ          Z  ZZZ     ZZZZZZZZZ\n		    ZZZZZZZZ          ZZ    ZZZZZZZZ\n		     ZZZZZZZZ             ZZZZZ\n		          ZZZ  Z   Z   Z  ZZZ\n		          ZZZ ZZZ ZZZ ZZZ ZZZ\n		          ZZZ ZZZ ZZZ ZZZ ZZZ\n		          ZZZ ZZZ ZZZ ZZZ ZZZ\n		           ZZZZZZZZZZZZZZZZZ\n		              ZZZZZZZZZZZ"Œ

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@gcc $(FLAG) $(INC) -o $@ -c $<
		@echo -n =

clean:
		@make -C $(LFT_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "$(KOC)$(NAME)'s OBJS REMOVED$(END)"

fclean: clean
		@make -C $(LFT_PATH) fclean
		@rm -f $(NAME)
		@echo "$(KOCC)$(NAME) REMOVED$(END)"

re: fclean all
