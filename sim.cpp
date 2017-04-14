#include <bits/stdc++.h>
using namespace std;
#define gearchange() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)

int main(){
  std::string s;
  std::vector<std::string> res;
  int c_l=1,t_l=1,cps=0,j=0,c_r=0,c_c=0;
  stringstream ss;
  getline(cin,s);
  ss<<s;
  // int k = ;
  // cout<<(isalnum(s[0]));
  res.push_back("");
  for(int i=0;i<s.length();i++){
    if(s[i]=='@'){
      cps = !cps;
    }
    else if(s[i]=='#'){
      res.push_back("");
      c_r++;
      c_c=0;
    }
    else if(s[i]=='>'){
      if(c_c<res[c_r].length()-1)
        c_c++;
      else if(c_c==res[c_r].length()-1 && res.size()>(c_r+1)){
        c_c=0;
        c_r++;
      }
    }
    else if(s[i]=='<'){
      if(c_c>0)
        c_c--;
      else if(c_c==0&& res.size()>(c_r)){
        c_c=res[c_r-1].length();
        c_r--;
      }
    }
    else if(s[i]=='/'){
      if(c_c>0){
        c_c--;
        res[c_r][c_c]='\0';

      }
      else if(c_c==0&& res.size()>(c_r)){
        res[c_r][c_c]='\0';
        c_c=res[c_r-1].length();
        c_r--;
        res[c_r].insert(c_c,res[c_r+1]);
        res.erase(res.begin() + c_r+1);
      }
    }
    else if(s[i]=='?'){
      if(c_r<res.size()-1){
        c_r++;
        if(c_c>res[c_r].length()-1)
          c_c = res[c_r].length();
      }
    }
    else if(s[i]=='^'){
      if(c_r>0){
        c_r--;
        if(c_c>res[c_r].length()-1)
          c_c = res[c_r].length();
      }
    }
    else{
      if(cps==1)
        res[c_r].insert(c_c,1,toupper(s[i]));
      else
        res[c_r].insert(c_c,1,s[i]);
      c_c++;
      // cout<<"gaandu";
    }
  }
  // cout<<res.size();
  for(int i=0;i<res.size();i++)
    cout<<res[i]<<endl;
}
