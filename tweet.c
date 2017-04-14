#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void closeall(int* arr,int n){
	for(int i=0;i<n;i++)
		arr[i]=0;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int tweet[n],open_tweets=0,index;
	closeall(tweet,n);
	while(k--){
		char* action;
		action = (char*)malloc(8);
		scanf("%s",action);
		if(strcmp(action,"CLOSEALL")==0){
			open_tweets = 0;
			closeall(tweet,n);
		}
		else{
			scanf("%d",&index);
			if(tweet[index-1]==0){
				tweet[index-1]=1;
				open_tweets++;
			}
			else{
				tweet[index-1]=0;
				open_tweets--;
			}
		}
	printf("%d\n",open_tweets);
	free(action);		
	}
	return 0;
}
