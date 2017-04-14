#include <bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
struct node {
	int o,c;
}tree[3*30007];

void update_tree(int indx, int st, int end,int idx){
	if(st==end){
			tree[indx].o=	tree[indx].c = -tree[indx].c;
			return;
	}
	int mid = (st+end)/2;
	if(idx<=mid)
		update_tree(2*indx+1,st,mid,idx);
	else
		update_tree(2*indx+2,mid+1,end,idx);
	// int ch = min(tree[2*indx+1].o,tree[2*indx+2].c);
	tree[indx].o = tree[2*indx+1].o + tree[2*indx+2].o;
	tree[indx].c = min(tree[2*indx+1].c ,tree[2*indx+1].o+tree[2*indx+2].c);
}


void build(int indx, int st, int end, string arr){
	if(st == end){
		if(arr[st]==')'){
			tree[indx].c=tree[indx].o = -1;
		}
		else{
			tree[indx].o=tree[indx].c = 1;
		}
		return;
	}
	int mid = (st+end)/2;
	build((2*indx)+1,st,mid,arr);
	build((2*indx)+2,mid+1,end,arr);
	tree[indx].o = tree[2*indx+1].o + tree[2*indx+2].o;
	tree[indx].c = min(tree[2*indx+1].c ,tree[2*indx+1].o+tree[2*indx+2].c);
}
int main(){
  gearchange();
  int t=10,k=1,n;
  char c;
	std::string s;
  while(t--){
    cin>>n;
		cin>>s;
    build(0,0,n-1,s);
    int m,num,res;
		cout<<"Test "<<k<<":"<<endl;
		cin>>m;
		while(m--){
      cin>>num;
      if(num){
				update_tree(0,0,n-1,num-1);
      }
      else{
				if(!tree[0].o && !tree[0].c)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
      }
    }
		k++;
  }
}
