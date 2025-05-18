// program template to be typed once and copied

#include <stdio.h>
#include <string.h>
#include <algorithm>
// #include <ext/hash_map>
#include <vector>
// #include <map>
// #include <set>
// #include <queue>
// #include <iostream>

using namespace std;
// using namespace __gnu_cxx;

#define debug printf
#define foreach(v,c) for (__typeof__((c).begin()) v = (c).begin(); v != (c).end(); v++)

const int E=1e-8;
struct pt{
  int x,y;
};

int isleft(const pt& a,const pt& b,const pt& c)
{
  return (b.x-a.x)*(c.y-a.y)-
         (b.y-a.y)*(c.x-a.x);
}


int dist2(const pt& a,const pt& b)
{
  return ((b.x-a.x)*(b.x-a.x)+ (b.y-a.y)*(b.y-a.y));
}

vector<pt> P;
bool operator<(
  const pt& a,const pt &b)
{
  return
    (isleft(P[0],b,a)>0||
    (isleft(P[0],b,a)==0&&
    dist2(P[0],a)<dist2(P[0],b)));
}

vector<pt>S;
void convexhull(const vector<pt>& p)
{
  P=p;
  int x=P[0].x,y=P[0].y;
  int z=0;
  for(unsigned int i=1;i<P.size();++i)
    if (P[i].y<y||
        y==P[i].y&&P[i].x<x){
      x=P[i].x;
      y=P[i].y;
      z=i;
    }
  swap(P[0],P[z]);
  sort(P.begin()+1,P.end());
  S.push_back(P[0]);
  S.push_back(P[1]);
  for(unsigned int i=2;i<P.size();++i){
    while (S.size()>=2 &&      
       isleft(S[S.size()-2],
       P[i],S[S.size()-1])<=0)
	S.pop_back();
    S.push_back(P[i]);
  }
}

int main() {
	int a,b,r;
	char buf[10000];
	while (fgets(buf, sizeof(buf), stdin) != NULL) {
		S.clear();
		P.clear();
		char *s = buf;
		while ( (r = sscanf(s, "(%d,%d)", &a, &b)) ) {
			if (r == EOF) break;
			s = strstr(s, " ");
			pt p ;
			p.x = a;
			p.y = b;
			P.push_back(p);

			if (s == NULL) break; 
			s++;

		}
		if (P.size() == 0) break;
		convexhull(P);

		foreach (p, S) {
			printf("(%d,%d) ", (int) p->x, (int) p->y);
		}

		printf("(%d,%d)\n", (int) S[0].x, (int)S[0].y);
	}
	return 0;
}

