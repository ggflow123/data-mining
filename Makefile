# Makefile

TARGETS=knn bayes

all: $(TARGETS)

knn: knn.c
	gccx -o knn knn.c

bayes: byes.c
	gccx -o bayes bayes.c -lm

clean:
	rm -f *.o $(TARGETS) *~
