#Makefile

TARGETS=knn bayes

all: $(TARGETS)

knn: knn.c
	gccx -o knn knn.c

bayes: bayes.c
	gccx -o bayes bayes.c    

clean:
	rm -f *.o $(TARGETS) *~
