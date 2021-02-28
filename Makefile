output := dak_math.h
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

build: head types.h constants.h operators.h functions.h tail

HEAD_INFO_ENCODED := $(shell echo "$(HEAD_INFO)" |  tr '\n' '\1')
head:
	@echo "$(HEAD_INFO_ENCODED)" | tr '\1' '\n' > $(output)
tail:
	@echo "\n#endif" >> $(output)

%.h:
	@echo "\n\n// $@ \n" >> $(output)
	@cat src/$@ >> $(output)


check: build
	g++ $(output)

clean: 
	rm dak_math.h dak_math.h.gch
