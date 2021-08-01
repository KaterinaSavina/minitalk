NAME	=	server
NAME1	=	client

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

LFPATH	=	./libft
SRCDIR  = ./srcs/

SRCNAME_SERVER	=	server
SRCNAME_CLIENT	=	client

SRCS_SERVER	=	$(addsuffix .c, $(addprefix srcs/, $(SRCNAME_SERVER)))
SRCS_CLIENT	=	$(addsuffix .c, $(addprefix srcs/, $(SRCNAME_CLIENT)))

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

.PHONY: all
all	:	$(NAME) $(NAME1)

$(NAME)	:	${OBJS_SERVER}
			$(MAKE) -C libft/.
			$(CC) -g ${OBJS_SERVER} ${LFPATH}/libft.a $(CFLAGS) -o ${NAME}

$(NAME1)	:	${OBJS_CLIENT}
			$(MAKE) -C libft/.
			$(CC) -g ${OBJS_CLIENT} ${LFPATH}/libft.a $(CFLAGS) -o ${NAME1}

.PHONY: clean
clean	:
			$(MAKE) clean -C libft/.
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_SERVER)


.PHONY: fclean
fclean	:	clean
			$(MAKE) fclean -C libft/.
			$(RM) $(NAME)
			$(RM) $(NAME1)


.PHONY: re
re	:	fclean all

.PHONY: bonus
bonus: $(NAME) $(NAME1)
