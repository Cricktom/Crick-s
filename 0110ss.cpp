#include <bits/stdc++.h>
// #define MOD 1000000007
using namespace std;
long double power(float a, long long int b){
    long double ans=1ll;
    while(b) {
        if(b&1)ans=(ans*a);
        a=(a*a);
        b=b/2;
    }
    return ans;
}
long long int countStrings( long long int n)
{

	return round((power(1.61803391,n)-power(-0.61803390,n))/2.236067977);
}
int main()
{
    long long int n;
    scanf("%lld",&n);
    // int k = round((log(n*2.236067977)/log(1.61803391/-0.61803390)));
    // cout<<k<<endl;
    int c=1;
    int i=4;
    while(c<n){
      c=countStrings(i);
      i++;
    }
    printf("%lld %lld\n",countStrings(i-3), countStrings(i-2));
    return 0;
}
