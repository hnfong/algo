// do addition
void addition(char *x, char *y , char *z, int maxlen) {
	int i,j,c; // c is carry
	c = 0; 
	for (i=0;i<=maxlen;i++) {
		if ((z[i] = x[i] + y[i] + c) >= 10) {
			z[i] = z[i] - 10;
			c = 1;
		} else {
			c = 0;
		};
		
	};
};

void hpadd() {
	char x[length+1];		//1st number
	char y[length+1];		//2nd number
	char z[length+2];	//result
	//initialize the variables....
	clean(x, length); 
	clean(y, length); 
	clean(z, length + 1);
	input (x);
	input (y);
	
	// if string 1 is greater than string 2...
	addition (x, y, z, length);
	output (z, length + 1);
	return;
};

