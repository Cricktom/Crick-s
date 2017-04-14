#include <bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
long long dp[1000][1000];
long long  get_count(std::vector<int>v,int v_indx,int n,int l,int count){

	if(count==0 && l==2*n)
		return 1;
	if(count<0 || count>n || l>=2*n)
		return 0;

	if(v.size()>v_indx){
		if(l+1==v[v_indx])
			return get_count(v,v_indx+1,n,l+1,count+1);

		else
			return get_count(v,v_indx,n,l+1,count+1)+get_count(v,v_indx,n,l+1,count-1);
	}
	else
		return get_count(v,v_indx,n,l+1,count+1) + get_count(v,v_indx,n,l+1,count-1);

}
int main(){
	gearchange();
	int t,n,k,x;
	cin>>t;
	while(t--){
		// memset(dp,-1,sizeof dp);
		cin>>n>>k;
		std::vector<int> v;
		while(k--){
			cin>>x;
			v.push_back(x);
		}
		cout<<get_count(v,0,n,0,0)<<endl;
	}
}
