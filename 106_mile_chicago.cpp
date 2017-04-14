#include <bits/stdc++.h>
using namespace std;
#define sync_with_c() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
struct node{
  int d;
  double p;

  node(){}
    node(int k, double b){
      d=k;
      p=b;
    }
  bool operator<(const node &k)const{
    if(k.p!=p) return p<k.p;
    if(k.d!=d) return d<k.d;
    return false;
  }
};
bool visited[101];
double get_maxP(std::vector<node>*v,int n){
  priority_queue<node>q;
  node temp;
  int pos;
  double pr=1;
  double ans =1;
  q.push(node(1,1));
  while(!q.empty()){
    temp = q.top();
    q.pop();
    if(visited[temp.d])continue;
    visited[temp.d]=true;
    if(temp.d==n){
        ans=temp.p;
        return ans*100;
    }
    for(int i=0;i<v[temp.d].size();i++){
      pos=v[temp.d][i].d;
      pr = ((temp.p))*((v[temp.d][i].p)/100);
      q.push(node(pos,pr));
    }

  }


}

int main(){
  sync_with_c();
  int n,r,s,dst,pr;
  while(1){
      cin>>n;
      if(n==0)
        break;
      cin>>r;
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
      double res = get_maxP(vec,n);
      std::cout << std::fixed;
      std::cout << std::setprecision(6);
      std::cout <<res<<endl;
  }
}
