#include <iostream>
#include <cstring>
using namespace std;
void update_tree(int* arr,int val,int indx,int size){
	while(indx<size){
		arr[indx]+=val;
		indx+=indx & (-indx);
	}
}

int get_sum(int* arr,int indx){
	int sum=0;
	while(indx){
		sum+=arr[indx];
		indx-=indx&(-indx);	
	}
	return sum;
}
void print(int* arr,int size){
	for(int i=1;i<size;i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
}	
int main(){
	int n;
	cin>>n;
	int arr[n+1],i=1,temp;
	std::memset(arr,0,sizeof arr);
	int size = sizeof arr/sizeof arr[0];
	while(i<size){
		cin>>temp;
		update_tree(arr,temp,i,size);
		print(arr,size);
		i++;
	}
	//for(i=1;i<size;i++)
//	cout<<"enter index for prefix summation";
//	cin>>temp;
	update_tree(arr,3,1,size);
	print(arr,size);
	update_tree(arr,-3,4,size);
	print(arr,size);
	cout<<get_sum(arr,4)<<endl;
}
