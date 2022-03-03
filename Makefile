.PHONY: all clean bonus fclean re

NAME = cub3D

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)libft.a

LIBMLX_DIR = ./mlx

LIBMLX = $(LIBMLX_DIR)libmlx.dylib

MAKE = make

CLEAN = clean

FCLEAN = fclean

SRC = main.c\
	srcs/arguments.c\
	srcs/begin.c\
	srcs/cub_utils.c\
	srcs/cub_utilstwo.c\
	srcs/parser_checkings.c\
	srcs/parser_checks.c\
	srcs/parsing.c\
	srcs/player_dir.c\
	srcs/screen.c\
	srcs/sprite.c\
	srcs/spritetwo.c\
	srcs/map_parsing.c\
	srcs/key_hook.c\
	srcs/cub_utilsthree.c\
	
	
OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra -g -O0

FLAGMLX = -framework OpenGL -framework AppKit

OPTION = -c -D GL_SILENCE_DEPRECATION

OPTIONOBJ = -o

DEL = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	@cd $(LIBFT_DIR) && mv ./libft.a ../
	@cd $(LIBMLX_DIR) && mv ./libmlx.dylib ../
	@$(CC) $(FLAG) $(OBJ) -L. -lmlx -lft $(FLAGSMLX) $(OPTIONOBJ) $(NAME)

$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKE)

$(LIBMLX):
	@cd $(LIBMLX_DIR) && $(MAKE)

%.o: %.c
	@$(CC) $(FLAG) $(OPTION) $< $(OPTIONOBJ) $@

clean:
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(CLEAN)
	@cd $(LIBMLX_DIR) && $(MAKE) $(CLEAN)
	
fclean: clean
	@$(DEL) $(NAME) ./libft.a ./libmlx.dylib
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKE) $(FCLEAN)
	
re: fclean all

