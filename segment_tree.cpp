#include <iostream>
using namespace std;
void update(int* tree,int node,int start,int end,int indx,int val){
	if(start==end){
		tree[node]+=val;
	}	
	else{
		int mid = (start+end)/2;
		if(start<=indx && indx<=mid)
			update(tree,2*node+1,start,mid,indx,val);
		else
			 update(tree,2*node+2,mid+1,end,indx,val);
		tree[node]=tree[2*node+1]+tree[2*node+2];
	}
}
int get_sum(int*tree,int node,int start,int end,int l,int r){
	if(r<=start||l>=end)
		return 0;
	if(l<=start && r>=end){
		return tree[node];
	}
	int mid = (start+end)/2;
	return get_sum(tree,2*node+1,start,mid,l,r)+get_sum(tree,2*node+2,mid+1,end,l,r);
	 
}
int build_segment(int* arr,int node,int start,int end,int* tree){
	if(start==end){
		tree[node]=arr[start];
	}	
	else{
		int mid = (start+end)/2;
		build_segment(arr,2*node+1,start,mid,tree);
		build_segment(arr,2*node+2,mid+1,end,tree);
		tree[node]=tree[2*node+1]+tree[2*node+2];
	}
}

int main(){
	int arr[4] = {1,3,5,7};
	int tree[7];
	build_segment(arr,0,0,3,tree);
	update(tree,0,0,3,2,3);
	for(int i=0;i<7;i++)
		cout<<tree[i]<<endl;
	
	cout<<"\nsum==  ";
	cout<<get_sum(tree,0,0,3,2,3);
}
