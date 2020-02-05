INCDIR =../include
CC=clang
CFLAGS=-Wall -Wconversion -Wextra -pedantic -I$(INCDIR)
SOURCES=celsius.c fahrenheit.c inputoutput.c main.c temperature.c
CPPCHECK=cppcheck
CHECKFLAGS=--language=c --enable=warning,style --template=clang -q --error-exitcode=1 --xml

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS=celsius.h fahrenheit.h main.h temperature.h
DEPS=$(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ=celsius.o fahrenheit.o inputoutput.o main.o temperature.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
	

default: check.xml main
.PHONY: default clean

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	
check.xml: $(SOURCES)
	$(CPPCHECK) $(CHECKFLAGS) $^ >$@

clean:
	rm -f $(ODIR)/*.o *~ main check.xml $(INCDIR)/*~
