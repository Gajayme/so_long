#NAMES
NAME		= so_long
MAKE		= make

#COMP USE CC INSTEAD?!?!??!
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

#LIBFT
LIBFT_DIR	= libft
LIBFT		= libft.a
LIBFT_MAKE	= cd $(LIBFT_DIR) && $(MAKE)
LIBFT_INC	= -L libft -lft

#MINILIBX STATIC
MLXDIR		= mlx
MLXMAKE		= cd $(MLXDIR) && $(MAKE)
MLX_INC		= -Lmlx -lmlx -framework OpenGL -framework AppKit

#SRC
SRC_DIR		= src
SRC			= $(SRC_DIR)/so_long.c \
			$(SRC_DIR)/stop.c \
			$(SRC_DIR)/map_read.c \
			$(SRC_DIR)/map_parse.c \
			$(SRC_DIR)/map_draw.c \
			$(SRC_DIR)/hooks.c \
			$(SRC_DIR)/move.c \
			$(SRC_DIR)/pre_move.c \

SRC_BON_DIR	= src_bonus
SRC_BON		= $(SRC_BON_DIR)/so_long_bonus.c \
			$(SRC_BON_DIR)/stop_bonus.c \
			$(SRC_BON_DIR)/map_read_bonus.c \
			$(SRC_BON_DIR)/map_parse_bonus.c \
			$(SRC_BON_DIR)/map_draw_bonus.c \
			$(SRC_BON_DIR)/hooks_bonus.c \
			$(SRC_BON_DIR)/move_bonus.c \
			$(SRC_BON_DIR)/pre_move_bonus.c \
			$(SRC_BON_DIR)/enemy_bonus.c \
			$(SRC_BON_DIR)/movements_bonus.c \


#INC
INC_DIR		= inc
INC			= $(INC_DIR) so_long.h
INC_BON_DIR		= inc_bonus
INC_BON		= $(INC_BON_DIR) so_long_bonus.h

#OBJ
OBJ_DIR		= obj
OBJ			= $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))
OBJ_BON_DIR		= obj_bonus
OBJ_BON		= $(patsubst $(SRC_BON_DIR)%, $(OBJ_BON_DIR)%, $(SRC_BON:.c=.o))

#OBJ_INC
OBJ_INC		= -I mlx -I $(INC_DIR) -I libft
OBJ_BON_INC	= -I mlx -I $(INC_BON_DIR) -I libft

#RMS
RM_DIR		= rm -rf
RM_FILE		= rm -f

#DEPS
$(NAME): $(OBJ)
	$(MLXMAKE)
	$(LIBFT_MAKE)
	$(CC) $(OBJ) $(LIBFT_INC) $(MLX_INC) -o $(NAME)

#OBJ DEPS
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(OBJ_INC) -c $< -o $@

$(OBJ_BON_DIR)/%.o: $(SRC_BON_DIR)/%.c
	$(CC) $(CFLAGS) $(OBJ_BON_INC) -c $< -o $@

$(OBJ)		:	| $(OBJ_DIR)
$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

$(OBJ_BON)		:	| $(OBJ_BON_DIR)
$(OBJ_BON_DIR):
			mkdir -p $(OBJ_BON_DIR)


#RULES
all:	$(NAME)

bonus:	fclean $(NAME) $(OBJ_BON)
		$(MLXMAKE)
		$(LIBFT_MAKE)
		$(CC) $(OBJ_BON) $(LIBFT_INC) $(MLX_INC) -o $(NAME)

clean:
		${RM_DIR} ${OBJ_DIR}
		${RM_DIR} ${OBJ_BON_DIR}


fclean:	clean
		${RM_FILE} $(NAME)
		cd $(LIBFT_DIR) && $(MAKE) fclean
		cd $(MLXDIR) && $(MAKE) clean

re:		fclean all

#OTHER
.PHONY: all clean fclean re
