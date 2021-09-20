CC = gcc
CFLAGS = -g -Wall -std=c99 -c
LDFLAGS = -g -Wall
BUILD_DIR = ./build

.PHONY: all test clean

all: main.o stringutils.o
	$(CC) $(LDFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/stringutils.o -o main

main.o: src/main.c build_dir
	$(CC) $(CFLAGS) src/main.c -o $(BUILD_DIR)/main.o

stringutils.o: src/utils/stringutils.c src/utils/stringutils.h build_dir
	$(CC) $(CFLAGS) src/utils/stringutils.c -o $(BUILD_DIR)/stringutils.o

build_dir:
	mkdir -p ${BUILD_DIR}

clean:
	rm -f $(BUILD_DIR)/*.o main

test: all
	@for testcase in test/* ; \
	do \
		echo "================ Running test $${testcase} ... =================" ; \
		rm $${testcase}/sample.out ; \
		touch $${testcase}/sample.out ; \
		cat $${testcase}/sample.in | ./main $$( < $${testcase}/sample.args ) > $${testcase}/sample.out ; \
		if (diff -s $${testcase}/sample.ref $${testcase}/sample.out ) ; \
		then \
			echo "================ Passed! ==================" ; \
		else \
			echo "================ Failed! ==================" ; \
		fi; \
		echo "" ; \
	done;

	@echo "================ Test Finished! =================="
