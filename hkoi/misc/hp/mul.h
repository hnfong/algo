void small_multiply(char *x, int z, char *y, int maxlen) {
	int i,j, tmp;
	char a[length+1];
	char b[length+1];
	clean(y, length);
	for (i=0;i<=maxlen;i++) {
		clean(b, length);
		tmp = x[i] * z;
		int2char(tmp, b);
		shift(b, i);
		addition(b,y,y, maxlen);
	};
};

// do multiplication
void multiply (char *x, char *y, char *z, int maxlen) {
	char a[length+1];
	int j;
	for (j=0;j<=maxlen;j++) {
		small_multiply(x, y[j], a, maxlen);
		shift(a, j);
		addition(a, z, z, maxlen);
	};
};

void hpmul() {
	char x[length+1];
	char y[length+1];
	char z[length+1];
	clean(x, length);
	clean(y, length);
	clean(z, length);
	input (x);
	input (y);
	multiply(x, y, z, length);
	output (z, length);
};
