#*******************************************************************************
# PROJECT: string
#
# AUTHORS: Yohann Martin (@Astropilot)
#
# DATE CREATED: 04/16/2022
#
# Copyright (c) 2022 Yohann MARTIN (@Astropilot). All rights reserved.
#
# Licensed under the MIT License. See LICENSE file in the project root for full
# license information.
#*******************************************************************************

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

FOLDER  = build/
TARGET	= string
RM		= rm -f

SRC		= src/tests.c

OBJ		= $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(FOLDER)$(TARGET)

.PHONY: clean fclean re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(FOLDER)$(TARGET)

re: fclean all
