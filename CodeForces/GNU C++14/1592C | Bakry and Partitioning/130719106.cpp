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
ll v[100007],val,cnt,x[100007];
 
void dfs(ll u,ll p){
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v!=p){
            dfs(v,u);
            x[u]^=x[v];
        }
    }
    x[u]^=v[u];
    if(x[u]==val){
        cnt++;
        x[u]=0;
    }
}
 
int main()
{
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n,k;
        cin>>n>>k;
        for(ll i=1;i<=n;i++){
            cin>>v[i];
            val^=v[i];
        }
        for(ll i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        if(val && k<3){
            cout<<"NO"<<endl;
            goto read;
        }
        if(!val){
            cout<<"YES"<<endl;
            goto read;
        }
        //cout<<val<<endl;
        dfs(1,0);
        if(cnt>2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        read:
        val=cnt=0;
        for(ll i=0;i<=n;i++){
            g[i].clear();
            v[i]=0;
            x[i]=0;
        }
    }
 
    return 0;
}