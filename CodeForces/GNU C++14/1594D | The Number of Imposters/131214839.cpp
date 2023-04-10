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
 
vector<pair<ll,ll>> g[200007];
ll ok,vis[200007],val[200007];
ll dfs(ll u,ll p,ll x){
    vis[u]=p;
    val[u]=x;
    ll ans=0;
    if(x==1) ans=1;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i].first;
        ll c=g[u][i].second;
        if(vis[v]==p){
            if(val[u]==1 && c==val[v]){
                //cout<<u<<" "<<v<<" "<<val[u]<<" "<<val[v]<<" "<<c<<endl;
                ok=1;
            }
            if(val[u]==0 && c!=val[v]){
                //cout<<u<<" "<<v<<" "<<val[u]<<" "<<val[v]<<" "<<c<<" "<<p<<endl;
                ok=1;
            }
        }
        else{
            if(val[u]==1){
                if(c==1) ans+=dfs(v,p,0);
                else ans+=dfs(v,p,1);
            }
            else{
                if(c==1) ans+=dfs(v,p,1);
                else ans+=dfs(v,p,0);
            }
        }
    }
    return ans;
}
 
int main()
{
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n,m,ans=0;
        cin>>n>>m;
        for(ll i=1;i<=m;i++){
            ll x,y,c;
            string s;
            cin>>x>>y>>s;
            if(s[0]=='i') c=1;
            else c=0;
            g[x].pb({y,c});
            g[y].pb({x,c});
        }
        for(ll i=1;i<=n;i++){
            if(!vis[i]){
                ans+=max(dfs(i,1,0),dfs(i,2,1));
            }
        }
        if(ok) cout<<-1<<endl;
        else cout<<ans<<endl;
        ok=0;
        for(ll i=1;i<=n;i++){
            g[i].clear();
            vis[i]=val[i]=0;
        }
    }
 
    return 0;
}