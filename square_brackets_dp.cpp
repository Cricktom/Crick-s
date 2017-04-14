#include <bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
long long dp[100][100];
long long  get_count(std::vector<int>v,int n){
  int i=1,j=1;
  for(i=1;i<=(2*n);i++){
    for(j=0;j<=i;j++){
      if(i==1){
        if(j==1)
          dp[i][j]=1;
        else
          dp[i][j]=0;
      }
      else{
        std::vector<int>::iterator it;
        it = find (v.begin(), v.end(), i);
        if(it!=v.end()){
          dp[i][j] = ((j==0)?0:dp[i-1][j-1]);

        }
        else{
          dp[i][j] = dp[i-1][j+1] + ((j==0)?0:dp[i-1][j-1]);
        }
      }

    	// cout<<dp[i][j]<<"  ";
    }
    //if(i==v[v_indx])
    //  v_indx++;
    //cout<<endl;

  }
  return dp[2*n][0];
}
int main(){
	gearchange();
	int t,n,k,x;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		cin>>n>>k;
		std::vector<int> v;
		while(k--){
			cin>>x;
			v.push_back(x);
		}
		cout<<get_count(v,n)<<endl;
	}
}
