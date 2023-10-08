C = g++
CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow  -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=4 -Wswitch-default -Wundef -Werror -Wno-unused

all: 894_A 900_B 900_C 900_D

894_A: 894_A.cpp
	$(C) $(CFLAGS) -c 894_A.cpp -o 894_A.o
	$(C) $(CFLAGS)  894_A.o -o A



900_B: 900_B.cpp
	$(C) $(CFLAGS) -c 900_B.cpp -o 900_B.o
	$(C) $(CFLAGS)  900_B.o -o B

900_C: 900_C.cpp
	$(C) $(CFLAGS) -c 900_C.cpp -o 900_C.o
	$(C) $(CFLAGS)  900_C.o -o C

900_D: 900_D.cpp
	$(C) $(CFLAGS) -c 900_D.cpp -o 900_D.o
	$(C) $(CFLAGS)  900_D.o -o D

clean:
	rm -rf A B C D
	rm -rf *.o

rebuild: clean all