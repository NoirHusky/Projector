.SUFFIXES: .o .cc

CC=g++

CXXFLAGS=-Wall -std=c++14 -DCPPHTTPLIB_OPENSSL_SUPPORT -lssl -lcrypto -ggdb # -D_GLIBCXX_DEBUG
CFLAGS=-Wall

LDFLAGS=-I./utils -fpermissive

UTILS=$(patsubst %.cc,%.o,$(wildcard utils/*.cc)) $(patsubst %.c,%.o,$(wildcard utils/*.c))
SRC=$(patsubst %.cc,%.o,$(wildcard *.cc))

OBJS= $(UTILS) $(SRC)

all: cpptube
cpptube: $(OBJS)
	@echo Making the app...
	@$(CC) $(CXXFLAGS) -o cpptube $(OBJS) -lm  $(LDFLAGS)
	@echo Done.

.cc.o:
	@echo Compiling: "$*.cc"
	@$(CC) $(CXXFLAGS) -o $*.o -c $*.cc $(LDFLAGS) -fpermissive

.c.o:
	@echo Compiling: "$*.c"
	@$(CC) $(CFLAGS) -o $*.o -c $*.c $(LDFLAGS) -fpermissive

clean:
	rm $(OBJS)
