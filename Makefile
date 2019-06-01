
NAME		=		correct

SRC_DIR		=		src
INC_DIR		=		include
BUILD_DIR	=		builds

SRC			:=		$(shell find $(SRC_DIR) -name '*.c' -type f)
INC			:=		$(shell find $(INC_DIR) -name '*.h' -type f)

OBJ			=		$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CFLAGS		=		-I $(INC_DIR) -g
LDFLAGS		=		-lm

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c	$(INC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) $(NAME)

re:	clean	all

.PHONY:	all	clean	re