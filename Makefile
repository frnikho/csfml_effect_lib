NAME					=					effect
DEMO_NAME				=					demo


SRC						=					src/particle/particle.c				\
											src/fade/fade.c						\
											src/fade/fade_draw.c

MAIN					=					src/demo.c

OBJ						=					$(SRC:%.c=%.o)
OBJ_MAIN				=					$(MAIN:%.c=%.o)

LIB						=					-lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-network

CFLAGS					=					-I include/ $(LIB)

all:					$(NAME)
$(NAME):				$(OBJ)
						ar rcs libeffect $(OBJ)
clean:
						$(RM) -rf $(OBJ)
fclean:					clean
						$(RM) -rf $(NAME)
re:						fclean all

demo:					$(OBJ) $(OBJ_MAIN)
						$(CC) -o $(DEMO_NAME) $(OBJ) $(OBJ_MAIN) $(LIB) $(CFLAGS)