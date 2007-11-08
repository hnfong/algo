#include <stdio.h>
#include <string.h>
#include <vector>

double w[20][20];
double v[20];
double tv[20];
int bt[20][20];

std::vector<int> ans;

#define TAG(x) printf("tag %d\n", (x));

void backtrack(int k, int t) {
	while (t >= 0) {
		if (bt[k][t] != -1) {
			backtrack(bt[k][t], t-1);
			break;
		}
		t--;
	}
	ans.push_back(k);
//	printf("%d ", k + 1);
}

	int n;	

void dump() {
	for (int i = 0 ; i < n; i++) {
		printf("%lf ", v[i]);
	}
	printf("\n");
}

int main() {
    while (scanf("%d", &n) != EOF) {
		for (int i = 0 ; i < n ; i ++)
			for (int j = 0; j< n; j++)
				if (i != j) scanf("%lf", &w[i][j]);
				else w[i][j] = 1.0;
		
		int best = 100;
		
		for (int s = 0 ; s < n; s++) { // starting point
			// init
			for (int i = 0 ; i < 20; i++)
				for (int j = 0; j < 20; j++)
					bt[i][j] = -1, v[i] = 0.0;
			
			v[s] = 1;
			for (int t = 0 ; t < n-1; t++) { // time
				// foreach edge, do some bellman-ford-like relaxation operation
				memcpy(tv,v,sizeof(tv));
				
				for (int i = 0; i < n; i++) {
					for (int j = 0 ; j < n; j++) {
						if (i == j) continue;
						// i->j
						if (tv[j] < v[i]*w[i][j]) {
							tv[j] = v[i]*w[i][j];
							bt[j][t] = i;
						}
					}
				}
				memcpy(v,tv,sizeof(v));
				
				// dump();

				// check whether 1% arbitrage is possible
				for (int i = 0 ; i < n ; i++) {
					if (v[i]*w[i][s] > 1.01) {
						if (t < best) {
							best = t;
							ans.clear();
							backtrack(i,t);
							ans.push_back(s);
						}
					}
				}
				
			}
		}
		
		if (best == 100) {
			printf("no arbitrage sequence exists\n");
		} else {
			double t = 1.0;
			for (int i = 1 ; i < ans.size(); i++) {
				t = t * w[ ans[i-1] ] [ ans[i] ];
			}
			if (t > 1.01) {
				for (int i = 1 ; i < ans.size(); i++) {
					printf("%d ", ans[i-1]+1);
				}
				printf("%d\n", ans[ans.size()-1]+1);
			} else {
				while (1) {}
			}
		}
	}
}
