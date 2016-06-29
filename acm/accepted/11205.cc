#include <stdio.h>
#include <string.h>
#include <algorithm>
unsigned int ones32(register unsigned int x)
{
	x -= ((x >> 1) & 0x55555555);
	x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
	x = (((x >> 4) + x) & 0x0f0f0f0f);
	x += (x >> 8);
	x += (x >> 16);
	return(x & 0x0000003f);
}

int main() {
	int cse; scanf("%d", &cse);
	while (cse--) {
		int p, n;
		scanf("%d %d", &p, &n);
		int max = 1<<p;

		int w[100];
		int u[100];

		for (int i = 0 ; i < n; i++) {
			int k = 0;
			for (int j = 0 ; j < p; j++) {
				int t;
				scanf("%d", &t);
				k <<= 1;
				k += t;
			}
			w[i] = k;
		}

		int z = p;
		for (int m = 0; m <max; m++) {
			int numactive = ones32(m);
			if (z <= numactive) continue;

			// apply mask
			for (int i = 0 ; i < n; i++) u[i] = w[i]&m;

			bool found = true;
			std::sort(u,u+n);
			for (int i = 1 ; i < n; i++)
				if (u[i]==u[i-1]) { found = false; }
			if (found && z > numactive) { z = numactive; }
		}
		printf("%d\n", z);
	}
}
