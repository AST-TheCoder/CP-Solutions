#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
 
 ll n;
 cin>>n;
 
 ll a[n+1],c=1;
 vector<pair<ll,ll>> b,ans;
 for(ll i=1;i<=n;i++){
  cin>>a[i];
  b.pb(mp(a[i],i));
 }
 
 sort(all(b));
 for(ll i=0;i<n;i++){
  if(i && b[i].first!=b[i-1].first) c++;
  a[b[i].second]=c;
 }
 
 //for(ll i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl; //[3, 9, 3, 6, 9] = [1, 3, 1, 2, 3]
 
 vector<ll> idx[n+1];
 
 for(ll i=1;i<=n;i++){
  idx[a[i]].pb(i);
 }
 
 for(ll i=n;i>=1;i--){
  for(ll j=a[i]+1;j<=n;j++){
   for(ll k=0;k<idx[j].size();k++){
    if(idx[j][k]<i) ans.pb(mp(idx[j][k],i));
    else break;
   }
  }
 }
 
 cout<<ans.size()<<endl;
 for(ll i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
 
    return 0;
}