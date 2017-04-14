#include <stdio.h>
#include <string.h>
// using namespace std;
// #define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define FOR(a,b) for(int i =a;i<b;i++)

int main(){
        // gearchange();
        int t,arr[10];
        char var;
        scanf("%d\n",&t);
        while(t--){
                memset(arr,0,sizeof arr);
                while(1){
                        scanf("%c",&var);
                        if(var=='\n')break;
                        arr[var-48]++;

                //      cout<<var;

                }
                FOR(6,10){
                        if(arr[i]>0){
                                for(int j=0;j<10;j++){
                                        if(((arr[j]>0)&&((i*10)+j>=65)&&((i*10)+j<=90))){
                                                if(i!=j)printf("%c",(i*10)+j);
                                                else if((i==j)&&(arr[j]>1))
                                                        printf("%c",(i*10)+j);

                                        }

                                }
                        }
                }
                printf("\n");

        }
}
