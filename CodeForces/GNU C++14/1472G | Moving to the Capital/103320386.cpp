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
 
 read:
 while(t--){
  ll n,m;
  cin>>n>>m;
  vector<ll> parent_of[n+1],child_of[n+1];
  for(ll i=1;i<=m;i++){
   ll x,y;
   cin>>x>>y;
   parent_of[x].pb(y);
   child_of[y].pb(x);
  }
  ll dis[n+1];
  for(ll i=2;i<=n;i++) dis[i]=-1;
 
  queue<ll> q;
  q.push(1LL);
  dis[1]=0;
  vector<ll> ts;
 
  while(!q.empty()){
   ll u=q.front();
   q.pop();
 
   for(ll i=0;i<parent_of[u].size();i++){
    ll v=parent_of[u][i];
    if(dis[v]==-1){
     dis[v]=dis[u]+1;
     q.push(v);
    }
   }
   ts.pb(u);
  }
 
  ll ans[n+1],mark[n+1],vis[n+1];
  for(ll i=1;i<=n;i++){
   ans[i]=dis[i];
   mark[i]=0;
   vis[i]=0;
  }
 
  for(ll i=0;i<n;i++){
   if(!vis[ts[i]]){
    q.push(ts[i]);
    //cout<<ts[i]<<endl;
    while(!q.empty()){
     ll v=q.front();
     q.pop();
     for(ll j=0;j<child_of[v].size();j++){
      ll u=child_of[v][j];
      if(v==ts[i]){
       if(ans[u]>dis[v]){
        //cout<<u<<" "<<v<<endl;
        ans[u]=dis[v];
        mark[u]=1;
        q.push(u);
       }
      }
      else if((ans[u]>ans[v] && (!mark[v] || dis[u]<dis[v])) || (ans[u]==ans[v] && mark[u] && !mark[v] && dis[u]<dis[v])){
       //cout<<u<<" "<<v<<" "<<ans[u]<<" "<<ans[v]<<" "<<mark[u]<<" "<<mark[v]<<" "<<dis[u]<<" "<<dis[v]<<endl;
       ans[u]=ans[v];
       if(dis[u]<dis[v]) mark[u]=mark[v];
       else mark[u]=1;
       q.push(u);
      }
     }
    }
   }
  }
  for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
 }
 
 return 0;
}