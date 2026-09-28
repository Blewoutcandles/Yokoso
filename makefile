BUILD_OUTPUT := build
BINARY_OUTPUT := ${BUILD_OUTPUT}/${FILE}.exe
SRC_FILES := $(wildcard src/*.cpp)
CPPFLAGS := -I.
FLAGS := -Wall -Werror -Wshadow
OPTIMIZATION_FLAG := -O2

${BINARY_OUTPUT}: ${FILE} ${SRC_FILES}
	@mkdir -p ${BUILD_OUTPUT}
	@g++ ${CPPFLAGS} ${FLAGS} ${FILE} ${SRC_FILES} ${OPTIMIZATION_FLAG} -o ${BINARY_OUTPUT}

run: ${BINARY_OUTPUT}
	@echo "----- OUTPUT -----\n$$(./${BINARY_OUTPUT})"

clean: 
	@rm -rf build