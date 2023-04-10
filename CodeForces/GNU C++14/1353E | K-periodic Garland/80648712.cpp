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
  int count=0;
  for(int i=0;i<n;i++){
      if(s[i]=='1') count++;
  }
  int ans=count;
  for(int i=0;i<k;i++){
   int x=0,y=0;
   for(int j=i;j<n;j+=k) {
    if(s[j]=='1') x++;
    else y++;
    if(y<=x) ans=min(ans,count-x+y);
    else x=y=0;
   }
  }
  cout<<ans<<endl;
 }
 return 0;
}