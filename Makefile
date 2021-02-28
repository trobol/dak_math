output := dak_math.h
files := src/head.h src/types.h src/constants.h src/operators.h src/functions.h src/tail.h

build:
	cat $(files) > $(output)

compile: build
	g++ $(output)