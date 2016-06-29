#include <stdio.h>

int main() {
	char s[1000];
	char *name1,*name2,*flight,*distance_str;
	int distance;
	while (!feof(stdin)) {
		fgets(s,1000,stdin);
		name1 = s;
		name2 = strstr(s, ",");
		*name2 = 0;
		name2++;
		flight = strstr(name2,",");
		*flight = 0;
		flight++;
		distance_str = strstr(flight,",");
		*distance_str = 0;
		distance_str++;
		distance = atoi(distance_str);
	};
};
