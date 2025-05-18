void hpfact() {
	int i, j; // counter
	int x; // stores the value to be muliplied
	char tmp[length+1]; // tmp
	char z[length+1]; // stores the output;
	char zero[length+1]; // stores the value 0
	char in[8];
	double loggy;
	clean (zero, length);	
	clean (tmp, length);
	clean (z, length);
	z[0] = 1;
	// do the input (this is different from those huge number inputs)
	printf("Enter a integer : ");
	clean(in, 4);
	fgets(in, 5, stdin);
	i=4;
	while (in[i] < 48) {
		in[i] = 0;
		i--;
	};
	x = 0;
	for (j=0;j<=i;j++) {
		x += (in[j] - 48) * pow(10, i - j);
	};
	
	// calculate whether length is enough
	loggy = 0;
	for (j=x;j>1;j--) {
		loggy += log10(j);
	};
	if (loggy+1 > length) {
		printf("Length is not enough. Please edit the LENGTH constant in hp.c to an integer > %g", loggy);
		return;
	};
	while (x != 0 ) {
		addition(zero, z, tmp, length);
		clean(z, length);
		small_multiply(tmp, x , z, length);
		x--;
	};
	output(z, length);
};
