CC = gcc
BOMPDIR = bin/openmp
BMPIDIR = bin/mpi
UDIR = util
OMPDIR = openmp
CFLAGS= -fopenmp -lm

_DEPS = matrix.h matrix.c
DEPS = $(patsubst %, $(UDIR)/%, $(_DEPS))

all: cannon cannonmpi

cannon: $(OMPDIR)/cannon.c $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

cannonmpi: mpi/cannon.c $(DEPS)
	mpicc $^ -o cannonmpi -lm 

clean:
	rm cannon && rm cannonmpi
