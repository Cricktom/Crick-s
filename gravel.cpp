#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
void update_tree(long long int* arr,long long int val,long long int indx,long long int size){
	while(indx<size){
		arr[indx]+=val;
		indx+=indx & (-indx);
	}
}

long long int get_sum(long long int* arr,long long int indx){
	long long int sum=0;
	while(indx){
		sum+=arr[indx];
		indx-=indx&(-indx);	
	}
	return sum;
}

int main(){
	long long int n,m,c;
	scanf("%lld %lld %lld",&n,&m,&c);
	long long int arr[n+1],i=1,temp,u,v,k;
	char command;
	std::memset(arr,0,sizeof arr);
	long long int size = sizeof arr/sizeof arr[0];
	while(m--){
		scanf(" %c",&command);
		if(command=='S'){
			scanf(" %lld %lld %lld",&u,&v,&k);
		//	cout<<u<<v<<k;
			update_tree(arr,k,u,size);
			update_tree(arr,-k,v+1,size);		
		}
		else{
			scanf(" %lld",&u);
			printf("%lld\n",(get_sum(arr,u)+c));
		
		}
		
	}
}
