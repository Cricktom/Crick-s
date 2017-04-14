#include <bits/stdc++.h>
using namespace std;
#define sync_with_c() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
// bool visited[102];


int main(){
  sync_with_c();
  int n,m;
  cin>>n;
  int skill_b[n];
  for(int i=0;i<n;i++){
    cin>>skill_b[i];
  }
  cin>>m;
  int skill_g[m];
  for(int i=0;i<m;i++){
    cin>>skill_g[i];
  }
  sort(skill_g,skill_g+m);
  sort(skill_b,skill_b+(n));
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(abs(skill_b[i]-skill_g[j])<=1){
        // cout<<skill_b[i]<<"  "<<skill_g[j]<<endl;
          skill_g[j]=1000;
          ans++;
          break;
      }
    }
  }
  cout<<ans<<endl;

}
