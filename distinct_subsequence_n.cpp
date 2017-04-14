#include <bits/stdc++.h>
#define sync_c() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;
int last_index[26];
int dp[100001];

int main(){
	sync_c();
	int t;
	cin>>t;
	std::string s;
	while(t--){
		dp[0]=1;
		memset(last_index,0,sizeof last_index);
		cin>>s;
		int l = s.length();
		for(int i=0;i<l;i++){
			dp[i+1]=dp[i]<<1;
			dp[i+1]-=dp[i+1]>1000000007?1000000007:0;
			if(last_index[s[i]-65]!=0){
				dp[i+1]-=dp[last_index[s[i]-65]-1];
				dp[i+1]+=dp[i+1]<0?1000000007:0;
			}
			last_index[s[i]-65]=i+1;
		}
		cout<<dp[l]<<endl;
	}
	return 0;
}
