#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define MAX 30001
int tree[30009];
struct tree_node{
	int num,pos;
};
struct query_node{
	int i,j,k,pos;
};
bool cmp(tree_node &a , tree_node &b){
  	return a.num > b.num;
}


bool compare(query_node &a, query_node &b){
	return a.k>b.k;
}

void update_tree(int indx){
	while(indx<MAX){
		tree[indx]+=1;
		indx+=indx & (-indx);
	}
}

int get_sum(int indx){
	int sum=0;
	while(indx){
		sum+=tree[indx];
		indx-=indx&(-indx);	
	}
	return sum;
}


int main(){
	int n;
	cin>>n;
	tree_node arr[n];
	memset(tree,0,sizeof tree);
	for(int i=0;i<n;i++){
		cin>>arr[i].num;
		arr[i].pos=i+1;	
	}
	sort(arr,arr+n,cmp);
	int q;
	cin>>q;
	query_node quer[q];
	for(int l=0;l<q;l++){
		scanf("%d%d%d",&quer[l].i,&quer[l].j,&quer[l].k);
		quer[l].pos=l;
	}	
	sort(quer,quer+q,compare);
	int track=0,result[q];
	for(int l=0;l<q;l++){
		while(track<n && arr[track].num>quer[l].k){
			update_tree(arr[track].pos);
			track++;
		}
	result[quer[l].pos]=get_sum(quer[l].j)-get_sum(quer[l].i-1);
	}

	for(int i=0;i<q;i++)
		printf("%d\n",result[i]);
	return 0;
}



