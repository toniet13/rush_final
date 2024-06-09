NAME	=	rush-02
SRC_DIR =	./src
OBJ_DIR	=	./ofiles
OBJS	= $(OBJ_DIR)/main.o \
		  $(OBJ_DIR)/check.o \
		  $(OBJ_DIR)/dictionary.o \
		  $(OBJ_DIR)/solver_00.o \
		  $(OBJ_DIR)/solver_01.o \
		  $(OBJ_DIR)/utility_00.o \
		  $(OBJ_DIR)/utility_01.o \
		  $(OBJ_DIR)/utility_02.o

CFLAGS	= -Wall -Wextra -Werror -I$(SRC_DIR)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	cc -c -MD $(CFLAGS) $< -o $@

-include $(OBJ_DIR)/*.d

.PHONY: clean
.PHONY: fclean

fclean :
	rm $(NAME)
	rm -r $(OBJ_DIR)

clean :
	rm -r $(OBJ_DIR)