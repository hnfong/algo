#include <iostream>
#include <queue>
#include <string.h>

/*
 @JUDGE_ID: 20044WC 10477 C++
 */

using namespace std;

struct dat {
	int x,y,s,d;
};

// 0 = knight, 1 = mutant knight, 2 = mutant pawn
int hc[3][8][2] = {
	{{1,2},{1,-2},{2,1},{2,-1},{-1,-2},{-1,2},{-2,-1},{-2,1}},
	{{1,3},{1,-3},{3,1},{3,-1},{-1,-3},{-1,3},{-3,-1},{-3,1}},
	{{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}
};
int n;
int u[21][21][3];
queue<dat> q;
int mypush(int x, int y, int s, int d) {
	dat pusher;
	if (x<=0||y<=0||x>n||y>n) { return -1; }
	if (u[x][y][s]) { return -2; }
	u[x][y][s] = 1;
	pusher.x = x;
	pusher.y = y;
	pusher.s = s;
	pusher.d = d;
	q.push(pusher);
	////cout << x << " " << y << " " << s << endl;
};
int main() {
	dat t;
	int i,j,k,nt,ni,s,d;
	int x1,y1,x2,y2;
	ni = 0;
	while (true) {
		cin >> n >> nt;
		if (n == 0) break;
		ni ++;
		cout << "Set " << ni << ":" << endl;
		while (nt > 0) {
			while (!q.empty()) {q.pop(); };
			memset(u,0,sizeof(u));
			nt --;
			cin >> s >> d;
			x1 = (s-1) % n + 1;
			y1 = (s-1) / n + 1;
			x2 = (d-1) % n + 1;
			y2 = (d-1) / n + 1;
			mypush(x1,y1,0,0);
			mypush(x1,y1,1,0);
			mypush(x1,y1,2,0);
			t.x = -1;
			while (!q.empty()) {
				t = q.front(); q.pop();
				//cout << "From: " << t.x << " " << t.y <<  " " << t.s << " " << t.d << endl;
				if (t.x==x2&&t.y==y2) { break; };
				k = (t.s + 1) % 3;
				for (i=0;i<8;i++) {
					if (k == 2 && i>=4) {
						if (t.x+hc[k][i][0]==x2 && t.y+hc[k][i][1]==y2)
							mypush(t.x+hc[k][i][0], t.y+hc[k][i][1], k, t.d+1);
						continue;
					};
					mypush(t.x+hc[k][i][0], t.y+hc[k][i][1], k, t.d+1);
				};
			};
			if (t.x==x2&&t.y==y2) { 
				cout << t.d << endl;
			} else {
				cout << "?" << endl;
			};
		};
	};
};
