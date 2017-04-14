#include <bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)

bool cmp(int a,int b){
  return a>b;
}

int main() {
    gearchange();
    long long int n,temp;
    cin>>n;
    long long int suma[n+1]={0},sumb[n+1]={0},res[n+1]={0};
    for(int i=1;i<=n;i++){
      cin>>temp;
      suma[i]+=suma[i-1]+temp;
    }
    for(int i=1;i<=n;i++){
      cin>>temp;
      sumb[i]+=sumb[i-1]+temp;
    }
    long long int max=0;
    int indxa,indxb;
    for(int i=1;i<=n;i++){
      if((suma[i]+(sumb[n]-sumb[i]))>max){
          max = (suma[i]+(sumb[n]-sumb[i]));
          indxa = i;
          indxb = i+1;
      }
    }
    if(max<sumb[n]){
        indxa=0;
        indxb=1;
    }
    for(int i = 1;i<=indxa;i++)
      res[i]=suma[i]-suma[i-1];
    for(int i = indxb;i<=n;i++)
        res[i]=sumb[i]-sumb[i-1];
    // for(int i=0;i<=n;i++)
    //     cout<<res[i]<<" ";
    //     cout<<endl;
    sort(res,res+(n+1),cmp);
    for(int i=0;i<n;i++){
      cout<<res[i];
      if(i!=n)
            cout<<" ";
    }
    cout<<endl;
}
