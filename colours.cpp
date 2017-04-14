#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int clr[4]={0};
	char tbl1[2*n],tbl2[2*n];
	for(int i=0;i<2*n;i++){
		cin>>tbl1[i];
		clr[tbl1[i]-65]++;	
//		cout<<clr[tbl1[i]-65]<<endl;
		
	}
	for(int i=0;i<2*n;i+=2){
		int clr[4]={0,0,0,0},clr1=-1,clr2=-1;

		clr[tbl1[i]-65]=1;
		clr[tbl1[i+1]-65]=1;
		for(int j=0;j<4;j++){
			if(clr[j]==0){
				if(clr1==-1)
					clr1=j;
				else
					clr2=j;
			}
		}
		if(tbl2[i-1]!=65+clr1){
			tbl2[i]=65+clr1;
			tbl2[i+1]=65+clr2;
		}
		else{
			tbl2[i]=65+clr2;
			tbl2[i+1]=65+clr1;
		}
	}
	for(int i=0;i<2*n;i++)
		cout<<tbl2[i];
	cout<<endl;
}

