#include <stdio.h>
#include <math.h>


int x[9];
int y[9];

double distance(int a,int b) {
	return sqrt((double) (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
};

int main() {
	double c[9];
	double e;
	int i;
	scanf("%d %d %d %d", &x[0], &y[0], &x[3], &y[3]);
	scanf("%d %d %d %d", &x[4], &y[4], &x[7], &y[7]);

	x[1] = x[3]; y[1] = y[0];
	x[2] = x[0]; y[2] = y[3];
	x[5] = x[7]; y[5] = y[4];
	x[6] = x[4]; y[6] = y[7];

	c[4] = c[5] = c[6] = c[7] = -1;
	// 8 cases
	c[0] = distance(3,4);
	c[1] = distance(2,5);
	c[2] = distance(0,7);
	c[3] = distance(1,6);
	if ((x[0]<=x[5] && x[5]<=x[3]) || (x[0]<=x[4] && x[4]<=x[3]) || (x[4] <= x[0] && x[0] <= x[5])) c[4] = y[4] - y[3];
	if ((y[0]<=y[6] && y[6]<=y[3]) || (y[0]<=y[4] && y[4]<=y[3]) || (y[4] <= y[0] && y[0] <= y[6])) c[5] = x[0] - x[7];
	if ((x[0]<=x[5] && x[5]<=x[3]) || (x[0]<=x[4] && x[4]<=x[3]) || (x[4] <= x[0] && x[0] <= x[5])) c[6] = y[0] - y[7];
	if ((y[0]<=y[6] && y[6]<=y[3]) || (y[0]<=y[4] && y[4]<=y[3]) || (y[4] <= y[0] && y[0] <= y[6])) c[7] = x[4] - x[3];

	e = 9999999;
	
	for (i=0;i<8;i++) {
		if (c[i] < e && c[i] >= 0) { e = c[i]; };
	};
	printf("%.3f\n", e);
	return 0;
};

