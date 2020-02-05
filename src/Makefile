INCDIR =../include
CC=clang
CFLAGS=-Wall -Wconversion -Wextra -pedantic -I$(INCDIR)
SOURCES=celsius.c fahrenheit.c inputoutput.c main.c temperature.c
CLANG-TIDY=clang-tidy
CLANG-TIDYFLAGS=-checks='*' -- -I$(INCDIR)
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
	

default: cppcheck.xml clang-tidy main
.PHONY: default clean

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	
cppcheck.xml: $(SOURCES)
	$(CPPCHECK) $^ $(CHECKFLAGS) 2>$@

clang-tidy: $(SOURCES)
	$(CLANG-TIDY) $^ $(CLANG-TIDYFLAGS)

clean:
	rm -f $(ODIR)/*.o *~ main cppcheck.xml $(INCDIR)/*~
