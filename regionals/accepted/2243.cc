#include <stdio.h>
#include <vector>

std::vector<int> v[30];
// bool w[30][30];
int col[30];
int maxfill;
int n;

//// #define debug printf
//// #define debug(...) 

bool fill(int k, int c) {
	// check adj
//	debug("fill (%d, %d)\n", k, c );
	for (unsigned i = 0 ; i < v[k].size(); i++) {
		if (col[v[k][i]] == c) return false;
	}

	col[k] = c;

	// try filling adj
	for (unsigned i = 0 ; i < v[k].size(); i++) {
		if (col[v[k][i]] != 0) continue;

		bool found = false;
		for (int j = 1 ; j <= maxfill; j++) {
			if (j == c) continue; // don't fill the current color
			found = found || fill(v[k][i], j);
		}
		if (!found) {
			col[k] = 0;
			return false;
		}
	}

	return true;
}

int metafill() {
	// check if ans = 1
	int z = 0;
	for (int i = 0; i < n; i++) {
		z += v[i].size();
	}
	if (z == 0) return 1;


	// check if ans = 2
//	debug("check2\n" );
	memset(col, 0,sizeof(col));
	maxfill = 2;
	z = true;
	for (int i = 0; i < n; i++) {
		if (col[i] != 0) continue;
		z = z && fill(i, 1);
	}
	if (z) return 2;


	// check if ans = 3
//	debug("check3\n" );
	memset(col, 0,sizeof(col));
	maxfill = 3;
	z = true;
	for (int i = 0; i < n; i++) {
		if (col[i] != 0) continue;
		z = z && fill(i, 1);
	}
	if (z) return 3;

	return 4;
}

int main() {
	while (scanf("%d\n", &n) != EOF) {
		if (n == 0) break;

		// memset(w,0,sizeof(w));
		memset(col,0,sizeof(col));
		for (int i = 0 ; i < 30; i++) {
			v[i].clear();
		}

		for (int i = 0 ; i < n; i++) {
			char t,buf[100];
			scanf("%c:", &t);
			int a = t - 'A';
			fgets(buf, 100, stdin);
			char *c;
			for (c = buf; *c != '\n'; c++) {
				int k = *c - 'A';
				v[a].push_back(k);
				v[k].push_back(a);
				// w[a][k] = 1;
				// w[k][a] = 1;
			}
		}

		int ans = metafill();

		printf("%d channel%s needed.\n", ans, (ans == 1? "" : "s"));
	}
}
