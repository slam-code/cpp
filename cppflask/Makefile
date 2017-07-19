CPPFLAGS+=-std=c++14 -Wall -Werror -Wextra -pedantic -Weffc++ -I. -Wundef -Wold-style-cast

all:    main

main: main.o basic_server.o service.o
	${CXX} $^ -o $@ -pthread

%.o: %.cpp
	${CXX} -c ${CPPFLAGS} $< -o $@

tests: url_scanner_test.cpp url_scanner.hpp
	${CXX} ${CPPFLAGS} -o $@ url_scanner_test.cpp -pthread -lgtest -lgtest_main
	./tests

clean:
	rm -f main tests main.o

deps:
	makedepend -Y. *.cpp

# DO NOT DELETE

basic_server.o: ./basic_server.hpp ./service.hpp ./url_scanner.hpp
basic_server.o: ./response.hpp ./request.hpp
main.o: ./service.hpp ./url_scanner.hpp ./response.hpp ./request.hpp
main.o: ./basic_server.hpp
service.o: ./url_scanner.hpp ./response.hpp ./request.hpp
url_scanner_test.o: ./url_scanner.hpp
