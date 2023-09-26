C = g++
CFLAGS = -Wall -Werror -Wextra

all: Problem_A Problem_B Problem_C Problem_D

Problem_A: problem_A.cpp
	$(C) $(CFLAGS) -c problem_A.cpp -o problem_A.o
	$(C) $(CFLAGS)  problem_A.o -o A



Problem_B: problem_B.cpp
	$(C) $(CFLAGS) -c problem_B.cpp -o problem_B.o
	$(C) $(CFLAGS)  problem_B.o -o B

Problem_C: problem_C.cpp
	$(C) $(CFLAGS) -c problem_C.cpp -o problem_C.o
	$(C) $(CFLAGS)  problem_C.o -o C

Problem_D: problem_D.cpp
	$(C) $(CFLAGS) -c problem_D.cpp -o problem_D.o
	$(C) $(CFLAGS)  problem_D.o -o D

clean:
	rm -rf A B C D
	rm -rf *.o

rebuild: clean all