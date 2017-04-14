#include <bits/stdc++.h>
using namespace std;
#define sync_with_c() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
struct node{
  int d;
  int p;

  node(){}
    node(int k, int b){
      d=k;
      p=b;
    }
  bool operator<(const node &k)const{
    if(k.p!=p) return p>k.p;
    if(k.d!=d) return d>k.d;
    return false;
  }
};
bool visited[101];
double get_minP(std::vector<node>*v,int o,int tr){
  priority_queue<node>q;
  node temp;
  int pos;
  int  pr=1;
  int ans =1;
  q.push(node(o,0));
  while(!q.empty()){
    temp = q.top();
    q.pop();
    if(visited[temp.d])continue;
    visited[temp.d]=true;
    if(temp.d==tr){
        ans=temp.p;
        return ans;
    }
    for(int i=0;i<v[temp.d].size();i++){
      pos=v[temp.d][i].d;
      pr = ((temp.p))+((v[temp.d][i].p));
      q.push(node(pos,pr));
    }

  }
  return -1;


}

int main(){
  sync_with_c();
  int n,r,s,dst,pr,t,o,tr;
  cin>>t;
  while(t--){
      cin>>n>>r>>o>>tr;
      std::vector<node>  vec[n+1];
      memset(visited,false,sizeof visited);
      for(int i=0;i<r;i++){
        cin>>s>>dst>>pr;
        node temp;
        temp.d=dst;
        temp.p=pr;
        vec[s].push_back(temp);
        temp.d = s;
        vec[dst].push_back(temp);
      }
      int res = get_minP(vec,o,tr);
      // std::cout << std::fixed;
      // std::cout << std::setprecision(6);
      if(res!=-1)
        std::cout<<res<<endl;
      else
        cout<<"NONE"<<endl;
  }
}
