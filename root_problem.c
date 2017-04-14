#include <stdio.h>
#include <stdlib.h>
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ids[n],sum[n],i,res=0;
		for(i=0;i<n;i++){
			scanf("%d %d",&ids[i],&sum[i]);
		}
		for(i=0;i<n;i++){
			res+=ids[i]-sum[i];
		}
		printf("%d\n",res);	
	}
return 0;
}
