// this assumes y is clean already
// hard coded!!! argh... 

void int2char (int x, char *y) {
	y[4] = (int) x / 10000;
	y[3] = (x - (y[4] * 10000)) / 1000;
	y[2] = (x - (y[4] * 10000 + y[3] * 1000)) / 100;
	y[1] = (x - (y[4] * 10000 + y[3] * 1000 + y[2] * 100)) / 10;
	y[0] = (x - (y[4] * 10000 + y[3] * 1000 + y[2] * 100 + y[1] * 10)) / 1;
};

// multiply x by 10^y
void shift(char *x, int y) {
	int i;
	for (i=length;i>=y;i--) {
		x[i] = x[i-y];
	};
	for (i=0;i<y;i++) {
		x[i] = 0;
	};
};

void dumpit(char *x, int len) {
	int i;
	for (i=0;i<=len;i++) {
		printf("%d " , x[i]);
	};
	printf("\n");
};

// initializes all the elements to 0
void clean(char *x, int len) {
	int i;
	for (i=0;i<=len;i++){
		x[i] = 0;
	};
};

// get the input (assumes x is cleaned)
void input(char *x) {
	int i, len;
	char z[length + 2];
	printf("Please input an integer : ");
	fgets(z, length + 2, stdin); // using z as a temporary var first
	len = strlen(z);
	len--;
	if (z[len] ==  10 || z[len] == 13) {
	len-- ; // because \n is included. I HATE THIS... esp when i couldn't test it on a M$ platform...
	};
	// rearrange the string for ease of calculation
	for (i=0;i<=len;i++) {
		if (z[i]>=48 && z[i]< 58) {
			x[len-i] = z[i] - 48;
		} else {
			x[len-i] = 0;
		};
	};
};

// print the output
void output(char *z, int maxlen) {
	int i,j;
	// print it
	i = maxlen;
	while (z[i] == 0) {i--;};
	if (i < 0) {printf ("0");};		// if z contains nothing
	while (i >= 0) {
		printf("%d", z[i]);
		i--;

	};
	printf("\n");
};

int hplen(char *x, int max) {
	signed int i;
	for (i=max-1;i>=0;i--) {
		if (x[i] != 0) {return i;};
	};
	return 0;
};
// large number * integer , y = output
// returns -1, 0, and 1 for x < y, x = y and x > y respectively
int hpcmp(char *x , char *y) {
	int i;
	int xlen, ylen;
	xlen = hplen(x, length);
	ylen = hplen(y, length);
//	printf("x is %d while y is %d", xlen, ylen);
	if (ylen > xlen) {return -1;};
	if (xlen > ylen) {return 1;};
	// if we're here then xlen eq ylen;
//	dumpit(x, length);
//	dumpit(y, length);
	for (i=xlen-1;i>=0;i--) {
//		printf("%d vs %d : ", x[i], y[i]);
		if (x[i] > y[i]) {return 1;};
		if (y[i] > x[i]) {return -1;};
	};
	return 0;
};


