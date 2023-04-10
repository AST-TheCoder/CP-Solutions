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
 
vector<ll> g[400007],rev_g[400007],ts,comp[400007];
ll ans[400007],c,vis[400007];
 
void dfs1(ll u,ll s){
    vis[u]=1;
    if(s==1) ans[u]=1;
 
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(!vis[v]) dfs1(v,s);
        else if(s==1) ans[v]=2;
    }
    ts.pb(u);
}
 
void dfs2(ll u){
    vis[u]=0;
    comp[c].pb(u);
 
    for(ll i=0;i<rev_g[u].size();i++){
        ll v=rev_g[u][i];
        if(u==v) comp[c].pb(u);
        if(vis[v]){
            dfs2(v);
        }
    }
}
 
int main()
{
 
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
 
        ts.clear();
        for(ll i=1;i<=n;i++){
            g[i].clear();
            rev_g[i].clear();
            ans[i]=vis[i]=0;
            comp[i].clear();
        }
 
        for(ll i=0;i<m;i++){
            ll x,y;
            cin>>x>>y;
            g[x].pb(y);
            rev_g[y].pb(x);
        }
 
        for(ll i=1;i<=n;i++){
            if(!vis[i]) dfs1(i,i);
        }
        reverse(all(ts));
        c=1;
        for(ll i=0;i<ts.size();i++){
            if(vis[ts[i]]){
                dfs2(ts[i]);
                c++;
            }
        }
        for(ll i=1;i<c;i++){
            if(comp[i].size()>1){
                for(ll j=0;j<comp[i].size();j++){
                    if(ans[comp[i][j]]) ans[comp[i][j]]=-1;
                }
            }
        }
 
 
        queue<ll> q;
        q.push(1);
        vis[1]=1;
        while(!q.empty()){
            ll u=q.front();
            q.pop();
            for(ll i=0;i<g[u].size();i++){
                ll v=g[u][i];
                if(ans[u]==2 && ans[v]!=-1) ans[v]=2;
                if(ans[u]==-1 && ans[v]!=-1){
                    ans[v]=-1;
                    q.push(v);
                }
                else if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
    }
 
    return 0;
}