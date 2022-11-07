##
# async_io
#
# @file
# @version 0.1

CC:=clang

CSource := $(wildcard src/*.c)
BASE_DIR := $(shell pwd)
BUILD_DIR := ${BASE_DIR}/bin
CSync := $(wildcard ${BASE_DIR}/src/sync.c)
CAsync := $(wildcard ${BASE_DIR}/src/async.c)

all: sync async

bin:
	if ! [ -f ./bin/ ]; then 						\
		echo bin folder not exists creating ... ;		\
		mkdir ./bin     					    ;	\
	fi

sync: bin
	@echo $@ compiling ...
	@cd ${BUILD_DIR} && \
	${CC} ${CSync} -o ./sync && \
	cd ${BASE_DIR}

async: bin
	@echo $@ compiling ...
	@cd ${BUILD_DIR} && \
	${CC} ${CAsync} -o ./async && \
	cd ${BASE_DIR}

run: all
	@echo "test programs with give async.c source file"
	@echo ":-----------: sync version :-----------:"
	${BUILD_DIR}/sync ${BASE_DIR}/src/async.c
	@echo ":-----------: async version :-----------:"
	${BUILD_DIR}/async ${BASE_DIR}/src/async.c

clean: bin
	rm -f $(wildcard  ./bin/*.o)

echo:
	@echo -e "CC: ${CC} \n BASE_DIR: ${BASE_DIR} \n BUILD_DIR: ${BUILD_DIR} \n Headers: ${Headers} \n CSource: ${CSource}"


# end
