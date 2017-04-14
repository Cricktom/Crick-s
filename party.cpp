#include <bits/stdc++.h>
using namespace std;
#define sync_with_c() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
bool visited[2002];

int dfs(std::vector<int>* v,int o){
  visited[o]=true;
  if(v[o].size()>0){
    if(!visited[v[o][0]])
      return 1+dfs(v,v[o][0]);
  }
  return 0;
}
int main(int argc, char const *argv[]) {
    sync_with_c();
    int n,temp;
    cin>>n;

    std::vector<int> v[n+1];
    for(int i=1;i<=n;i++){
      cin>>temp;
      if(temp!=-1)
        v[i].push_back(temp);
    }
    int mx=0;
    for(int i=1;i<=n;i++){
      memset(visited,false,sizeof visited);
      int l = dfs(v,i);
      // cout<<l<<endl;
      if(l+1>mx)
        mx=l+1;
    }
    cout<<mx<<endl;
  return 0;
}
