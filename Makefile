# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 10:48:13 by hdeniz            #+#    #+#              #
#    Updated: 2024/10/26 16:31:01 by hdeniz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *************************** [v] MAIN SOURCES [v] *************************** #
LIBFT_SRC	=	./libft/ft_strdup.c \
				./libft/ft_strlen.c \
				./libft/ft_rand.c \
				./libft/ft_strjoin.c \
				./libft/ft_strlcat.c \
				./libft/ft_strlcpy.c \
				./libft/ft_split.c \
				./libft/ft_putnbr.c \
				./libft/ft_free_matrix.c \
				./libft/ft_copy_matrix.c \
				./libft/ft_print_matrix.c \
				./libft/ft_matrixlen.c \
				./libft/ft_numlen.c \
				./libft/ft_math/Other/ft_lerp.c \
				./libft/ft_math/Other/ft_mini.c \
				./libft/ft_math/Other/ft_fabs.c \
				./libft/ft_math/Other/ft_fmax.c \
				./libft/get_next_line/get_next_line_utils.c \
				./libft/get_next_line/get_next_line.c

MAIN_SRC	=	$(LIBFT_SRC)
# *************************** [^] MAIN SOURCES [^] *************************** #

# ************************** [v] BONUS SOURCES [v] *************************** #
BONUS_SRC	=	$(LIBFT_SRC)
# ************************** [^] BONUS SOURCES [^] *************************** #

# ****************************** [v] BONUS [v] ******************************* #
	# [EXE]
		BONUS_EXE	=	#"cub3D_bonus"
		BONUS		=	#./bonus/cub3D.c
	# [EXE]
	# [ARCHIVE AND OVERLINKING CHECKER]
		BONUS_NAME		=	#./bonus/cub3D_bonus.a
	# [ARCHIVE AND OVERLINKING CHECKER]
	# [.c STRINGS TO .o]
		BONUS_OBJ	=	$(eval BONUS_OBJ := $$(BONUS_SRC:.c=.o))$(BONUS_OBJ)
	# [.c STRINGS TO .o]
# ****************************** [^] BONUS [^] ******************************* #

# **************************** [v] VARIABLES [v] ***************************** #
	# [MLX]
	MLX				=	./minilibx/libmlx.a
	# [MLX]
	# [COMPILER]
		CC			=	gcc
	# [COMPILER]
	# [EXE]
		MAIN_EXE	=	"cub3D"
		MAIN		=	./main/cub3D.c
	# [EXE]
	# [ARCHIVE AND OVERLINKING CHECKER]
		NAME		=	./cub3D.a
	# [ARCHIVE AND OVERLINKING CHECKER]
	# [COMPILER FLAGS]
		CFLAGS		=	-Wall -Wextra -Werror -Imlx # -g
		MAIN_FLAGS	=	-Wall -Wextra -Werror -lmlx \
						-framework OpenGL -framework AppKit -L./minilibx # -g
	# [COMPILER FLAGS]
	# [.c STRINGS TO .o]
		MAIN_OBJ	=	$(eval MAIN_OBJ := $$(MAIN_SRC:.c=.o))$(MAIN_OBJ)
	# [.c STRINGS TO .o]
	# ANIMATION VARIABLES
		TERMINAL_LEN	:=	\
			$(eval TERMINAL_LEN := $(shell tput cols))$(TERMINAL_LEN)
		NUMBER_OF_FILES	:=	0
		FILE_COUNTER	:=	0
	# ANIMATION VARIABLES
# **************************** [^] VARIABLES [^] ***************************** #

# ****************************** [v] COLORS [v] ****************************** #
	C_RESET	=	$(shell tput sgr0)
	C_BLINK	=	$(shell tput blink)
	F15		=	$(shell tput setaf 15)
	B1F11	=	$(shell tput setab 1)$(shell tput setaf 11)
	B12F15	=	$(shell tput setab 12)$(shell tput setaf 15)
	B1F15	=	$(shell tput setab 1)$(shell tput setaf 15)
	B2F15	=	$(shell tput setab 2)$(shell tput setaf 15)
	F11		=	$(shell tput setaf 11)
	F13		=	$(shell tput setaf 13)
	F14		=	$(shell tput setaf 14)
	F10		=	$(shell tput setaf 10)
# ****************************** [^] COLORS [^] ****************************** #

# ***************************#* [v] FUNCIONS [v] ***************************** #
define progress_bar
	$(eval PBAR := $(shell echo $(1)*100/$(2)*100/100 | bc))
	$(eval PDONE := $(shell echo $(PBAR)*3/10 | bc))
	$(eval PLEFT := $(shell echo 30-$(PDONE) | bc))
	$(eval PSEQ := $(shell seq 0 1 $(PLEFT) 2>/dev/null))
	$(eval PEMPTY := $(shell if [ "$(1)" -ne "$(2)" ]; \
		then printf ".%.0s" $(PSEQ); fi))
	$(eval PFILL := $(shell printf "\#%.0s" $(shell seq 1 $(PDONE))))
	@printf "\r%*s\r $(F11)[$(F14)$(PFILL)$(PEMPTY)$(F11)] $(PBAR)%% - \
		$(F10)[$(1)/$(2)]$(F11) [$(F13)$(3)$(F11)$(C_RESET)]" \
		$(TERMINAL_LEN) " "
endef
# ***************************#* [^] FUNCIONS [^] ***************************** #

%.o: %.c
	$(eval FILE_COUNTER := $(shell echo $(FILE_COUNTER) + 1 | bc))
	$(call progress_bar,$(FILE_COUNTER),$(NUMBER_OF_FILES),$<)
	@rm -f $(MAIN_EXE) 2>/dev/null
	@rm -f $(BONUS_EXE) 2>/dev/null
	@$(CC) $(CFLAGS) -c $< -o $@

all: files_n_calculator $(MLX) $(NAME)

$(NAME): $(MAIN) $(MAIN_OBJ)
	@ar rc $(NAME) $(MAIN_OBJ) 2>/dev/null && \
	echo "\n\n $(C_BLINK)$(B2F15) $(NAME) is ready! $(C_RESET)\n"
	@$(CC) $(MAIN_FLAGS) $(MAIN) $(NAME) -o "./$(MAIN_EXE)" && \
	echo "\n\n $(C_BLINK)$(B2F15) $(MAIN_EXE) is ready! $(C_RESET)\n"

$(BONUS_NAME): $(BONUS) $(BONUS_OBJ)
	@ar rc $(BONUS_NAME) $(BONUS_OBJ) 2>/dev/null && \
	echo "\n\n $(C_BLINK)$(B2F15) $(BONUS_NAME) is ready! $(C_RESET)\n"
	@$(CC) $(MAIN_FLAGS) $(BONUS) $(BONUS_NAME) -o "./$(BONUS_EXE)" && \
	echo "\n\n $(C_BLINK)$(B2F15) $(BONUS_EXE) is ready! $(C_RESET)\n"

$(MLX):
	@echo " $(F10)$(shell tput setaf 0)COMPILING MLX!!!! $(C_RESET)"
	@make -C "./minilibx"
	@echo " $(B2F15)MLX Done !$(C_RESET)"

b: bonus
bonus: bonus_files_n_calculator $(BONUS_NAME)

c: clean
clear: clean
clean:
	@rm $(MAIN_OBJ) $(BONUS_OBJ) 2>/dev/null && \
		echo "\n $(B1F15) Objects are cleared! $(C_RESET)\n" || \
		echo "\n $(B12F15) Nothing to clear! $(C_RESET)\n"

fc: fclean
fclean: clean
	@rm $(NAME) $(BONUS_NAME) 2>/dev/null && \
	echo "\n $(B1F11) $(NAME) $(F15)deleted! $(C_RESET)\n" || \
	echo "\n $(B12F15) $(NAME) is not exist already! $(C_RESET)\n"
	@rm $(MAIN_EXE) $(BONUS_EXE) 2>/dev/null && \
	echo "\n $(B1F11) $(MAIN_EXE) $(F15)deleted! $(C_RESET)\n" || \
	echo "\n $(B12F15) $(MAIN_EXE) is not exist already! $(C_RESET)\n"

re: fc all

files_n_calculator:
	@echo ""
	$(eval FILE_COUNTER := 0)
	$(eval NUMBER_OF_FILES := $(shell echo $(MAIN_SRC) \
		| wc -w | sed "s/ //g" | bc))
	$(eval N_OBJ := \
		$(shell find "./main" "./libft" \
		-name '*.o' -type f | wc -w | sed "s/ //g" | bc))
	$(eval NUMBER_OF_FILES := $(shell echo $(NUMBER_OF_FILES) - $(N_OBJ) | bc))
	$(if $(filter 0,$(NUMBER_OF_FILES)), $(eval NUMBER_OF_FILES := 1))

bonus_files_n_calculator:
	@echo ""
	$(eval FILE_COUNTER := 0)
	$(eval NUMBER_OF_FILES := $(shell echo $(BONUS_SRC) \
		| wc -w | sed "s/ //g" | bc))
	$(eval N_OBJ := \
		$(shell find "./bonus" "./libft" \
		-name '*.o' -type f | wc -w | sed "s/ //g" | bc))
	$(eval NUMBER_OF_FILES := $(shell echo $(NUMBER_OF_FILES) - $(N_OBJ) | bc))
	$(if $(filter 0,$(NUMBER_OF_FILES)), $(eval NUMBER_OF_FILES := 1))

.PHONY: all fclean fc clean clear c bonus b