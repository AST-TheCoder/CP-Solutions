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
  ll ans=0;
  pair<ll,ll> x[n+1];
  memset(x,0,sizeof(x));
  for(ll i=1;i<=n;i++){
   cin>>x[i].first;
   ans+=x[i].first;
   x[i].second--;
  }
  for(ll i=1;i<n;i++){
   ll u,v;
   cin>>u>>v;
   x[u].second++;
   x[v].second++;
  }
  sort(x+1,x+n+1,greater<pair<ll,ll>>());
  for(ll i=1,j=1;i<n;i++){
   cout<<ans<<" ";
   while(!x[j].second && j<=n) j++;
   if(j<=n){
    ans+=x[j].first;
    x[j].second--;
   }
  }
  cout<<endl;
 }
 
 return 0;
}