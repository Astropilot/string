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
LFLAGS	= --coverage
GTEST	= /usr/local/lib/libgtest.a

RM		= rm -f

all: tests

tests: tests/simple_strings.o tests/tests.o
	$(CC) $(CFLAGS) tests/simple_strings.o tests/tests.o $(LFLAGS) $(GTEST) -o tests/tests

tests/simple_strings.o: tests/simple_strings.cpp
	$(CC) $(CFLAGS) --coverage -O0 -c tests/simple_strings.cpp -o tests/simple_strings.o

tests/tests.o: tests/tests.cpp
	$(CC) $(CFLAGS) -c tests/tests.cpp -o tests/tests.o

.PHONY: clean fclean re

clean:
	$(RM) tests/tests.o tests/simple_strings.o

fclean: clean
	$(RM) tests/tests

re: fclean all
