/* Sidney's Code Snipplets */

/* Count the number of ones in binary representation of a 32bit int */
unsigned int ones32(register unsigned int x)
{
    x -= ((x >> 1) & 0x55555555);
    x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
    x = (((x >> 4) + x) & 0x0f0f0f0f);
    x += (x >> 8);
    x += (x >> 16);
    return(x & 0x0000003f);
}

/* max return value is 31 (most sig), min is -1 (a==0); 2^n will return n */
typedef unsigned int u32;
int sig_bit(u32 a) {
	int z = 0;
	if (a & 0xFFFF0000) { z += 16; a >>= 16; }
	if (a & 0xFF00) { z += 8; a >>= 8; }
	if (a & 0xF0) { z += 4; a >>= 4; }
	if (a & 12) { z += 2; a >>= 2; }
	if (a & 2) { z += 1; a >>= 1; }
	return z+a-1;
}

/* Sample of operator overloading syntax for stuff like std::sort() */
struct nod {
    int r,c,v;
    nod (int rr, int cc,int vv) { r = rr; c = cc; v = vv; }
    bool operator<(const nod &t) const { return v > t.v; }
};

/* example of std::hash(). Only defined for char* and built-in integral types */
{ 
	hash<const char *> H;
	printf("%d\n", H("hello"));
}

/* constant time fast exponentation, computes a^b mod n in 32 iterations */
typedef unsigned int u32;
u32 mod_exp(u32 a, u32 b, u32 n) {
	unsigned long long d;
	d = 1;
	for (int i = 31; i >= 0; i--) {
		d = (d * d) % n;
		if ((b & (1 << i)) >> i)
			d = (d*a) % n;
	}
	return (u32) d;
}

