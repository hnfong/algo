#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  char x[51];
  char y[51];
  int l;
  //scanf("%s\n",&x);
  cin.getline(x,50);
  l = strlen(x);;
  next_permutation(x,x+l-1);
  cout << x;
  sort(x,x+l-1);
}
