#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 int t;
 cin>>t;
 
 while(t--){
  string s;
  cin>>s;
 
  ll n=s.size();
  ll x[n+1],y[n+1],ans=INT_MAX;
  memset(x,0,sizeof(x));
  memset(y,0,sizeof(y));
 
  for(ll i=0;i<n;i++){
   if(i==0) x[i]=(ll)s[i]-'0';
   else{
    x[i]=x[i-1];
    x[i]+=((ll)s[i]-'0');
   }
  }
 
  for(ll i=n-1;i>=0;i--){
   y[i]=y[i+1];
   y[i]+=((ll)s[i]-'0');
  }
 
  for(ll i=0;i<n;i++){
   ans=min(ans,i+1-x[i]+y[i+1]);
   ans=min(ans,x[i]+(n-i-1)-y[i+1]);
  }
  cout<<ans<<endl;
 }
 
 return 0;
}