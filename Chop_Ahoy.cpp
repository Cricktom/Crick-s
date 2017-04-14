#include <bits/stdc++.h>
using namespace std;
#define sync_with_c() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
int get_ways(string s, int i,int j,int k,int n){

  if(k==n){
    if(j>=i)
      return 1;
    return 0;
  }
  int r1=0,r2=0;
  r1 = get_ways(s,i,j+(s[k]-48),k+1,n);
  if(j>=i)
    r2 = get_ways(s,j,s[k]-48,k+1,n);
  return r1+r2;
}

int main(){
  sync_with_c();
  std::string s;
  int t=1;
  cin>>s;
  while(s!="bye"){
    cout<<t<<". "<<get_ways(s,0,s[0]-48,1,s.length())<<endl;
    t++;
    cin>>s;

  }
}
