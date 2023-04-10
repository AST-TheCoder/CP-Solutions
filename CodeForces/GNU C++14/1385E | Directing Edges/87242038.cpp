#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
vector<ll> d_graph[200007],trop_sort;
bool vis[200007];
 
void dfs(ll u){
 vis[u]=1;
 
 for(ll i=0;i<d_graph[u].size();i++){
  ll v=d_graph[u][i];
  if(!vis[v]){
   dfs(v);
  }
 }
 
 trop_sort.pb(u);
}
 
int main()
{
 ll t;
 cin>>t;
 read:
 while(t--){
  ll n,m;
  cin>>n>>m;
  vector<pair<ll,ll>> x;
  ll pos[n+1];
 
  trop_sort.clear();
  for(ll i=1;i<=n;i++){
   d_graph[i].clear();
   vis[i]=0;
  }
 
  for(ll i=1;i<=m;i++){
   ll t,u,v;
   cin>>t>>u>>v;
   if(t) d_graph[u].pb(v);
   else x.pb(mp(u,v));
  }
 
  for(ll i=1;i<=n;i++){
   if(!vis[i]) dfs(i);
  }
 
  for(ll i=0;i<n;i++){
   pos[trop_sort[i]]=i;
  }
 
  for(ll i=1;i<=n;i++){
   for(ll j=0;j<d_graph[i].size();j++){
    ll u=i,v=d_graph[i][j];
    if(pos[v]>pos[u]){
     cout<<"NO"<<endl;
     goto read;
    }
   }
  }
 
  for(ll i=0;i<x.size();i++){
   ll u=x[i].first,v=x[i].second;
   if(pos[u]>pos[v]) d_graph[u].pb(v);
   else d_graph[v].pb(u);
  }
 
  cout<<"YES"<<endl;
  for(ll i=1;i<=n;i++){
   for(ll j=0;j<d_graph[i].size();j++){
    ll u=i,v=d_graph[i][j];
    cout<<u<<" "<<v<<endl;
   }
  }
 }
 
 return 0;
}