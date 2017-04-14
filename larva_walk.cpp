#include <bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
long long int dp[29][29][15];
long long int get_count(int x,int y, int n){
  if(dp[x][y][n]!=-1){
    // cout<<"if  "<<dp[x][y]<<"  y=  "<<y<<"   x=  "<<x<<endl;
    return dp[x][y][n];
  }
  if (n==0 && (x==14 && y==14)){
    // dp[x][y]=1;
    return 1;
  }
  if(n==0 && (x!=14 || y!=14)){
    // dp[x][y]=0;
    return 0;
  }
  dp[x][y][n] = (get_count(x+1,y,n-1)+get_count(x-1,y,n-1)+get_count(x+1,y+1,n-1)+get_count(x-1,y-1,n-1)+get_count(x,y-1,n-1)+get_count(x,y+1,n-1));
  return dp[x][y][n];
}

int main(){
  gearchange();
  int t,n;
  int x = pow(2,31);
  cin>>t;
  while(t--){
    memset(dp,-1,sizeof dp);
    // for(int i=0;i<20;i++){
    //   for(int j=0;j<20;j++)
    //     dp[i][j]=-1;
    // }
    // cout<<dp[0][0]<<endl;
    cin>>n;
    cout<<(get_count(14,14,n))<<endl;/*<<dp[0][0]<<endl;;*/
  }
}
