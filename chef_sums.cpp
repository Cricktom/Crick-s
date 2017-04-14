#include <bits/stdc++.h>
using namespace std;
#define FOR(init,term) for(int i=init;i<term;i++)
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)

int main(){
	int indx,min=1000000,t,n,var;
	cin>>t;
	while(t--){
		min = 1000000;
		indx=0;
		cin>>n;
		FOR(1,n+1){
			cin>>var;
			if(var<min){
				min =var;
				indx = i;
			}
		}
		cout<<indx<<endl;
	}

}
