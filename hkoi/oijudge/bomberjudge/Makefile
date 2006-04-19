all: oiio.o bomberjudge.o 
	g++ -o bomberjudge *.o
run-bomberjudge:
	./bomberjudge bomber.in bomber.out bomber.ans
clean:
	rm -f oiscanf.o bomberjudge bomberjudge.o
run: run-bomberjudge

package: clean
	sh ./package
