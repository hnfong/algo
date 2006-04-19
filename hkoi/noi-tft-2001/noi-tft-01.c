#include <stdio.h>
#include <math.h>

/*
short int have;
// recursion is EVIL... YEAH!! *I* _AM_ evil!!! MUHAHAHAHAHAHAH!!!
int have_consecutive_one (long int number, short int last){
	int tmp;
	if (number <= 0) {return 0;}
//	if (fmod(number, 2) > 0.9) { // THIS REALLY SUCKS MY RUNTIME
	tmp = number / 2;
	if (((float) number /2) != tmp ) {
		if (last == 1) {have = 1;return 0;} ;
		have_consecutive_one(tmp, 1) ;
	} else {
		have_consecutive_one(tmp, 0) ;
	};
	if (have == 1) {return 1;};
};
*/

// faster than above, but still ... only successful if runtime > 1 min.. ;(
short int have_consecutive_two (long int number) {
	short int last;
	last = 0;
	while (number > 0) {
		if (((number / 2) * 2)  != number) {
//		if (((double) number /2) != (number = number / 2) ) {
			if (last==1) {return 1;};
			last = 1;
		} else {
			last = 0;
		};
		number = number / 2;
	};
	return 0;
};

int main() {
	long int i;
	long int tmp;
	tmp = 30000000;
	for (i=1;i<30000000;i++){
			tmp -= (have_consecutive_two (i));
	};
	printf("%d ", tmp);
	return 0;
};

