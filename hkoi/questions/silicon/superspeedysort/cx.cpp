#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  vector<int> v;
  int a,b,m,k;
  cin>>a>>b>>m>>k;
  int t=0;
  a%=b;
  for(int i=0;i<m;++i)
    v.push_back(t=(t+a)%b);
  sort(v.begin(),v.end());
  while(cin>>b)
    cout<<v[b-1]<<endl;
}

