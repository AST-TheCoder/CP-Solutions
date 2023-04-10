#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
vector<ll> graph[100007];
bool vis[100007];
ll child[100007],n,mod=1000000007;
vector<ll> edge_count;
 
void dfs(ll u){
 vis[u]=1;
 for(ll i=0;i<graph[u].size();i++){
  ll v=graph[u][i];
  if(!vis[v]){
   dfs(v);
   child[u]+=child[v];
   edge_count.pb(child[v]*(n-child[v]));
  }
 }
 child[u]++;
}
 
int main()
{
 
 ll t;
 cin>>t;
 
 read:
 while(t--){
  cin>>n;
 
  edge_count.clear();
  for(ll i=1;i<=n;i++){
   graph[i].clear();
   vis[i]=0;
   child[i]=0;
  }
 
  for(ll i=1;i<n;i++){
   ll u,v;
   cin>>u>>v;
   graph[u].pb(v);
   graph[v].pb(u);
  }
  dfs(1);
  sort(all(edge_count),greater<ll>());
  for(ll i=0;i<edge_count.size();i++) edge_count[i]%=mod;
 
  ll m,ans=0;
  cin>>m;
  vector<ll> p;
  for(ll i=0;i<m;i++){
   ll x;
   cin>>x;
   p.pb(x);
  }
  sort(all(p),greater<ll>());
 
  for(ll i=0,j=0;i<max(p.size(),edge_count.size());i++){
   if(i>=p.size()){
    ans+=edge_count[i];
    ans%=mod;
   }
   else if(p.size()-i>edge_count.size()){
    p[i+1]*=p[i];
    j++;
    p[i+1]%=mod;
   }
   else{
    ans+=((p[i]*edge_count[i-j])%mod);
    ans%=mod;
   }
  }
  cout<<ans<<endl;
 }
 
 return 0;
}