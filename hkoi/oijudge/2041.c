#include <stdio.h>

#define ACUR 1
#define BCUR -1

#define THRESHOLD 1E-10

/* #define DEBUG */

int main() {
	int i,j,k,m,n;
	double a,b,c,d,t,o;
	int state;

	scanf("%d %d", &n, &m);
	t = (double) m;
	o = t;
	state = ACUR;
	
	for (i=0;i<n;i++) {
		c = d;
		scanf("%lf", &d);

		if (i == 0) { continue; };
		if (d > c) {
			/* increasing */

			if (state == BCUR) {
				/* original state is decreasing */
				t = t / c;
				o = t;
#ifdef DEBUG
				printf("A<-B %lf = %lf\n", c, t); 
#endif
			};

			state = ACUR ;
		} else if (d < c) {
			/* decreasing */
			if (state == ACUR) {
				/* original state is increasing */
				t = t * c;
#ifdef DEBUG
				printf("A->B %lf = %lf\n", c, t);
#endif
			};
			state = BCUR;
		};
	};
	if (state == BCUR) {
		o = t / d;
#ifdef DEBUG
		printf("A<-B %lf = %lf\n", d, o);
#endif
	};
	printf("%.2lf\n", o);
	return 0;
};
