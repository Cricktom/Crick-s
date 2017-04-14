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
	long long int t,n,m,q;
	scanf("%lld",&t);
	while(t--){
		scanf(" %lld %lld",&n,&m);
		long long int arr1[n+1],arr2[n+1],i=1,temp,u,v,k;
		// int command;
		std::memset(arr1,0,sizeof arr1);
		std::memset(arr2,0,sizeof arr2);
		/*for(i=0;i<n+1;i++)
			printf("%lld  ",arr2[i]);
		printf("\n");*/
		long long int size = sizeof arr1/sizeof arr1[0];
		int command;
		while(m--){
			scanf(" %d",&command);
			if(command==0){
				scanf(" %lld %lld %lld",&u,&v,&k);
			//	cout<<u<<v<<k;
				update_tree(arr1,k,u,size);
				update_tree(arr1,-k,v+1,size);		
				update_tree(arr2,k*(u-1),u,size);
				update_tree(arr2,-k*(v),v+1,size);
			}
			// scanf("%lld",&q);
			else{
				scanf(" %lld %lld",&u,&v);
				printf("%lld\n",(get_sum(arr1,v)*(v)-get_sum(arr2,v))-((get_sum(arr1,u-1)*(u-1))-get_sum(arr2,u-1))); 					}
 
		}
	
	}
}
