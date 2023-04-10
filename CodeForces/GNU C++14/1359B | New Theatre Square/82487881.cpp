#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll t;
 cin>>t;
 
 while(t--){
  ll n,m,x,y,ans=0;
  cin>>n>>m>>x>>y;
  y=min(y,2*x);
  string s;
  for(ll i=0;i<n;i++){
   cin>>s;
   for(ll j=0;j<m;j++){
    if(s[j]=='.'){
     if(j+1<m && s[j+1]=='.') ans+=y,j++;
     else ans+=x;
    }
   }
  }
  cout<<ans<<endl;
 }
 
 return 0;
}