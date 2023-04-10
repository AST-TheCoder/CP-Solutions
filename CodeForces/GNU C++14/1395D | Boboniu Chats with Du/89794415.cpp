#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll n,d,m,ans=0,idx=0;
 cin>>n>>d>>m;
 
 ll a[n+1];
 for(ll i=1;i<=n;i++){
  cin>>a[i];
  if(a[i]>m) idx++;
 }
 
 sort(a+1,a+n+1,greater<ll>());
 for(ll i=2;i<=n;i++) a[i]+=a[i-1];
 
 if(!idx){
  cout<<a[n]<<endl;
  return 0;
 }
 
 for(ll i=1;i<=idx;i++){
  ll days=n-(i-1)*(d+1)-1;
  if(days>=0){
   ll x=a[i]+a[min(idx+days,n)]-a[idx];
   ans=max(ans,x);
  }
 }
 
 cout<<ans<<endl;
 
 return 0;
}