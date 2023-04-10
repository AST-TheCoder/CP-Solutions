#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
vector<ll> g[100007];
ll p[100007],q[100007],l[100007],r[100007];
 
void dfs(ll u,ll par){
 for(ll i=0;i<g[u].size();i++){
  ll v=g[u][i];
  if(v==par) continue;
  dfs(v,u);
  l[u]+=max(l[v]+abs(p[v]-p[u]),r[v]+abs(q[v]-p[u]));
  r[u]+=max(l[v]+abs(p[v]-q[u]),r[v]+abs(q[v]-q[u]));
 }
 //cout<<u<<" "<<l[u]<<" "<<r[u]<<endl;
}
 
int main()
{   
    
    
    ll t;
    scanf("%lli",&t);
 
    while(t--){
     ll n;
     scanf("%lli",&n);
 
     for(ll i=1;i<=n;i++){
      scanf("%lli %lli",&p[i],&q[i]);
      g[i].clear();
      l[i]=r[i]=0;
     }
     for(ll i=1;i<n;i++){
      ll x,y;
      scanf("%lli %lli",&x,&y);
      g[x].pb(y);
      g[y].pb(x);
     }
 
     dfs(1,-1);
     printf("%lli\n",max(l[1],r[1]));
    }
 
    return 0;
}