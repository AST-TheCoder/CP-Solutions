#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 ll t;
 cin>>t;
 
 read:
 while(t--){
  ll n,m,ans=0;
  cin>>n>>m;
 
  pair<ll,ll> a[m];
  for(ll i=0;i<m;i++) cin>>a[i].first>>a[i].second;
 
  sort(a,a+m);
 
  ll val[m],sum[m];
  for(ll i=0;i<m;i++) val[i]=a[i].first;
 
  sum[m-1]=val[m-1];
  for(ll i=m-2;i>=0;i--){
   sum[i]=sum[i+1]+val[i];
  }
 
  for(ll i=0;i<m;i++){
   ll idx=lower_bound(val,val+m,a[i].second)-val,c,mx;
   if(idx<=i){
    if(m-idx>n) idx=m-n;
    mx=0;
    c=n;
   }
   if(idx>i){
    if(m-idx>n-1) idx=m-n+1;
    mx=a[i].first;
    c=n-1;
   }
 
   if(idx<m){
    mx+=sum[idx];
    c-=(m-idx);
   }
 
   mx+=c*a[i].second;
   ans=max(ans,mx);
  }
 
  cout<<ans<<endl;
 }
 
 return 0;
}