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
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
 
int main()
{  
 
    ll n,q;
    cin>>n>>q;
 
    ll ans[n+1];
    ll val=pow(2,30)-1;
 
    for(ll i=1;i<=n;i++) ans[i]=val;
 
    vector<pair<ll,ll>> g[n+1];
    for(ll i=1;i<=q;i++){
        ll u,v,val;
        cin>>u>>v>>val;
 
        g[u].pb({v,val});
        g[v].pb({u,val});
    }
 
    for(ll k=0;k<30;k++){
        for(ll i=1;i<=n;i++){
            ll u=i;
            for(ll j=0;j<g[u].size();j++){
                ll v=g[u][j].first;
                ll w=g[u][j].second;
                if(!(w&(1<<k))){
                    ans[u]&=(val-(1<<k));
                }
            }
        }
        for(ll i=1;i<=n;i++){
            ll u=i,chk=(1<<k);
            if(!(ans[u]&chk)) continue;
            for(ll j=0;j<g[u].size();j++){
                ll v=g[u][j].first;
                chk&=ans[v];
                if(u==v) chk=0;
            }
            if(chk) ans[u]&=(val-chk);
        }
    }
    for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
 
    return 0;
}