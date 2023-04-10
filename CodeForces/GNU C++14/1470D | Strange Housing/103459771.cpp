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
 
vector<ll> g[300007],ans;
ll vis[300007],nodes;
 
void dfs(ll u){
 if(vis[u]==1){
  for(ll i=0;i<g[u].size();i++){
   ll v=g[u][i];
   if(!vis[v]){
    vis[v]=2;
    nodes++;
   }
  }
 }
 ll ok=vis[u];
 vis[u]=3;
 for(ll i=0;i<g[u].size();i++){
  ll v=g[u][i];
  if(vis[v]==0 || vis[v]==2){
   if(!vis[v]){
    nodes++;
    if(ok==2){
     vis[v]=1;
     ans.pb(v);
    }
   }
   dfs(v);
  }
 }
}
 
int main()
{ 
 ll t;
 scanf("%lli",&t);
 
 while(t--){
  ll n,m;
  scanf("%lli %lli",&n,&m);
  nodes=0;
  ans.clear();
  for(ll i=1;i<=n;i++){
   g[i].clear();
   vis[i]=0;
  }
  for(ll i=0;i<m;i++){
   ll x,y;
   cin>>x>>y;
   g[x].pb(y);
   g[y].pb(x);
  }
  ans.pb(1LL);
  vis[1]=1;
  nodes=1;
  dfs(1);
  //cout<<nodes<<endl;
  if(nodes!=n){
   cout<<"NO"<<endl;
   continue;
  }
  else{
   cout<<"YES"<<endl;
   cout<<(ll)ans.size()<<endl;
   for(ll i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }cout<<endl;
  }
 }
 
 return 0;
}