output := dak_math.h
files := src/types.h src/constants.h src/operators.h src/functions.h
COMMIT_SHA1 := $(shell git rev-parse --short HEAD)
DATE := $(shell date +"%m-%d-%y")
LICENSE := $(shell cat LICENSE | tr '\n' '\1')

define HEAD_INFO
/*											\1
THIS FILE IS GENERATED 						\1
SOURCE: https://github.com/trobol/dak_math 	\1
COMMIT SHA1: $(COMMIT_SHA1) 				\1
DATE: $(DATE)								\1
LICENSE: 									\1
											\1
$(LICENSE)									\1
											\1
*/											\1
#ifndef _DAK_MATH_H							\1
#define _DAK_MATH_H							\1
endef

HEAD_INFO_ENCODED := $(shell echo "$(HEAD_INFO)" |  tr '\n' '\1')
build:
	@echo "$(HEAD_INFO_ENCODED)" | tr '\1' '\n' > $(output)
	@cat $(files) >> $(output)
	@echo "\n#endif" >> $(output)

compile: build
	g++ $(output)

