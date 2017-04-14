#include <bits/stdc++.h>
using namespace std;
long long int get_max(long long int*arr,int i,int n){
	if(i>=n)
		return 0;
	return max((arr[i]^get_max(arr,i+1,n)),(0^get_max(arr,i+1,n)));
}

int main(){
	int n;
	cin>>n;
	long long int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
		//cout<<arr[i]<<endl;
	}
	sort(arr,arr+n);
	//cout<<get_max(arr,0,n)<<endl;
	long long int ans=0;
	for(int i=n-1;i>=0;i--){
		if((ans^arr[i])>ans)
			ans^=arr[i];
	}
	cout<<ans<<endl;
	return 0;
}
