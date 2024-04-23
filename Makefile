CC=clang++
CFLAGS=-pedantic-errors -gdwarf-4 -std=c++20
LDFLAGS=-lgtest -lgtest_main -lpthread
SOURCES=listgtests.cpp arrygtests.cpp

all: listgtests arrygtests assocgtests paragtests
	

arrygtests: arrygtests.cpp
	$(CC) arrygtests.cpp $(CFLAGS) $(LDFLAGS) -o $@

listgtests: listgtests.cpp
	$(CC) listgtests.cpp $(CFLAGS) $(LDFLAGS) -o $@

assocgtests: assocgtests.cpp
	$(CC) assocgtests.cpp $(CFLAGS) $(LDFLAGS) -o $@

paragtests: paragtests.cpp
	$(CC) paragtests.cpp $(CFLAGS) $(LDFLAGS) -o $@

clean:
	rm -rf *.o listgtests arrygtests
