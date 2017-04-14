#include <bits/stdc++.h>
using namespace std;
#define sync_with_c() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
struct node{
  int d,l,T;
};
int dp[101][10007];
int get_shortestL(std::vector<node>*v,int k,int n,int cty){
  if(cty==n && k>=0)
    return 0;
  if(k<=0 && cty!=n)
    return 1000000;
  if(dp[cty][k]!=1000000)
    return dp[cty][k];
  // int cst=100000;
  int sz = v[cty].size();
  for(int i=0;i<sz;i++){
    int c=1000000;
    if(v[cty][i].T<=k){
      c = v[cty][i].l+get_shortestL(v,k-v[cty][i].T,n,v[cty][i].d);
      if(c<dp[cty][k])
        dp[cty][k] = c;
    }
  }
  return dp[cty][k];
}
void fill_mat(){
  for(int i=0;i<101;i++){
    for(int j=0;j<10007;j++)
      dp[i][j]=1000000;
  }
}
int main(){
  sync_with_c();
  int t,k,n,r,s,dst,lt,tl;
  cin>>t;
  while(t--){
    cin>>k>>n>>r;
    fill_mat();
    std::vector<node>  vec[n+1];
    for(int i=0;i<r;i++){
      cin>>s>>dst>>lt>>tl;
      node temp;
      temp.d=dst;
      temp.l=lt;
      temp.T=tl;
      vec[s].push_back(temp);
    }
    int res = get_shortestL(vec,k,n,1);
    cout<<(res>=1000000?-1:res)<<endl;
  }
}
