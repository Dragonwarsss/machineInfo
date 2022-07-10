SDIR		=	src/
MODDIR		=	src/ModuleGet/

SRC			=	$(SDIR)main.cpp \
				$(MODDIR)basicModule.cpp \
				$(MODDIR)cpuModule.cpp \
				$(MODDIR)cpuUsage.cpp \
				$(MODDIR)os.cpp \
				$(MODDIR)timeModule.cpp	\
				$(MODDIR)ramModule.cpp \
				$(MODDIR)networkModule.cpp \
				$(MODDIR)monitorCore.cpp \

IDIR		=	include/
INCL		=	my.h \
				basicModule.hpp \
				cpuModule.hpp\
				cpuUsage.hpp\
				IMonitorModule.hpp\
				os.hpp \
				timeModule.hpp	\
				hTop.hpp \
				networkModule.hpp \
				monitorCore.hpp


CC			=	g++
OBJ			=	$(SRC:.cpp=.o)
BIN			=	machineInfo
CPPFLAGS	=	-Wall -Wextra -Werror -I$(IDIR) -lsfml-network -lsfml-system

all: $(BIN)

$(BIN): $(OBJ)
		$(CC) $(OBJ) -o $(BIN) $(CPPFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(BIN)

re: fclean all

.PHONY: all clean fclean re
