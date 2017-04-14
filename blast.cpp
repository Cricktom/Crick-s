#include <bits/stdc++.h>
using namespace std;
int dp[10000][10000]={-1};
// int get_blast(string s1,string s2,int x,int i,int j){
// //	cout<<i<<" "<<j<<endl;
// 	if((i>=s1.length() && j<s2.length()) || (i<s1.length() && j>=s2.length())){
// //		cout<<"Returning:: "<<x<<endl;
// 		return x*(s2.length()-j+1);
//
// 	}
// 	if((i<s1.length() && j>=s2.length())){
// 		return x*(s1.length()-i+1);
// 	}
//
// 	if(i>=s1.length() && j>=s2.length()){
// 		//cout<<"Returning:: 0"<<endl;
// 		return 0;
// 	}
// 	//int r1=0,r2=0,r3=0;
// 	// cout<<s1[i]<<"    "<<s2[j]<<endl;
// 	return std::min({x+get_blast(s1,s2,x,i+1,j),x+get_blast(s1,s2,x,i,j+1),abs(s1[i]-s2[j])+get_blast(s1,s2,x,i+1,j+1)});
// 	//r2 =x+ get_blast(s1,s2,x,i,j+1);
// 	//r3 =abs(s1[i]-s2[j])+get_blast(s1,s2,x,i+1,j+1);
// 	//cout<<r1<<"   "<<r2<<"   "<<r3<<endl;
// 	//cout<<"Returning:"<<std::min({r1, r2, r3})<<endl;
// 	//return std::min({r1, r2, r3});
// }

int main(){
	int x;
	std::string s1,s2;
	cin>>s1>>s2>>x;
	int l1 = s1.length();
	int l2 = s2.length();
	dp[0][0]=0;
	for(int i=1;i<=l2;i++)dp[0][i]=i*x;
	for(int i=1;i<=l1;i++)dp[i][0]=i*x;
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
				dp[i][j] = std::min({x+dp[i-1][j],x+dp[i][j-1],abs(s1[i-1]-s2[j-1])+dp[i-1][j-1]});
		}

	}
	cout<<dp[l1][l2]<<endl;

}
