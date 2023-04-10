#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll n,ans=0;
 cin>>n;
 ll a[n+1];
 for(ll i=1;i<=n;i++) cin>>a[i];
 
 for(ll k=1;k<=30;k++){
  ll sum=0,m=0;
  for(ll i=1;i<=n;i++){
   if(a[i]>k) m=0;
   else{
    m+=a[i];
    if(m<0) m=0;
   }
   sum=max(sum,m);
  }
  ans=max(sum-k,ans);
 }
 cout<<ans<<endl;
 
 return 0;
}