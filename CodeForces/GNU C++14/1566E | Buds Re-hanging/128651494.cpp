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
 
vector<ll> g[200007];
ll ans,m[2000007],c,n;
 
void dfs(ll u,ll p){
    ll ok=0;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v!=p){
            dfs(v,u);
            if(m[v]!=2) ok=1;
        }
    }
    if(u==1){
        ans=n-2*c;
        if(ok) ans--;
    }
    if(ok){
        m[u]=2;
        c++;
    }
    else m[u]=1;
}
 
int main()
{
 
    ll t;
    cin>>t;
 
    while(t--){
        cin>>n;
        c=0;
        for(ll i=1;i<=n;i++){
            g[i].clear();
            m[i]=0;
        }
        for(ll i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1,-1);
        cout<<ans<<endl;
    }
 
    return 0;
}