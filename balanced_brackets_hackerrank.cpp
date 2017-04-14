#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        std::string s;
        cin>>s;
        int n=s.length(),i=0,c1=0,c2=0,c3=0;
        char ch1=' ',ch2=' ',ch3=' ';
        if(n%2!=0){
            cout<<"NO"<<endl;
            continue;
        }
               
        for(i=0; i<(n);i++){
           // cout<<s[i]<<" "<<s[n-i-1]<<endl;
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                if(ch1==' ' || s[i]==ch1){
                    ch1=s[i];
                    c1++;
                }
                else if(ch2==' ' || s[i]==ch2){
                        ch2=s[i];
                        c2++;
                }
                else if(ch3==' ' || s[i]==ch3){
                        ch3=s[i];
                        c3++;
                }
            }
            else{
                if(s[i]==ch1+1 || s[i]==ch1+2){
                        c1--;
                    if(c1==0)
                            ch1=' ';
                }
                else if(s[i]==ch2+1 || s[i]==ch2+2){
                    c2--;
                    if(c2==0)
                            ch2=' ';
                }
                else if(s[i]==ch3+1 || s[i]==ch3+2){
                    c3--;
                    if(c3==0)
                            ch3=' ';
                }
                else{
                    cout<<"NO"<<endl;
                    break;
                }
            }
            if((c1==0 && (c2!=0 || c3!=0)) || (c2==0&&c3!=0)){
                cout<<"NO"<<endl;
                break;
            }
                   
         }
        if(i==n && c1==0 && c2==0 && c3==0)
                cout<<"YES"<<endl;
        else if(i==n && (c1!=0 || c2!=0 || c3!=0))
             cout<<"NO"<<endl;
    }
    return 0;
}

