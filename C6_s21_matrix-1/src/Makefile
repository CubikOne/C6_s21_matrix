CFLAGS = -g -Wall -Werror -Wextra -std=c11
CC = gcc

FILES_FOLDERS = *.c
TEST_FOLDERS = ../src/test/*.c

OS = $(shell uname)
ifeq ($(OS),Linux)
    DOP_LIB = -lcheck -lm -lpthread -lsubunit -lrt
else
    DOP_LIB = -lcheck -lm -lpthread
endif

all: clean s21_matrix.a

s21_matrix.a: clean
	$(CC) $(CFLAGS) -c $(FILES_FOLDERS)
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a
	
clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf build
	rm -rf report
	rm -rf *.info
	rm -rf testout
	rm -rf *.gcno
	rm -rf *.gcda

test: clean s21_matrix.a
	$(CC) $(CFLAGS) --coverage $(FILES_FOLDERS) $(TEST_FOLDERS) -o testout $(DOP_LIB)
	./testout

gcov_report: test
	mkdir -p report
	gcovr -r. --html --html-details -o report/index.html -e tests 
	open report/index.html
	rm -rf *.gcno *.gcda

style:
	clang-format -style=google $(FILES_FOLDERS) $(TEST_FOLDERS) *.h -i

check:
	cppcheck $(FILES_FOLDERS)

valgrind: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all  ./testout