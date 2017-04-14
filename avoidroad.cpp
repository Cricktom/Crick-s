#include <bits/stdc++.h>
using namespace std;
int l[7][7]={0};
int get(int w, int h,vector<std::string> v){

	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			if(i==0j||j==0)
				l[i][j]=1;
			else
				l[i][j]=l[i-1][j]+l[i][j-1];	
		}
	}
	return l[w-1][h-1];
}

int main(){
	int w,h;
	cin>>w>>h;
	vector<std::string> blocks;
	//std::string str;
	blocks.push_back("0 0 0 1");
	blocks.push_back("6 6 5 6");
	
//	l[0][1]=l[1][0]=1;
	//int dp[w][h];
	//memset(dp,0,sizeof dp);
	
	int num = get(w,h,blocks);
	cout<<num<<endl;
	return 0;	
}
