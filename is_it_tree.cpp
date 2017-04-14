#include <bits/stdc++.h>
using namespace std;
int visited[10002], cnt;


bool check_tree(std::vector<int>* v,int src,int p){

  visited[src]=true;
  for(int i=0;i<v[src].size();i++){
    int k = v[src][i];
    if(!visited[k]){
      cnt++;
      if(!check_tree(v,k,src))
        return 0;
    }
    else if(visited[k] && k!=p)
      return 0;
  }
  return 1;
}

int main(){
  int n,e,a,b,k=1;
  cin>>n>>e;
  cnt=1;
  memset(visited,0,sizeof visited);
  vector<int> v[n+1];
  for(int i=0;i<e;i++){
    cin>>a>>b;
    v[a].push_back(b);
    // v[b].push_back(a);
  }
  int i;
  for (i=1;i<=n;i++) {
    if(!visited[i]){
        k = check_tree(v,i,i);
        if(k==0)
          break;
    }
  }
  // cout<<i<<"  "<<k<<" "<<cnt<<endl;
  if(k==1 && e==n-1 && cnt==n)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
