BUILD_OUTPUT := build
BINARY_OUTPUT := ${BUILD_OUTPUT}/a
FLAGS := -Wall -Werror -Wshadow
OPTIMIZATION_FLAG := -O2

${BINARY_OUTPUT}: ${FILE}
	@mkdir -p ${BUILD_OUTPUT}
	@g++ ${FLAGS} ${FILE} ${OPTIMIZATION_FLAG} -o ${BINARY_OUTPUT}

run: ${BINARY_OUTPUT}
	@echo "$$(./${BINARY_OUTPUT})"

clean: 
	@rm -rf build



