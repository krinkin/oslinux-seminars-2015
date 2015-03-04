LIBS = -lcap

SRC=$(wildcard *.c)
EXE=$(SRC:.c=)



%: %.c 
	gcc -o $@ $< ${LIBS}

all: $(EXE)

clean:
	rm ${EXE}


