# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abuonomo <abuonomo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 19:15:40 by abuonomo          #+#    #+#              #
#    Updated: 2023/03/13 19:02:36 by abuonomo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FT_PRINTF_PATH		=	./ft_printf
FT_PRINTF			=	$(FT_PRINTF_PATH)/libftprintf.a

SOURCES_FILESS	=	client.c
SOURCES_FILESC	=	server.c

OBJECTSS			= 	$(SOURCES_FILESS:.c=.o)
OBJECTSC			= 	$(SOURCES_FILESC:.c=.o)

NAMEC			=	client
NAMES			=	server

CC				=	gcc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

%.o:%.c
	$(CC) ${CFLAGS}  -c $< -o $@

all:			$(NAMEC) $(NAMES)

$(NAMEC):	$(OBJECTSS) $(FT_PRINTF)
				$(CC) $(OBJECTSS) $(FT_PRINTF) -o $(NAMEC)
$(NAMES):	$(OBJECTSC) $(FT_PRINTF)
				$(CC) $(OBJECTSC) $(FT_PRINTF) -o $(NAMES)

$(FT_PRINTF):
				make -C $(FT_PRINTF_PATH)

clean:
				${RM} ${OBJECTSS} ${OBJECTSC}
				make clean -C ${FT_PRINTF_PATH}

fclean:			clean
					rm -f $(NAMEC) $(NAMES)
					rm -f $(FT_PRINTF)

re:				fclean all

.PHONY:			all clean re
