#include <bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
int dp[8][8];
void get_cost(int c,int d,int x, int y){
	int r1,r2,r3,r4,r5,r6,r7,r8;
	if(x==c && y==d)
		return;
	if(x<0 || x>7 || y<0 || y>7)
		return;
	// cout<<"x="<<x<<"   y="<<y<<endl;
	if((x+2)>=0 && (x+2)<=7 && (y+1)>=0 && (y+1)<=7){
		r1=dp[x+2][y+1];
		dp[x+2][y+1] = min((((x*(x+2))+(y*(y+1)))+dp[x][y]),dp[x+2][y+1]);
		// cout<<"1  "<<dp[x+2][y+1]<<endl;
		if(r1!=dp[x+2][y+1])get_cost(c,d,x+2,y+1);

	}
	if((x+2)>=0 && (x+2)<=7 && (y-1)>=0 && (y-1)<=7){
		r2=dp[x+2][y-1];
		dp[x+2][y-1] = min((((x*(x+2))+(y*(y-1)))+dp[x][y]),dp[x+2][y-1]);
		// cout<<"2  "<<dp[x+2][y-1]<<endl;
		if(r2!=dp[x+2][y-1])get_cost(c,d,x+2,y-1);
	}
	if((x-2)>=0 && (x-2)<=7 && (y+1)>=0 && (y+1)<=7){
		r3=dp[x-2][y+1];
		dp[x-2][y+1] = min((((x*(x-2))+(y*(y+1)))+dp[x][y]),dp[x-2][y+1]);
		// cout<<"3  "<<dp[x+2][y-1]<<endl;
		if(r3!=dp[x-2][y+1])get_cost(c,d,x-2,y+1);
	}
	if((x-2)>=0 && (x-2)<=7 && (y-1)>=0 && (y-1)<=7){
		r4=dp[x-2][y-1];
		dp[x-2][y-1] = min((((x*(x-2))+(y*(y-1)))+dp[x][y]),dp[x-2][y-1]);
		if(r4!=dp[x-2][y-1])get_cost(c,d,x-2,y-1);
	}
	if((x+1)>=0 && (x+1)<=7 && (y+2)>=0 && (y+2)<=7){
		r5=dp[x+1][y+2];
		dp[x+1][y+2] = min((((x*(x+1))+(y*(y+2)))+dp[x][y]),dp[x+1][y+2]);
		if(r5!=dp[x+1][y+2])get_cost(c,d,x+1,y+2);
	}
	if((x+1)>=0 && (x+1)<=7 && (y-2)>=0 && (y-2)<=7){
		r6=dp[x+1][y-2];
		dp[x+1][y-2] = min((((x*(x+1))+(y*(y-2)))+dp[x][y]),dp[x+1][y-2]);
		// cout<<"x   "<<dp[x+1][y-2]<<endl;
		if(r6!=dp[x+1][y-2])get_cost(c,d,x+1,y-2);
	}
	if((x-1)>=0 && (x-1)<=7 && (y+2)>=0 && (y+2)<=7){
		r7=dp[x-1][y+2];
		dp[x-1][y+2] = min((((x*(x-1))+(y*(y+2)))+dp[x][y]),dp[x-1][y+2]);
		if(r7!=dp[x-1][y+2])get_cost(c,d,x-1,y+2);
	}
	if((x-1)>=0 && (x-1)<=7 && (y-2)>=0 && (y-2)<=7){
		r8=dp[x-1][y-2];
		dp[x-1][y-2] = min((((x*(x-1))+(y*(y-2)))+dp[x][y]),dp[x-1][y-2]);
		if(r8!=dp[x-1][y-2])get_cost(c,d,x-1,y-2);
	}
	return;
}

int main() {
	gearchange();
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)==4){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++)
				dp[i][j]=100000;
		}
		dp[a][b]=0;
		get_cost(c,d,a,b);
		cout<<dp[c][d]<<endl;
	}
	return 0;
}
