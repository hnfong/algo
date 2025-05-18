#include <stdlib.h>
#include <stdio.h>

#define ME 2147483647123456789ULL

#define HEY2

int main() {
	unsigned long long a;
	a = rand() * rand();
	int i = 10000000;
	while (i > 0) {
		a = ME;

#ifdef HEY
		
		a = (a & 0x5555555555555555ULL) + ((a >> 1 & 0x5555555555555555ULL));
		a = (a & 0x3333333333333333ULL) + ((a >> 2 & 0x3333333333333333ULL));
		a = (a & 0x0f0f0f0f0f0f0f0fULL) + ((a >> 4 & 0x0f0f0f0f0f0f0f0fULL));
		a = (a & 0x00ff00ff00ff00ffULL) + ((a >> 8 & 0x00ff00ff00ff00ffULL));
		a = (a & 0x0000ffff0000ffffULL) + ((a >> 16 & 0x0000ffff0000ffffULL));
		a = (a & 0x00000000ffffffffULL) + ((a >> 32 & 0x00000000ffffffffULL));

#endif

#ifndef HEY
		int b = 0;
		while (a != 0) {
			b += a & 1;
			a = a >> 1;
		};
#endif
		i--;
	};

};
