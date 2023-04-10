#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main()
{
 ll t;
 cin>>t;
 
 while(t--){
  ll n,k,ans;
  cin>>n>>k;
  ll a[n+1],b[n+1];
 
  for(ll i=1;i<=n;i++){
   cin>>a[i];
   a[i]%=k;
   if(a[i]!=0) a[i]=k-a[i];
  }
 
  sort(a+1,a+n+1);
  ans=a[1];b[1]=a[1];
  for(ll i=2;i<=n;i++){
   if(!a[i]) continue;
   if(a[i]==a[i-1]) b[i]=b[i-1]+k;
   else b[i]=a[i];
   ans=max(b[i],ans);
  }
  
  if(ans) cout<<ans+1<<endl;
  else cout<<ans<<endl;
 }
    return 0;
}