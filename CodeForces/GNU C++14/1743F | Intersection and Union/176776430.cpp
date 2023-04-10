#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
ll mod=998244353,p[300007];
ordered_set<ll> q;
vector<ll> c[300007],k[300007];
 
ll bigmod(ll n,ll p){
 if(p==0) return 1;
 if(p%2) return (n*bigmod(n,p-1))%mod;
 ll x=bigmod(n,p/2);
 return (x*x)%mod;
}
 
int main()
{   
 
 ll n;
 cin>>n;
 
 for(ll i=1;i<=n;i++){
  ll l,r;
  cin>>l>>r;
  k[l].pb(i);
  c[r].pb(i);
 }
 
 for(ll i=0;i<=300000;i++){
  for(ll j=0;j<k[i].size();j++) q.insert(k[i][j]);
  if(q.size()==0) continue;
  p[i]=*q.find_by_order(q.size()-1);
  for(ll j=0;j<c[i].size();j++){
   ll v=c[i][j];
   q.erase(q.find_by_order(q.order_of_key(v)));
  }
 }
 
 ll ans=0;
 for(ll i=0;i<=300000;i++){
  //if(i<=10) cout<<i<<" "<<p[i]<<endl;
  if(!p[i]) continue;
  ll x=n-p[i]+1;
  if(p[i]==1) x--;
  ll y=n-x-1;
  ll temp=bigmod(2,x);
  temp=(temp*bigmod(3,y))%mod;
  ans=(ans+temp)%mod;
 }
 cout<<ans<<endl;
 
 return 0;
}