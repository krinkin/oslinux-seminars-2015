LIBS = -lcap
LDFLAGS=sss

SRC=$(wildcard *.c)
EXE=$(SRC:.c=)



%: %.c 
	gcc -o $@ $< ${LIBS}

all: $(EXE)

clean:
	echo ${EXE}


