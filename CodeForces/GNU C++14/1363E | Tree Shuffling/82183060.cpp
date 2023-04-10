#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
vector<ll> g[200001];
bool vis[200001],b[200001],c[200001];
ll a[200001],OtoZ[200001],ZtoO[200001],ans;
 
void dfs(ll u,bool chk,ll val)
{
 if(!chk){
  vis[u]=1;
  if(b[u] && !c[u]) OtoZ[u]++;
  if(!b[u] && c[u]) ZtoO[u]++;
 
  for(ll i=0;i<g[u].size();i++){
   ll v=g[u][i];
   if(!vis[v]){
    dfs(v,chk,val);
    OtoZ[u]+=OtoZ[v];
    ZtoO[u]+=ZtoO[v];
   }
  }
 }
 else{
  if(val>a[u]){
   ans-=(2*min(OtoZ[u],ZtoO[u])*val);
   ans+=(2*min(OtoZ[u],ZtoO[u])*a[u]);
  }
  vis[u]=0;
  for(ll i=0;i<g[u].size();i++){
   ll v=g[u][i];
   if(vis[v]){
    dfs(v,chk,min(val,a[u]));
   }
  }
 }
}
 
int main()
{
 
 ll n;
 cin>>n;
 for(ll i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
 for(ll i=1;i<n;i++){
  ll x,y;
  cin>>x>>y;
  g[x].push_back(y);
  g[y].push_back(x);
 }
 
 dfs(1,0,-1);
 
 if(OtoZ[1]!=ZtoO[1]){
  cout<<-1<<endl;
  return 0;
 }
 
 ans=(OtoZ[1]+ZtoO[1])*a[1];
 dfs(1,1,a[1]);
 
 cout<<ans<<endl;
 
 return 0;
}