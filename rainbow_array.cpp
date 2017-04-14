#include <iostream>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n],x=0,i=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			
		}
		if(arr[0]!=1){
			cout<<"no"<<endl;
			continue;
		}
		while(1){
			if(arr[i]==7)
				break;
			if((arr[i]!=arr[n-(i+1)]) || ((arr[i+1]-arr[i])>1)){
				x=1;
				break;
			}
			i++;
		}
		if(x==0){
			for(int j=i;j<=(n-(i+1));j++){
				if(arr[j]!=7){
					x=1;
					break;	
				}
			}
		}
		
		if(x==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}	
}
