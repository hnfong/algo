#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int tc;
	scanf("%d\n", &tc);
	while (tc > 0) {
		tc --;
		int coke, one,five,ten;
		scanf("%d %d %d %d\n", &coke, &one, &five, &ten);

		int cnt = 0;

		while (coke > 0) {
			if (ten > 0) {
				ten--;
				if 
				cnt++;
				one+=2;
				goto hell;
			};

			if (five > 0) {
				if (five >= 2) {
					if (five*2/3 >= coke) {
						five -= 2;
						cnt += 2;
						goto hell;
					};
				};
				five--;
				one-=3;
				cnt+=4;
				goto hell;
			};

			cnt+=8;
			
			hell:
			coke --;
		};
		printf("%d\n", cnt);
	};
};
