#include <bits/stdc++.h>
using namespace std;
std::map<int,long long int>coins;
long long int get_coins(long long int  n){
	if(n==0)
		return 0;
	if(coins[n]!=0)
		return coins[n];
	for(int i=4;i<=n;i++){
		coins[n] = max(n,(get_coins(n/2)+get_coins(n/3)+get_coins(n/4)));
	}
	return coins[n];
}

int main(){
	long long int  n;
	coins[0]=0;coins[1]=1;coins[2]=2;coins[3]=3;	
	while(scanf("%lld",&n)==1)
		printf("%lld\n",get_coins(n));
	return 0;
}
