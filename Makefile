##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SDIR		=	src/
LAUNCHDIR	=	src/launcher/
MODDIR		=	src/ModuleGet/
SFDIR		=	src/sfml/
TXDIR		=	src/ncurses/

SRC			=	$(SDIR)main.cpp \
				$(LAUNCHDIR)launcher.cpp \
				$(MODDIR)basicModule.cpp \
				$(MODDIR)cpuModule.cpp \
				$(MODDIR)cpuUsage.cpp \
				$(MODDIR)os.cpp \
				$(MODDIR)timeModule.cpp	\
				$(SFDIR)hTop.cpp	\
				$(SFDIR)modules.cpp	\
				$(MODDIR)ramModule.cpp \
				$(MODDIR)networkModule.cpp \
				$(MODDIR)monitorCore.cpp \
				$(TXDIR)text_mode.cpp

IDIR		=	include/
INCL		=	my.h \
				launcher.hpp\
				basicModule.hpp \
				cpuModule.hpp\
				cpuUsage.hpp\
				IMonitorModule.hpp\
				launcher.hpp\
				os.hpp \
				timeModule.hpp	\
				hTop.hpp \
				text_mode.hpp \
				networkModule.hpp \
				monitorCore.hpp


CC			=	g++
OBJ			=	$(SRC:.cpp=.o)
BIN			=	machineInfo
CPPFLAGS	=	-Wall -Wextra -Werror -I$(IDIR) -lncurses -lsfml-graphics -lsfml-window -lsfml-network -lsfml-system

all: $(BIN)

$(BIN): $(OBJ)
		$(CC) $(OBJ) -o $(BIN) $(CPPFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(BIN)

re: fclean all

.PHONY: all clean fclean re
