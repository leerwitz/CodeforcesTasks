C = g++
CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow  -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

all: 678_D 900_B 671_C 181_C 672_B TestHashTable

678_D: 678_D.cpp
	$(C) $(CFLAGS) -c 678_D.cpp -o 678_D.o
	$(C) $(CFLAGS)  678_D.o -o 678_D



900_B: 900_B.cpp
	$(C) $(CFLAGS) -c 900_B.cpp -o 900_B.o
	$(C) $(CFLAGS)  900_B.o -o 900_B

671_C: 671_C.cpp
	$(C) $(CFLAGS) -c 671_C.cpp -o 671_C.o
	$(C) $(CFLAGS)  671_C.o -o 671_C

181_C: 181_C.cpp
	$(C) $(CFLAGS) -c 181_C.cpp -o 181_C.o
	$(C) $(CFLAGS)  181_C.o -o 181_C

672_B: 672_B.cpp
	$(C) $(CFLAGS) -c 672_B.cpp -o 672_B.o
	$(C) $(CFLAGS)  672_B.o -o 672_B

TestHashtable: TestHashTable.cpp
	$(C) $(CFLAGS) -c TestHashTable.cpp -o TestHashTable.o
	$(C) $(CFLAGS)  TestHashTable.o -o TestHashTable


clean:
	rm -rf 678_D 900_B 671_C 181_C 672_B TestHashTable
	rm -rf *.o

rebuild: clean all