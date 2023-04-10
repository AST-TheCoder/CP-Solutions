#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll n,m;
 cin>>n>>m;
 ll x,c,y,ans=0;
 cin>>x>>c>>y;
 vector<ll> a,b;
 
 a.pb(0LL);
 for(ll i=1;i<=n;i++){
  ll p;
  cin>>p;
  a.pb(p);
 }a.pb(0LL);
 
 b.pb(0LL);
 for(ll i=1;i<=m;i++){
  ll p;
  cin>>p;
  b.pb(p);
 }b.pb(0LL);
 
 vector<ll> val;
 
 for(ll i=1,j=1;i<a.size();i++){
  if(a[i]!=b[j]) val.pb(a[i]);
  else{
   if(!val.size()){
    j++;
    continue;
   }
   sort(all(val));
   ll mx=max(b[j-1],b[j]),k=0,v_sz=val.size();
 
   if(val[v_sz-1]>mx && v_sz<c){
    cout<<-1<<endl;
    return 0;
   }
 
   if(c*y<x){
    if(val[v_sz-1]<mx) ans+=(v_sz*y);
    else ans+=(v_sz-c)*y+x;
   }
   else{
    ll mod=v_sz%c;
    ans+=mod*y+(v_sz/c)*x;
   }
   j++;
   val.clear();
  }
  if(i+1==a.size() && j!=b.size()){
   cout<<-1<<endl;
   return 0;
  }
 }
 
 cout<<ans<<endl;
 
    return 0;
}