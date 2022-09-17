CC=gcc -std=c11
CFLAGS= -Wall -Wextra -Werror
GCOV_LIBS=--coverage
BUILD_PATH= ./backend/
SOURCE_PATH = ./backend/
SOURCES= $(SOURCE_PATH)main_test.c  $(SOURCE_PATH)parser.c $(SOURCE_PATH)support_func.c
H = $(SOURCE_PATH)parser.h
LIBO=s21_3DViewer.o
LIBA=s21_3DViewer.a
EXE=test.out
MKF = makefile.qt # создаю файл чтоб читался как makefile для install

OS = $(shell uname)

ifeq ($(OS), Darwin)
	TST_LIBS=-lcheck -lm -g
else
	TST_LIBS=-lcheck -pthread -lrt -lm -D_GNU_SOURCE -lsubunit -lpthread -g
endif

all: install

build:
	mkdir build
	cd ./build/ && qmake ../ && make

install:
	make clean
	mkdir build
	qmake -o $(MKF) && make -f $(MKF) && make clean -f $(MKF) && rm $(MKF) && mv 3DViewer.app build

uninstall:
	rm -rf build*

dist:
	rm -rf Archive_3DViewer/
	mkdir Archive_3DViewer/
	mkdir Archive_3DViewer/src
	cp Makefile *.c *.h *.pro *.cpp *.ui *.user Archive_3DViewer/src/
	tar cvzf Archive_3DViewer.tgz Archive_3DViewer/
	# mv Archive_SmartCalc_v1.0.tgz $(HOME)/Desktop/
	rm -rf Archive_3DViewer/

dvi: 
	open dvi.html

clean:
	@rm -rf *.a && rm -rf *.o *.out
	@rm -rf *.info && rm -rf *.gcda && rm -rf *.gcno &&  rm -rf *.gcov
	@rm -rf report/ && rm -rf *.
	@rm -f $(SOURCE_PATH)main
	@rm -rf .qmake.stash
	@rm -rf ./build*
	@rm -rf 3DViewer
	@rm -rf 3DViewer Archive_3DViewer.tgz
	@rm -rf ./qt/build*

test: s21_3DViewer.a
	$(CC) $(CFLAGS) tests.c -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)

d:  # dont use!
	$(CC) $(CFLAGS) $(TST_LIBS) $(SOURCES) -o $(BUILD_PATH)main
	$(BUILD_PATH)main

rebuild: clean all

s21_3DViewer.a: clean
	$(CC) $(CFLAGS) -c $(SOURCES) -o $(BUILD_PATH)$(LIBO)
	ar rcs $(SOURCE_PATH)$(LIBA) $(SOURCE_PATH)$(LIBO)
	ranlib $(SOURCE_PATH)$(LIBA)

gcov_report: s21_3DViewer.a
	$(CC) $(CFLAGS) $(GCOV_LIBS) tests.c $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)
	lcov -t "test" -c -d $(BUILD_PATH) --output-file $(BUILD_PATH)coverage.info
	genhtml $(BUILD_PATH)coverage.info --output-directory $(BUILD_PATH)report/
	open ./report/index.html


leaks:
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt 	$(BUILD_PATH)$(EXE)

check:
	@echo
	@echo ===STYLE TEST===
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	rm CPPLINT.cfg

rebuild: clean uninstall all

reinstall: clean uninstall install
