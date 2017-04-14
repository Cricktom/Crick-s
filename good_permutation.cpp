#include <bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define FOR(init,term) for(int i=init;i<term;i++)

int main(){
	gearchange();
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		FOR(1,n+1){
			if(i%2!=0 && i!=n)
				cout<<i+1;
			else if(i%2!=0 && i==n)
                                cout<<i-2;
			else if(i%2==0 && i==n-1)
				cout<<i+1;
			
			else
				cout<<i-1;
			if(i!=n)
				cout<<" ";
		}
		cout<<endl;
	}
	
}
