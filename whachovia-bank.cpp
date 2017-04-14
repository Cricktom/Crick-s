#include <bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
int get_profit(std::vector<int> val, std::vector<int> wt, int k){
   
	int i, w;
   	int n=val.size();
   	int K[n+1][k+1];
 
   
	for (i = 0; i <= n; i++)
	   {
	       for (w = 0; w <= k; w++)
	       {
	           if (i==0 || w==0)
	               K[i][w] = 0;
	           else if(wt[i-1] <= w)
       	          	K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
       	   	   else
       	        	K[i][w] = K[i-1][w];
       		}
   	}	
 
   return K[n][k];
}

int main(){
	gearchange();
	int t,k,m,c,wt;
	cin>>t;
	while(t--){
		cin>>k>>m;
		std::vector<int> v,w;
		while(m--){
			cin>>wt>>c;
			v.push_back(c);
			w.push_back(wt);
		}
		cout<<"Hey stupid robber, you can get "<<get_profit(v,w,k)<<endl;
	}
}
