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

CC		= g++
CFLAGS	= -Wall -Wextra -Werror -g -pthread -I /usr/local/include/gtest/
GTEST	= /usr/local/lib/libgtest.a

FOLDER  = tests/
TARGET	= tests
RM		= rm -f

SRC		= tests/tests.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GTEST) -o $(FOLDER)$(TARGET)

.PHONY: clean fclean re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(FOLDER)$(TARGET)

re: fclean all
