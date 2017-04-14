#include <bits/stdc++.h>
using namespace std;
long long int dp[10000][10000];
long long int comb(int n, int k){
	 long long int ans=1;
   	 k=k>n-k?n-k:k;
		//  cout<<dp[n][k]<<endl;
     if(dp[n][k]!=-1)
      return dp[n][k];
    	int j=1;
    	for(;j<=k;j++,n--)
    	{
        	if(n%j==0)
        	{
            		ans*=n/j;
        	}
		else{
        		if(ans%j==0)
        		{
            			ans=ans/j*n;
        		}
			else
       	 		{
            			ans=(ans*n)/j;
        		}
    		}
	}
    dp[n][k] = ans;
		// cout<<ans<<endl;
    return ans;
}

long long int count_subseq(string s){
  long long count = 0;
  vector<int>vec[26];
  int l = s.length();
  for(int i=0;i<l;i++){
    vec[s[i]-65].push_back(i);
  }
	// cout<<l<<endl;
  for(int i=1;i<=l;i++){
    count+=comb(l,i)%1000000007;
		// cout<<count<<endl;
		for(int j=0;j<26;j++){
			// cout<<vec[s[j]-65].size()<<endl;
      if(vec[j].size()>1){
        for(int k=1;k<vec[j].size();k++){
          if(i==1){
						// cout<<vec[j].size()<<endl;
            count-=(vec[j].size()-1)%1000000007;
          }
          else if((l-vec[j][k])>=(i)){
						// cout<<vec[j][k]<<endl;
            count-=comb(l-vec[j][k]-1,i-1)%1000000007;
          }
        }
      }
    }
		// cout<<count<<endl;
  }
  return (count+1)%1000000007;
}

int main(){
  int t;
  std::string s;
	memset(dp,-1,sizeof dp);
  cin>>t;
  while(t--){
    cin>>s;
    cout<<count_subseq(s)<<endl;
  }

}
