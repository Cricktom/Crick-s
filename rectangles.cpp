#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i=2,j=2,count=n;
	while(i<n/2){
		j=i;
		while(i*j<=n){
			count++;
			j++;
		}
		i++;
	}
	cout<<count<<endl;
}

