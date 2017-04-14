#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main(){
	int str1[26],str2[26],t,i;
	cin>>t;
	while(t--){
		memset(str1,0,sizeof str1);
		memset(str2,0,sizeof str2);
		char s[500];
		scanf("%s",s);
		for(i=0;i<strlen(s);i++)
			str1[s[i]-97]+=1;
	//	printf("%s\n",s);
		scanf("%s",s);
	//	printf("%s\n",s);
		for(i=0;i<strlen(s);i++)
                        str2[s[i]-97]+=1;
	/*	for(i=0;i<26;i++)
			printf("%d ",str1[i]);
		printf("\n");
		for(i=0;i<26;i++)
			printf("%d ",str2[i]);
		printf("\n");
	*/	int x=0;
		for(i=0;i<26;i++){
			if(str1[i]>=2&&str2[i]==0){
				x=1;			
				break;
			}
		}
		if(x==0){
			for(i=0;i<26;i++){
					if(str2[i]==0&&str1[i]>=1){
						x=2;
						break;
					}
			}
			if(x==2){
				for(i=0;i<26;i++){
					if(str2[i]>=1&&str1[i]==0){
						x=0;
						break;
					}
				}
				x=(i==26)?1:0;
			}
		
		}
		if(x==1)
			printf("A\n");
		else
			printf("B\n");
	}
	
}
