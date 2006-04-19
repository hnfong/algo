#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char s[10000];
	unsigned long long a,b,c;
	char *t, *t2, *s1, *s2, *s3;
	char m1[10000];
	char m2[10000];

	while (!feof(stdin)) {
		memset(s,0,sizeof(s));
		memset(m1,0,sizeof(m1));
		memset(m2,0,sizeof(m2));
		fgets(s,10000,stdin);
		if (feof(stdin)) break;
		printf("%s",s);

		t = s;
		while (!(*t >= '0' && *t <= '9')) { t++ ;};
		t2 = t;
		while (*t2 >= '0' && *t2 <= '9') { t2++ ;};
		strncpy(m1,t,t2-t);
		s1 = m1;
		/*printf("(%s)", s1);*/

		while (*t2 != '+' && *t2 != '*') { t2 ++ ; };
		s2 = t2;
		/*printf("%c", *s2);*/

		t = t2;
		while (!(*t >= '0' && *t <= '9')) { t++ ;};
		t2 = t;
		while (*t2 >= '0' && *t2 <= '9') { t2++ ;};
		strncpy(m2,t,t2-t);
		s3 = m2;
		/*printf("(%s)", s3);
		printf("\n");*/


		/* remove leading zeros */
		while (*s1 == '0') { s1 ++ ; };
		while (*s3 == '0') { s3 ++ ; };


		/* See if the first number is too big */
		if (strlen(s1) > 10) { a = -1; } else {
			a = atoll(s1);
			if (a > 2147483647) { a = -1; };
		};
		if (a == -1) printf("first number too big\n");
		
		/* See if the second number is too big */
		if (strlen(s3) > 10) { b = -1; } else {
			b = atoll(s3);
			if (b > 2147483647) { b = -1; };
		};
		if (b == -1) printf("second number too big\n");

		/*printf("debug %s %c %s == %lld %c %lld\n", s1,*s2,s3,a,*s2,b);*/

		/* see if the result is too big */
		if (a == -1) {
			if (b == 0 && *s2 == '*') continue;
			printf("result too big\n");
		} else if (b == -1) {
			if (a == 0 && *s2 == '*') continue;
			printf("result too big\n");
		} else {
			if (*s2 == '+') {
				c = a + b;
				if (c > 2147483647) printf("result too big\n");
			};
			if (*s2 == '*') {
				c = a * b;
				if (c > 2147483647) printf("result too big\n"); 
			};
		};
	};
	return 0;
};
