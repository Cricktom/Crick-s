#include <bits/stdc++.h>
using namespace std;
int N;
std::string s = "(())";
int res=0;
int count(int a,int b,int c){
	if(c>=N){
		if(b==0&&a==0)
			return 1;
		else
			return 0;
	}
	if(a<0 || b<0)
		return 0;
	if(a==0 && b==0)
		return 1;
	if(s[c]=='('){
		res+=count(a+1,b-1,c+1)+count(a,b,c+1);	
		return res;
	}
	if(s[c]==')'){
		res+=count(a-1,b+1,c+1)+count(a,b,c+1);
		return res;
	}
	return 0;
	
}

int main(){
//	s="(())";
	N=s.length();
	printf("%d\n",count(0,0,0));
	return 0;
}
