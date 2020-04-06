CFLAGS		= -O4 -Wall ./include/main.hpp
CC			= g++ $(CFLAGS)
#DEST		= /usr/local/bin
#LDFLAGS	= -L/usr/local/lib
LIBS		= -lm
OBJS		= ./src/main.o
PROGRAM		= Vestigium

all:		$(PROGRAM)

$(PROGRAM):	$(OBJS)
			$(CC) $(OBJS) $(LIBS) -o $(PROGRAM)

clean:;		rm -f *.o *~ $(PROGRAM)

