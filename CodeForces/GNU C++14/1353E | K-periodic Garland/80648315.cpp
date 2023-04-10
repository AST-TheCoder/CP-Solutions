#include<bits/stdc++.h>
using namespace std; 
int main() 
{
 int t;
 cin>>t;
 while(t--){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  int count=0,m=0;
  for(int i=0;i<n;i++){
      if(s[i]=='1') count++;
  }
  for(int i=0;i<k;i++){
   int c=0;
   for(int j=i;j<n;j+=k) {
    if(s[j]=='1') c++;
    else{
     c--;
     if(c<0) c=0;
    }
    m=max(m,c);
   }
  }
  cout<<count-m<<endl;
 }
 return 0;
}