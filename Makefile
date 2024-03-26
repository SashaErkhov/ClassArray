CC=clang++
CFLAGS=-pedantic-errors -gdwarf-4 -std=c++20
LDFLAGS=-lgtest -lgtest_main -lpthread
SOURCES=listgtests.cpp arrygtests.cpp

all: $(SOURCES) listgtests arrygtests
	

arrygtests: arrygtests.cpp
	$(CC) arrygtests.cpp $(CFLAGS) $(LDFLAGS) -o $@

listgtests: listgtests.cpp
	$(CC) listgtests.cpp $(CFLAGS) $(LDFLAGS) -o $@

clean:
	rm -rf *.o listgtests arrygtests