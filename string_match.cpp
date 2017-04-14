#include <bits/stdc++.h>
using namespace std;
char str[100000];
struct count{
	int count;
	vector<int> indx;
}arr[10];

int main(){
	int i=0,size;
	long long substr_count=0;
	
	while(1){
		char temp;
		scanf("%c",&temp);
		if(temp=='\n')
			break;
		str[i]=temp;
		arr[temp-48].count=0;
		arr[temp-48].indx.push_back(i);
		i++;
	}
	cin>>size;
	int s[size];
	int min=1000000,max=-1,k=-1,c,m,j;
	char prev_c;
	for(i=0;i<size;i++){
		cin>>s[i];
		// arr[s[i]].count=1;
		m=c=arr[s[i]].indx[0];
		min = c<min?c:min;
		max = m>max?m:max;
				
	}
	int len = strlen(str)-1;
	// cout<<len<<endl;
	c=-1;
	while(max<=len){
		i=min-(k+1);
		j= len-(max);
		k=min;
		substr_count+=(i+j+(i*j))+1;
		prev_c = str[min];
		arr[prev_c-48].count+=1;
		i = arr[prev_c-48].indx[arr[prev_c-48].count];
		max = i>max?i:max;
		min = 1000000;
		for(j=0;j<size;j++){
			if(arr[s[j]].indx.size()<=arr[s[j]].count){
				c=1;
				break;
				
			}
			i=arr[s[j]].indx[arr[s[j]].count];
			if(i<min)
				min=i;
		}
		if(c==1)
			break;
		// cout<<min<<"    "<<max<<endl;
	
	}
	cout<<substr_count<<endl;	
}
