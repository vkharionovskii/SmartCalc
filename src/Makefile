CC=g++
# CPPFLAGS=-Wall -Wextra -Werror -Wno-unused -pedantic -std=c++17 -lstdc++
CXXFLAGS=-Wall -Wextra -Werror -Wno-unused -pedantic -std=c++17
GTESTFLAGS=-lgtest_main -lgtest
#
NAME=s21_SmartCalc.a
HEADER=Model.h
SRC=Model.cc Controller.cc
OBJ=$(patsubst %.cc, %.o, $(SRC))
#
OS = $(shell uname)
#
.PHONY: all build s21_SmartCalc test install uninstall dist dvi gcov_report re clean m
#
#
#
all: $(NAME)
#
build: $(NAME)
#
$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?
%.o : %.c $(HEADER)
	$(CC) $(CXXFLAGS) -c $< -o $@
#
tests: build
	$(CC) $(CXXFLAGS) $(GTESTFLAGS) GTest.cc $(SRC) $(NAME) -o TEST
	./TEST
#
gcov_report:
	$(CC) GTest.cc -c
	$(CC) $(CXXFLAGS) $(GTESTFLAGS) --coverage GTest.o $(SRC) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html
#
install:
	make clean
	mkdir build
	cd SmartCalc && qmake && make && make clean && rm Makefile && cd ../ && cp -r SmartCalc/SmartCalc* build
	# mv SmartCalc/SmartCalc* build
	rm -rf build/SmartCalc.pro build/SmartCalc.pro.user
#
uninstall:
	rm -rf build*
#
dvi:
	open readme.html
#
dist: install
	rm -rf Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/src
	cp ./build/SmartCalc* Archive_SmartCalc_v2.0/src/
	tar cvzf Archive_SmartCalc_v2.0.tgz Archive_SmartCalc_v2.0/
	rm -rf Archive_SmartCalc_v2.0/
#
check: tests
	clang-format -n *.cc *.h SmartCalc/*.h SmartCalc/*.cc
ifeq ($(OS),Darwin)
	leaks -atExit -- ./TEST
else
	valgrind --tool=memcheck --track-origins=yes --leak-check=full ./TEST
endif
#
style:
	clang-format -i *.cc *.h SmartCalc/*.h SmartCalc/*.cc
#
re: clean build
#
clean:
	rm -rf *.out *.dSYM *.o *.a *.gch
	rm -rf gcov_report
	rm -rf report
	rm -rf *.gcda *.info *.gcno
	rm -rf Archive_SmartCalc_v2.0 
	rm -rf *tgz
	rm -rf build*
	rm -rf gcov_test 
	rm -rf TEST CALCULATOR
#
m: build
	$(CC) main.cc $(SRC) $(NAME) $(CXXFLAGS) -lstdc++ -o CALCULATOR && ./CALCULATOR
