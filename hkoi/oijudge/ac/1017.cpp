#include <deque>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main() {
	deque<int> q1;
	deque<int> q2;
	queue<int> q;
	int x;
	cin >> x;
	q1.push_front(0);
	q2.push_front(0);
	while (cin >> x) {
		if (q1.back() < x) {
			q.push(1);
			q1.push_back(x);
		} else if (q2.back() < x) {
			q.push(2);
			q2.push_back(x);
		} else {
			cout << "NO" << endl;
			exit (0);
		};
	};
	cout << "YES" << endl;
	cout << q.front() ;
	q.pop();
	while (x = q.front()) {
		cout << " " << x ;
		q.pop();
	};
	cout << endl;
};
