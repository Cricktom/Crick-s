#include <iostream>
using namespace std;

int main(){
	int t,n,d;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>d;
		long int arr[n+1];
		int sum=0,avg=0,temp,attempt=0;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum%n!=0){
			cout<<-1<<endl;
			//cout<<"hey there"<<endl;
			continue;
		}
		avg=sum/n;
		for(int i=1;i<=n-d;i++){
			if(arr[i]<avg){
				temp = avg-arr[i];
				arr[i+d]-=temp;
				arr[i]+=temp;
				attempt+=temp;
				//std::cout<<"arr[i]= "<<arr[i]+temp<< "arr[i+d]= "<<arr[i+d];
			}
			else{
				temp=arr[i]-avg;
				arr[i+d]+=temp;
				arr[i]-=temp;
				attempt+=temp;
				//std::cout<<"arr[i]= "<<arr[i-temp]<<"arr[i+d]= "<<arr[i]-temp,arr[i+d];
				
			}
			
			
			
		}
		for(int i=1;i<=n;i++){
			if(arr[i]!=avg){
				attempt=-1;
				break;
			}
		}
		cout<<attempt<<endl;
		
}
	return 0;
}
