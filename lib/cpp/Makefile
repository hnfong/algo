mains := $(shell ls [0-9]*.cpp | sed s/\.cpp/.exe/g)
tests := $(shell ls [0-9]*.sample.in | sed s/in/myout/g)

all: $(mains) $(tests)

%.exe: %.cpp
	clang++ -lm -O2 -std=c++11 -pipe $< -o $@

%.sample.myout: %.sample.in %.exe
	./$(word 2,$^) < $< | tee $@

clean:
	rm -vf *.exe
