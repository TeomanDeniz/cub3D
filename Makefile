# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 10:48:13 by hdeniz            #+#    #+#              #
#    Updated: 2024/04/29 16:31:01 by hdeniz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ************************* [v] SET MAKECMDGOALS [v] ************************* #
#                                                                              #
# IT IS A FIX FOR OVERLINKING, INSTEAD IF CALLING A PHONY TO CALCULATE HOW     #
# MANY .o FILES HAVE, WE DIRECTLY CALCULATING IT IN GLOBAL VARIABLES.          #
#                                                                              #
################################################################################
ifndef MAKECMDGOALS
	MAKECMDGOALS := ./main
endif

ifeq ($(filter $(MAKECMDGOALS),bonus b),bonus)
	MAKECMDGOALS := ./bonus
else
	MAKECMDGOALS := ./main
endif
# ************************* [^] SET MAKECMDGOALS [^] ************************* #

# *************************** [v] MAIN SOURCES [v] *************************** #
LIBFT_SRC	=	./libft/bool/ft_isdigit.c \
				./libft/converters/ft_atoi.c \
				./libft/converters/ft_numlen.c \
				./libft/memory/ft_safe_free.c \
				./libft/memory/ft_memmove.c \
				./libft/memory/ft_calloc.c \
				./libft/memory/ft_bzero.c \
				./libft/memory/ft_memset.c \
				./libft/string/ft_strlen.c \
				./libft/string/ft_split.c \
				./libft/string/ft_strcdup.c \
				./libft/string/ft_strdup.c \
				./libft/string/ft_strchr.c \
				./libft/string/ft_strncmp.c \
				./libft/string/ft_strtrim.c \
				./libft/string/ft_substr.c \
				./libft/string/ft_strlcpy.c \
				./libft/matrix/ft_matrixlen.c \
				./libft/matrix/ft_copy_matrix.c \
				./libft/matrix/ft_free_matrix.c \
				./libft/get_next_line/get_next_line.c \
				./libft/get_next_line/get_next_line_utils.c \
				./libft/ft_math/Other/ft_lerpf.c \
				./libft/ft_math/Other/ft_fabsf.c \
				./libft/ft_math/Other/ft_iabs.c \
				./libft/ft_math/Other/ft_fminf.c \
				./libft/ft_math/Other/ft_fmaxf.c \
				./libft/ft_math/Other/ft_imax.c \
				./libft/ft_math/Trigonometric/ft_sinf.c \
				./libft/ft_math/Trigonometric/ft_cosf.c \
				./libft/ft_math/Trigonometric/ft_tanf.c \
				./libft/ft_math/Rounding_Remainder/ft_floorf.c \
				./libft/ft_math/Rounding_Remainder/ft_fmodf.c \
				./libft/ft_math/Floating-point_Classification/ft_isnan.c \
				./libft/ft_math/Floating-point_Classification/ft_isinf.c \
				./libft/ft_math/Power/ft_powf.c \
				./libft/ft_math/Power/ft_sqrtf.c \
				./libft/ft_math/Exponential_Logarithmic/ft_expf.c \
				./libft/ft_math/Exponential_Logarithmic/ft_logf.c

MAIN_SRC	=	$(LIBFT_SRC) \
				./main/exit_functions/game_error.c \
				./main/exit_functions/close_window.c \
				./main/exit_functions/free_game.c \
				./main/exit_functions/game_warning.c \
				./main/setup/setup.c \
				./main/setup/map/check_map_data.c \
				./main/setup/map/check_map_header.c \
				./main/setup/map/check_map_header_color.c \
				./main/setup/map/check_map_header_xpm.c \
				./main/setup/map/get_data_map.c \
				./main/setup/map/get_map_header.c \
				./main/setup/map/map_control.c \
				./main/setup/map/free_map.c \
				./main/setup/map/set_map_to_game.c \
				./main/events/key_down.c \
				./main/events/key_up.c \
				./main/events/mouse_event.c \
				./main/render/input_events.c \
				./main/render/render.c \
				./main/render/putpixel.c \
				./main/render/skybox.c \
				./main/render/lidar/lidar.c \
				./main/render/lidar/calculate_distance_x.c \
				./main/render/lidar/calculate_distance_y.c \
				./main/render/lidar/check_between_0_90.c \
				./main/render/lidar/check_between_90_180.c \
				./main/render/lidar/check_between_180_240.c \
				./main/render/lidar/check_between_240_360.c
# *************************** [^] MAIN SOURCES [^] *************************** #

# ************************** [v] BONUS SOURCES [v] *************************** #
BONUS_SRC	=	$(LIBFT_SRC)
# ************************** [^] BONUS SOURCES [^] *************************** #

# ****************************** [v] BONUS [v] ******************************* #
	# [EXE]
#		BONUS_EXE	=	#"cub3D_bonus"
#		BONUS		=	#./bonus/cub3D.c
	# [EXE]
	# [.c STRINGS TO .o]
#		BONUS_OBJ	=	$(eval BONUS_OBJ := $$(BONUS_SRC:.c=.o))$(BONUS_OBJ)
	# [.c STRINGS TO .o]
# ****************************** [^] BONUS [^] ******************************* #

# **************************** [v] VARIABLES [v] ***************************** #
	# [MLX]
		MLX			=	./minilibx/libmlx.a
	# [MLX]
	# [COMPILER]
		CC			=	gcc
	# [COMPILER]
	# [EXE]
		MAIN_EXE	=	./cub3D
		MAIN		=	./main/cub3D.c
	# [EXE]
	# [COMPILER FLAGS]
		CFLAGS		=	-Wall -Wextra -Werror -O3 -Imlx # -g
		MAIN_FLAGS	=	-lmlx -O3 \
						-framework OpenGL -framework AppKit -L./minilibx # -g
	# [COMPILER FLAGS]
	# [.c STRINGS TO .o]
		MAIN_OBJ	=	$(MAIN_SRC:.c=.o)
	# [.c STRINGS TO .o]
	# [CHECK MAIN IS COMPILED]
		MAIN_READY	=	$(MAIN:.c=.o)
	# [CHECK MAIN IS COMPILED]
	# ANIMATION VARIABLES
		TERMINAL_LEN	:=	\
			$(eval TERMINAL_LEN := $(shell tput cols))$(TERMINAL_LEN)
		NUMBER_OF_FILES	:=	0
		FILE_COUNTER	:=	0
		N_OBJ			:=	$(eval N_OBJ := $$(shell find $(MAKECMDGOALS) \
		"./libft" -name '*.o' -type f | wc -w | sed "s/ //g" | bc))$(N_OBJ)
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
	F0		=	$(shell tput setaf 0)
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
	$(eval NUMBER_OF_FILES := $(shell echo $(MAIN_SRC) \
		| wc -w | sed "s/ //g" | bc))
	$(eval NUMBER_OF_FILES := $(shell echo $(NUMBER_OF_FILES) - $(N_OBJ) | bc))
	$(if $(filter 0,$(NUMBER_OF_FILES)), $(eval NUMBER_OF_FILES := 1))
	$(eval FILE_COUNTER := $(shell echo $(FILE_COUNTER) + 1 | bc))
	$(call progress_bar,$(FILE_COUNTER),$(NUMBER_OF_FILES),$<)
	@rm -f $(MAIN_EXE) 2>/dev/null
	@#@rm -f $(BONUS_EXE) 2>/dev/null
	@$(CC) $(CFLAGS) -c $< -o $@ 2>/dev/null || (\
		echo "\n\n $(B1F15) Failed to compile [$(F11)$<$(F15)] $(C_RESET)\n" &&\
		$(CC) $(CFLAGS) -c $< -o $@)

all: $(MAIN_EXE)

$(MAIN_EXE): $(MLX) $(MAIN) $(MAIN_OBJ)
	@$(CC) $(MAIN_FLAGS) $(MAIN) $(MAIN_OBJ) -o "$(MAIN_EXE)" && \
		echo "\n\n $(C_BLINK)$(B2F15) $(MAIN_EXE) is ready! $(C_RESET)\n"

#$(BONUS_EXE): $(BONUS) $(BONUS_OBJ)
#	@$(CC) $(MAIN_FLAGS) $(BONUS) $(BONUS_OBJ) -o "./$(BONUS_EXE)" && \
#		echo "\n\n $(C_BLINK)$(B2F15) $(BONUS_EXE) is ready! $(C_RESET)\n"

$(MLX):
	@echo " $(F0)COMPILING MLX!!!! $(C_RESET)"
	@make -C "./minilibx" 1>/dev/null
	@echo " $(B2F15)MLX Done !$(C_RESET)"

#b: bonus
#bonus: $(BONUS_EXE)

c: clean
clear: clean
clean:
	@rm $(MAIN_OBJ) $(BONUS_OBJ) 2>/dev/null && \
		echo "\n $(B1F15) Objects are cleared! $(C_RESET)\n" || \
		echo "\n $(B12F15) Nothing to clear! $(C_RESET)\n"
	$(eval N_OBJ := "0")

cmlx:
	@make -C "./minilibx" "clean" 1>/dev/null

fc: fclean
fclean: clean
	@rm $(MAIN_EXE) $(BONUS_EXE) 2>/dev/null && \
		echo "\n $(B1F11) $(MAIN_EXE) $(F15)deleted! $(C_RESET)\n" || \
		echo "\n $(B12F15) $(MAIN_EXE) is not exist already! $(C_RESET)\n"

re: fc all

.PHONY: all fclean fc clean clear c cmlx #bonus b
