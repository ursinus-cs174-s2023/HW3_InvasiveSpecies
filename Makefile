CC       = g++
WSDIR    = $(CURDIR)/wsServer
INCLUDE  = -I $(WSDIR)/include
CFLAGS   =  -Wall -Wextra -g
CFLAGS  +=  $(INCLUDE) -std=c++11 -pthread
LIB      =  $(WSDIR)/libws.a

all: $(LIB) driver

$(LIB):
	@$(MAKE) all -C $(WSDIR)/

randutils.o: randutils.h randutils.cpp $(LIB)
	$(CC) $(CFLAGS) -c randutils.cpp

animal.o: animal.h animal.cpp randutils.h
	$(CC) $(CFLAGS) -c animal.cpp

simulation.o: simulation.h animal.h simulation.cpp $(LIB)
	$(CC) $(CFLAGS) -c simulation.cpp

canvas.o: canvas.h simulation.h canvas.cpp $(LIB)
	$(CC) $(CFLAGS) -c canvas.cpp

driver: randutils.o animal.o simulation.o canvas.o $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) driver.cpp randutils.o animal.o simulation.o canvas.o -o driver $(LIB)

# Clean
clean:
	rm *.o driver
