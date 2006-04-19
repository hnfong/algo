// do subtraction
void subtract(char *x, char *y , char *z) {
	int i,j,b ; // b is borrow
	b = 0;
	for (i=0;i<=length;i++) {
		if ((z[i] = x[i] - y[i] - b) < 0) {
			z[i] = z[i] + 10;
			b = 1;
		} else {
			b = 0;
		};
		
	};

};


void hpsub() {
	char x[length+1];		//1st number
	char y[length+1];		//2nd number
	char z[length+1+1];	//result

	//initialize the variables....
	clean(x, length); clean(y, length); clean(z, length + 1);
	input (x);
	input (y);
	
	// if string 1 is greater than string 2...
	if (hpcmp(x, y) >= 0) {
		subtract (x, y, z);
		output (z, length);
	} else {
		subtract (y, x, z);
		printf("-");
		output (z, length);
	}; 
};


