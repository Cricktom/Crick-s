#include <bits/stdc++.h>
using namespace std;
#define sync_with_c() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
bool visited[1002];
void bfs(std::vector<int>* v,int o){
  queue<int>q;
  q.push(o);
  visited[o]=true;
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    cout<<p<<" ";
    for(int i=0;i<v[p].size();i++){
      int l = v[p][i];
      if(!visited[l]){
        q.push(l);
        visited[l]=true;
      }
    }
  }

}

void dfs(std::vector<int>* v,int o){
  cout<<o<<" ";
  visited[o]=true;
  for(int i=0;i<v[o].size();i++){
    int l = v[o][i];
    if(!visited[l]){
      visited[l]=true;
      dfs(v,l);

    }
  }
}

int main(){
  int t,n,v,m,u,c=1;
  cin>>t;
  while(t--){
    cin>>n;
    std::vector<int> vec[n+1];
    for(int i=1;i<=n;i++){
      cin>>v>>m;
      for(int i=0;i<m;i++){
        cin>>u;
        vec[v].push_back(u);
      }
    }
    cout<<"graph "<<c<<endl;
    int o,k;
    while (1) {
      memset(visited,false, sizeof visited);
      cin>>o>>k;
      if(o==0 && k==0)
        break;
      if(k==0)
        dfs(vec,o);
      else
        bfs(vec,o);
      cout<<endl;
    }
    c++;
  }
}
