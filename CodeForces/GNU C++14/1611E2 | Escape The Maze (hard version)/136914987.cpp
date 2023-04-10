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
 
 
ll x[200007],d[200007],ans[200007];
vector<ll> g[200007];
 
ll dfs(ll u,ll p){
    if(p) d[u]=d[p]+1;
    ll ok=2;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v==p) continue;
        ok=min(ok,dfs(v,u));
        x[u]=min(x[u],x[v]+1);
        ans[u]+=ans[v];
    }
    //cout<<u<<" "<<x[u]<<" "<<d[u]<<" "<<ok<<endl;
    if(x[u]<=d[u]){
        ans[u]=1;
        return 1;
    }
    else if(ok==1) return 1;
    else{
        ans[u]=0;
        return 0;
    }
}
 
 
int main()
{   
    
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,k;
        cin>>n>>k;
        for(ll i=1;i<=n;i++){
            x[i]=Max;
            g[i].clear();
            ans[i]=0;
        }
        for(ll i=1;i<=k;i++){
            ll p;
            cin>>p;
            x[p]=0;
        }
        for(ll i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        if(dfs(1,0)) cout<<ans[1]<<endl;
        else cout<<-1<<endl;
    }
 
    return 0;
}