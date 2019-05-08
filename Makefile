# Deyuan. May 2019

.PHONY: all clean

PYCONFIG := ~/anaconda3/bin/python3.7-config
CFLAGS := $(shell $(PYCONFIG) --cflags)
LDFLAGS := $(shell $(PYCONFIG) --ldflags)

all:
	g++ $(CFLAGS) $(LDFLAGS) main.cc dummy_module.cc embed_and_extend.cc -o demo.out

clean:
	rm -rf demo.out

