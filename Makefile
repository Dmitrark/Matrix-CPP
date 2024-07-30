LIBRARY_NAME = s21_matrix_oop.a
COMPILER = g++
PATH_TO_C_FILES = functions/*.cpp
PATH_TO_TEST_FILES = tests/*cc tests/*.h

GCC_FLAGS = -std=c++17 -Wall -Wextra -Werror -g
GCC_LIBS = -lstdc++ -lgtest -pthread -I.

all: $(LIBRARY_NAME)

$(LIBRARY_NAME):
	$(COMPILER) $(GCC_FLAGS) $(GCC_LIBS) $(PATH_TO_C_FILES) -c
	ar rcs $(LIBRARY_NAME) *.o
	ranlib $(LIBRARY_NAME)
	rm -r *.o

test: clean $(LIBRARY_NAME)
	$(COMPILER) $(PATH_TO_TEST_FILES) $(GCC_LIBS) -L. -l:$(LIBRARY_NAME) -o test
ifeq ($(MAKECMDGOALS), test)
	./test
endif

clean:
	if [ -f "test" ]; then rm -r test; fi
	if [ -f "$(LIBRARY_NAME)" ]; then rm -r $(LIBRARY_NAME); fi

valgrind: test
	valgrind --tool=memcheck --leak-check=yes --log-file=report.txt --quiet ./test
	cat report.txt
	rm report.txt
	make clean

clang-check:
	clang-format --style=Google -n *.h $(PATH_TO_C_FILES) $(PATH_TO_TEST_FILES)

clang-fix:
	clang-format --style=Google -i *.h $(PATH_TO_C_FILES) $(PATH_TO_TEST_FILES)
