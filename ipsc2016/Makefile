.PHONY: clean run all
.PRECIOUS: %.o
CXX=xcrun clang++
CXXFLAGS=-O2
SOURCES=$(shell ls *.cc)
MAINS=$(shell ls *.cc | sed 's/\.cc$$/.exe/')

all: ${MAINS} ${TESTS}

%.exe: %.o
	${CXX} ${FRAMEWORKS} ${LDFLAGS} -o $@ $+

%.o: %.mm
	${CXX} -c ${CXXFLAGS} $<

clean:
	rm -f *.o *.exe *.test
