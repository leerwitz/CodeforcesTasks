C = g++
CFLAGS = -Wall -Werror -Wextra

all: 894_A 894_B 894_C 894_D

894_A: 894_A.cpp
	$(C) $(CFLAGS) -c 894_A.cpp -o 894_A.o
	$(C) $(CFLAGS)  894_A.o -o A



894_B: 894_B.cpp
	$(C) $(CFLAGS) -c 894_B.cpp -o 894_B.o
	$(C) $(CFLAGS)  894_B.o -o B

894_C: 894_C.cpp
	$(C) $(CFLAGS) -c 894_C.cpp -o 894_C.o
	$(C) $(CFLAGS)  894_C.o -o C

894_D: 894_D.cpp
	$(C) $(CFLAGS) -c 894_D.cpp -o 894_D.o
	$(C) $(CFLAGS)  894_D.o -o D

clean:
	rm -rf A B C D
	rm -rf *.o

rebuild: clean all