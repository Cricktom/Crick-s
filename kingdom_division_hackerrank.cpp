#include <bits/stdc++.h>
using namespace std;
#define FOR(init,term) for(int i=init;i<term;i++)

int main(){
  int n,v1,v2;
  cin>>n;
  long long int dp[n];
  dp[1]=dp[2]=2;
  std::vector<int> vect[n+1];
  FOR(1,n){
    cin>>v1>>v2;
    if(i>2){
        if(vect[v1].size()>1 || vect[v2].size()>1)
          dp[i] = dp[i-1];
        else
          dp[i] = dp[i-1]+vect[vect[v1].size()==1?vect[v1][0]:vect[v2][0]].size();
    }
    vect[v1].push_back(v2);
    vect[v2].push_back(v1);

  }
  cout<<dp[n-1]<<endl;
}
