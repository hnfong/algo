#!/bin/sh

for i in 0 1 2 3 4 5 6 7 8 9 ; do 
	echo PASS $i
	cp testdata/DIR$i.TXT DIR.TXT
	cp testdata/USER$i.TXT USER.TXT
	cp testdata/REMOVE$i.TXT R.TXT
	time ./program2
	diff R.TXT REMOVE.TXT
done
