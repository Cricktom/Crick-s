#include <bits/stdc++.h>
using namespace std;
#define sync_with_c() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
int mat[251][251],ans[62502];
bool visited[251][251];

int  get_number(int n,int m,int x,int y){
  if(x<0 || x>=n || y<0 || y>=m)
    return 0;
  if(mat[x][y]==0)
    return 0;
  if(visited[x][y])
    return 0;
  visited[x][y]=true;
  return 1+get_number(n,m,x-1,y)+get_number(n,m,x+1,y)+get_number(n,m,x,y-1)+get_number(n,m,x,y+1);
}

int main(){
  int n,m;
  while(1){
    cin>>n>>m;
    if(n==0 && m==0)
      break;
    int cnt=0, mx=0;
    memset(visited,false,sizeof visited);
    memset(ans,0,sizeof ans);

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>mat[i][j];
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        int l = get_number(n,m,i,j);
        if(l!=0){
          ans[l]++;
          cnt++;
        }
        if(l>mx)
          mx=l;
      }

    cout<<cnt<<endl;
    for(int i=1;i<=mx;i++){
      if(ans[i]>0)
        cout<<i<<" "<<ans[i]<<endl;
    }
  }
}
