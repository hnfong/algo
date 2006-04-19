#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	struct person {
		string s;
		char sex;
		int score;
	};
	person w[100];
	person p;
	int i,j,k,n;
	double f;
	string s;
	char c;
	cin >> n;
	for (i=0;i<n;i++) {
		s.clear();
		while ((c = getc(stdin)) && (c != ',')) {
			if (c >= 32) s.push_back(c);
		};
		w[i].s = s;
		w[i].sex = getc(stdin);
		c = getc(stdin);
		cin >> w[i].score;
		//cout << "!" << w[i].s << "|||" << w[i].sex << "|||" << w[i].score << endl;
	};
	for (i=0;i<n;i++) {
		for (j=i;j>0;j--) {
			if (w[j].score > w[j-1].score) {
				p = w[j];
				w[j] = w[j-1];
				w[j-1] = p;
			};
		};
	};
	/*for (i=0;i<n;i++) {
		cout << "!" << w[i].s << "|||" << w[i].sex << "|||" << w[i].score << endl;
	};*/
	if (w[0].sex=='F'||w[1].sex=='F'||w[2].sex=='F') {
		// There, done.
	} else {
		f = w[0].score+w[1].score+w[2].score;
		k = 0;
		for (i=3;i<n;i++) {
			if (w[i].sex=='F') {
				k = i;
				break;
			};
		};
		if ((k>0) && (f < (w[0].score+w[1].score+w[k].score)*1.1)) {
			w[2] = w[k];
		};
	};

	for (i=0;i<3;i++) {
		for (j=i;j>0;j--) {
			if (strcasecmp(w[j].s.c_str(), w[j-1].s.c_str()) < 0) {
				p = w[j];
				w[j] = w[j-1];
				w[j-1] = p;
			};
		};
	};
	for (i=0;i<3;i++) {
		cout << w[i].s << endl;
	};
};

