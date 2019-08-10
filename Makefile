TARGET_PROGRAM = prog
COMPILER = gcc

#ensure verbose output
CCFLAGS = -Wall -std=c11
LDFLAGS = -lrt

$(TARGET_PROGRAM) : xor.o
	$(COMPILER) -o $(TARGET_PROGRAM) xor.o

xor.o :
	$(COMPILER) -c xor.c $(CCFLAGS)

clean :
	rm -f *.o $(TARGET_PROGRAM)

debug : CCFLAGS += -DDEBUG -g
debug : $(TARGET_PROGRAM)
