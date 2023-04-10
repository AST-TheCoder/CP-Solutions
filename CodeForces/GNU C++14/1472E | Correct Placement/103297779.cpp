#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main()
{ 
 ll t;
 cin>>t;
 
 while(t--){
  ll n;
  cin>>n;
  vector<pair<ll,pair<ll,ll>>> val;
  for(ll i=1;i<=n;i++){
   ll x,y;
   cin>>x>>y;
   val.pb({x,{1,i}});
   val.pb({y,{2,i}});
  }
  pair<ll,ll> p[n+1],q[n+1];
  sort(all(val));
  for(ll i=0,ok=1;i<2*n;i++){
   if(i && val[i].first!=val[i-1].first) ok++;
   if(val[i].second.first==1){
    p[val[i].second.second].first=ok;
    q[val[i].second.second].second=ok;
   }
   else{
    p[val[i].second.second].second=ok;
    q[val[i].second.second].first=ok;
   }
  }
  pair<ll,ll> p_arr[2*n+1],q_arr[2*n+1];
  for(ll i=0;i<=2*n;i++){
   p_arr[i].first=INT_MAX;
   q_arr[i].first=INT_MAX;
  }
  for(ll i=1;i<=n;i++){
   if(p[i].second<p_arr[p[i].first].first){
    p_arr[p[i].first].first=p[i].second;
    p_arr[p[i].first].second=i;
   }
  }
  for(ll i=2;i<=2*n;i++){
   p_arr[i]=min(p_arr[i],p_arr[i-1]);
  }
  for(ll i=1;i<=n;i++){
   if(q[i].second<q_arr[q[i].first].first){
    q_arr[q[i].first].first=q[i].second;
    q_arr[q[i].first].second=i;
   }
  }
  for(ll i=2;i<=2*n;i++){
   q_arr[i]=min(q_arr[i],q_arr[i-1]);
  }
  for(ll i=1;i<=n;i++){
   if(p_arr[p[i].first-1].first<p[i].second) cout<<p_arr[p[i].first-1].second<<" ";
   else if(q_arr[p[i].first-1].first<p[i].second) cout<<q_arr[p[i].first-1].second<<" ";
   else cout<<-1<<" ";
  }cout<<endl;
 }
 
 return 0;
}