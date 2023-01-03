CC       = g++
WSDIR    = $(CURDIR)/wsServer
INCLUDE  = -I $(WSDIR)/include
CFLAGS   =  -Wall -Wextra -g
CFLAGS  +=  $(INCLUDE) -std=c++11 -pthread
LIB      =  $(WSDIR)/libws.a

all: $(LIB) driver

$(LIB):
	@$(MAKE) all -C $(WSDIR)/

animal.o: animal.h animal.cpp
	$(CC) $(CFLAGS) -c animal.cpp

simulation.o: simulation.h animal.h simulation.cpp $(LIB)
	$(CC) $(CFLAGS) -c simulation.cpp

canvas.o: canvas.h simulation.h canvas.cpp $(LIB)
	$(CC) $(CFLAGS) -c canvas.cpp

driver: animal.o simulation.o canvas.o $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) driver.cpp animal.o simulation.o canvas.o -o driver $(LIB)

# Clean
clean:
	rm *.o driver
