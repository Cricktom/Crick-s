#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a , int b){
  return a > b;
}
int main(){
	int arr[6]={5,3,1,6,0,9};
	sort(arr,arr+6,cmp);
	for(int i=0;i<6;i++)
		cout<<arr[i]<<endl;
	return 0;
}
