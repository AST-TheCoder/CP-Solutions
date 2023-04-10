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
 
vector<ll> g[300007];
 
ll dfs(ll u,ll p){
    if(g[u].size()<3 && u!=1) return g[u].size(); 
    ll x=Max;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v==p) continue;
        x=min(x,dfs(v,u));
    }
    x+=2;
    //cout<<u<<" "<<x<<endl;
    return x;
}
 
int main()
{   
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++) g[i].clear();
 
        for(ll i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
 
            g[u].pb(v);
            g[v].pb(u);
        }
        if(g[1].size()==1){
            cout<<n-2<<endl;
            continue;
        }
 
        ll ans=dfs(1,-1);
        cout<<n-ans<<endl;
    }
 
    return 0;
}