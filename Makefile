NAME					=					libeffect.a
DEMO_NAME				=					demo


SRC						=					src/particle/particle.c				\
											src/particle/particle_draw.c		\
											src/fade/fade.c						\
											src/fade/fade_draw.c				\
											src/fade/fade_set.c

MAIN					=					src/demo.c

OBJ						=					$(SRC:%.c=%.o)
OBJ_MAIN				=					$(MAIN:%.c=%.o)

LIB						=					-lm -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-network

CFLAGS					=					-I include/ $(LIB)

all:					$(NAME)
$(NAME):				$(OBJ)
						ar rcs $(NAME) $(OBJ)
clean:
						$(RM) -rf $(OBJ)
fclean:					clean
						$(RM) -rf $(NAME)
re:						fclean all

demo:					$(OBJ) $(OBJ_MAIN)
						$(CC) -o $(DEMO_NAME) $(OBJ) $(OBJ_MAIN) $(LIB) $(CFLAGS)