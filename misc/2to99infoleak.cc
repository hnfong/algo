#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

/*
 * Solution to a moliu problem forwarded (or retold) by cx:
 *  cx picked two numbers between 2 and 99.
 *  cx told Si the sum of the two numbers.
 *  cx told cychoi the product of the two numbers.
 *  Si and cychoi were really smart.
 *  Here's the conservation:
 *  Si: "hahaha, cychoi, you have no clue what the sum is!"
 *  cychoi: "Oh! i know the two numbers la!"
 *  Si: "oh! i know too la!"
 *
 *  Q: what are the two numbers? also, show that they are unique.
*/

short mem[10000];

bool uniquefactor(int n) {
	if (mem[n]==0) {
		int z = 0;
		double bound = sqrt(n)+0.001;
		for (int i = 2; i<= bound; i++) {
			if (n%i == 0 && n/i >= 2 && n/i <= 99) {
				z++;
			}
		}
		if (z == 1) {
			mem[n] = 1;
		} else {
			mem[n] = -1;
		}
	}
	return mem[n] == 1;
}

vector<pair<int,int> > possiblepairs;
map<int,set<int> > cnt;
set<int> possibleproducts;

int main(){
	memset(mem,0,sizeof(mem));
	for (int a = 2; a <= 99; a++) {
		for (int b = a; b <= 99; b++) {
			int sum = a+b;

			// filter out the pairs where cychoi has a chance to be able to guess the sums.
			bool cychoiguessable = false;
			for (int k = 2; k <= sum/2; k++) {
				if (uniquefactor( k* (sum-k)) ) {
					cychoiguessable = true;
				}
			}
			if (cychoiguessable) continue;

			// record the sums that can produce a non-cychoiguessable product
			for (int k = 2; k <= sum/2; k++) {
				int t = k*(sum-k);
				cnt[t].insert(sum);
			}

			// record the possible pairs
			possiblepairs.push_back(make_pair(a,b));
		}
	}

	// find the possible products that would make cychoi say "i know the numbers la!"
	for (map<int,set<int> >::iterator it = cnt.begin(); it != cnt.end(); it++) {
		if (it->second.size() ==1) possibleproducts.insert(it->first);
	}

	// find the possible a,b that would make Si say "i know too!"
	for (vector<pair<int,int> >::iterator it = possiblepairs.begin(); it!= possiblepairs.end(); it++) {
		int a = it->first;
		int b = it->second;
		int sum = a+b;
		int z = 0;
		for (int k = 2; k <= sum/2; k++) {
			if ( possibleproducts.count(k*(sum-k)) ) {
				z++;
			}
		}
		if (z == 1 && possibleproducts.count(a*b) ) printf("Answer: %d %d\n", a,b);
	}
}
