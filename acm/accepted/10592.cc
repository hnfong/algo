#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char w[50][51];
int u[50][50];
bool fighting;

int dr[] = {0,0,1,-1};
int dc[] = {-1,1,0,0};

void search(vector< pair<int,int> > &l, int r, int c, int marker, const char *matches, char opposition) {
	if (r < 0 || r >= n || c < 0 || c >= n) return;
	bool Q = false;
	if (u[r][c] & marker) return;
	for (unsigned int i = 0 ; i < strlen(matches); i++) { if (w[r][c] == matches[i]) Q = true; }
	if (!Q) return;

	u[r][c] = u[r][c] | marker;

	l.push_back(make_pair(r,c));

	for (int i = 0 ; i < 4; i++) {
		int rr = r+dr[i];
		int cc = c+dc[i];
		if (w[rr][cc] == opposition) fighting = true;
		search(l, rr, cc, marker, matches, opposition);
	}
}


int main() {
	while (scanf("%d\n", &n), n) {
		for (int i = 0 ; i < n ; i ++) gets(w[i]);
		memset(u,0,sizeof(u));

		int cse = 0;
		int zF = 0;

		for (int i = 0; i < n ; i ++) {
			for (int j = 0 ; j < n ; j++) {
				vector< pair<int,int> > a1;
				search(
						a1, // return array
						i,j, // coords
						0x1, // marker
						"*BP", // matching strings
						'X' // opposition
					  );

				if (a1.size() == 0) continue;

				int zB = 0;
				int zP = 0;

				for (vector<pair<int,int> >::iterator it = a1.begin(); it != a1.end(); it++)
				{
					vector< pair<int,int> > t;
					
					// search for B
					fighting = false;
					search (
						t, // return array
						it->first,it->second, // coords
						0x10, //marker
						"B", // matching strings
						'P' // opposition
						   );

					if (t.size() != 0) zB ++;
					if (fighting) zF ++;

					t.clear();

					// search for P
					fighting = false;
					search (
						t, // return array
						it->first,it->second, // coords
						0x100, //marker
						"P", // matching strings
						'B' // opposition
						   );

					if (t.size() != 0) zP ++;
					if (fighting) zF ++;
				}
				printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy group(s)\n", ++cse, zB, zP);
			}
		}

		printf("Total %d group(s) are in fighting position.\n\n", zF);
	}
}
