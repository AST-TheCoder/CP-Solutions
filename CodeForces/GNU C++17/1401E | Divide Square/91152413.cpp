#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{
 
 ll n,m,ans=1;
 cin>>n>>m;
 
 vector<pair<ll,pair<ll,ll>>> hl,hr,vd,vu;
 for(ll i=0;i<n;i++){
  ll x,p,q;
  cin>>x>>p>>q;
  if(!p) hl.pb(mp(x,mp(p,q)));
  else hr.pb(mp(x,mp(p,q)));
  if(!p && q==1000000) ans++;
 }
 
 for(ll i=0;i<m;i++){
  ll x,p,q;
  cin>>x>>p>>q;
  if(!p) vd.pb(mp(x,mp(p,q)));
  else vu.pb(mp(x,mp(p,q)));
  if(!p && q==1000000) ans++;
 }
 
 vector<pair<ll,ll>> v;
 for(ll i=0;i<vd.size();i++){
  v.pb(mp(vd[i].second.second,vd[i].first));
 }
 sort(all(v));
 
 vector<pair<ll,ll>>h;
 for(ll i=0;i<hl.size();i++){
  h.pb(mp(hl[i].first,hl[i].second.second));
 }
 sort(all(h));
 
 ordered_set<pair<ll,ll>> x;
 ll j=0;
 for(ll i=0;i<v.size();i++){
  for(;j<h.size();j++){
   if(h[j].first<=v[i].first) x.insert(mp(h[j].second,j+1));
   else break;
  }
  ll p=x.order_of_key(mp(v[i].second,0LL));
  ans+=(x.size()-p);
 }
 
 h.clear();x.clear();
 for(ll i=0;i<hr.size();i++){
  h.pb(mp(hr[i].first,hr[i].second.first));
 }
 sort(all(h));
 
 for(ll i=0,j=0;i<v.size();i++){
  for(;j<h.size();j++){
   if(h[j].first<=v[i].first) x.insert(mp(h[j].second,j+1));
   else break;
  }
  ll p=x.order_of_key(mp(v[i].second+1,0LL));
  ans+=p;
 }
 
 v.clear();h.clear();x.clear();
 
 for(ll i=0;i<vu.size();i++){
  v.pb(mp(vu[i].second.first,vu[i].first));
 }
 sort(all(v),greater<pair<ll,ll>>());
 
 for(ll i=0;i<hl.size();i++){
  h.pb(mp(hl[i].first,hl[i].second.second));
 }
 sort(all(h),greater<pair<ll,ll>>());
 
 for(ll i=0,j=0;i<v.size();i++){
  for(;j<h.size();j++){
   if(h[j].first>=v[i].first) x.insert(mp(h[j].second,j+1));
   else break;
  }
  ll p=x.order_of_key(mp(v[i].second,0LL));
  ans+=(x.size()-p);
 }
 
 h.clear();x.clear();
 for(ll i=0;i<hr.size();i++){
  h.pb(mp(hr[i].first,hr[i].second.first));
 }
 sort(all(h),greater<pair<ll,ll>>());
 
 for(ll i=0,j=0;i<v.size();i++){
  for(;j<h.size();j++){
   if(h[j].first>=v[i].first) x.insert(mp(h[j].second,j+1));
   else break;
  }
  ll p=x.order_of_key(mp(v[i].second+1,0LL));
  ans+=p;
 }
 
 cout<<ans<<endl;
 
 return 0;
}