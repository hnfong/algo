#include <stdio.h>
#include <string.h>

#define WEST 1
#define NORTH 2
#define EAST 4
#define SOUTH 8

using namespace std;

struct st {
	char w[24];
	char l;
};

int qh = 0; int qt  = 0;

st q[100000];

void push(st t, int l, int d) {
	if (t.w[l] & NORTH > 0) {
		1
};

st pop () {
	qh++;
	return q[qh];
};


int main() {
	st t;
	int x , y;
	memset(q,0,sizeof(q));
	scanf("%d %d\n", &x, &y);
	l = y * 6 + x;
	for (int i = 0 ; i < 24 ; i ++ )
		scanf("%d", &t.w[i]);
	
	q[qt] = t;
	
	
};

