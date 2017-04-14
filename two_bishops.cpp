#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int i,j,line[2],indx[2],k=0;
		char x[9];
		for(i=1;i<=8;i++){
			for(j=1;j<=8;j++){
				cin>>x[j];
				if(x[j]=='B'){
					line[k] = i;
					indx[k]=j;
					k++;
				}
			}
		}
		//cout<<line[0]<<endl<<line[1]<<endl;		
		//cout<<indx[0]<<endl<<indx[1]<<endl;
		if(((indx[0]+(line[1]-line[0]))==indx[1])||((indx[0]-(line[1]-line[0]))==indx[1]))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
