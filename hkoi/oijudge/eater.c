#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>


int main( ) {
	sleep(1000);
	/*int i = 0;
	char s[100];
	void *p;*/
	//sprintf(s, "cat /proc/%d/status | grep \"[vV]\"", getpid());
	//system(s);

/*	for (i = 0 ; i < 1000; i ++ ) {
		printf("%d %d %d:\n", i+1, RLIMIT_RSS, RLIMIT_AS);
		//p = malloc( 500000 );
		//memset(p, 0, 200000);
		sleep(1);
	};
	*/
};

