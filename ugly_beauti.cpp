#include <bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)

int main() {
    gearchange();
    int q,n;
    cin>>q;
    while(q--){
      int res =0,temp;
      cin>>n;
      long long int arr[n+1],arr2[n+1]={0};
      // memset(arr,0,sizeof arr);
      for(int i=1; i<=n;i++)
        cin>>arr[i];
      for(int i =1;i<=n;i++){
        if(arr[i]>n){
          res=0;
          break;
        }
        arr2[arr[i]]+=1;
        if(i!=arr[i]){
            res=1;
        }
        if(arr2[arr[i]]>1){
              res=0;
              break;
        }
      }
      if(res==0)
        cout<<"Ugly"<<endl;
      else
        cout<<"Beautiful"<<endl;

    }
}
