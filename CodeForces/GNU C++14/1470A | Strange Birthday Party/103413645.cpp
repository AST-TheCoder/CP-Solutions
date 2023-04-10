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
  ll n,m;
  cin>>n>>m;
  ll x[m+1];
  memset(x,0,sizeof(x));
  for(ll i=1;i<=n;i++){
   ll p;
   cin>>p;
   x[p]++;
  }
  ll c[m+1];
  for(ll i=1;i<=m;i++) cin>>c[i];
  priority_queue<ll> pq;
  for(ll i=m;i>=1;i--){
   while(x[i]--) pq.push(c[i]);
   if(!pq.empty() && pq.top()>c[i]){
    pq.pop();
    pq.push(c[i]);
   }
  }
  ll ans=0;
  while(!pq.empty()){
   ans+=pq.top();
   pq.pop();
  }
  cout<<ans<<endl;
 }
 
 return 0;
}