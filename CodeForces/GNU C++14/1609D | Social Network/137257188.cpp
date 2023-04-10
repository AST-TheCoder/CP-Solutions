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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
ll par[1007],cnt[1007];
 
ll find_par(ll u){
    if(par[u]!=u) return par[u]=find_par(par[u]);
    return u;
}
 
int main()
{   
 
    ll n,q,c=0;
    cin>>n>>q;
 
    for(ll i=1;i<=n;i++) par[i]=i;
 
    while(q--){
        ll u,v,ans=0;
        cin>>u>>v;
 
        u=find_par(u);
        v=find_par(v);
 
        if(u!=v){
            par[v]=u;
            //cout<<u<<" "<<v<<" "<<cnt[u]<<" "<<cnt[v]<<" "<<par[v]<<" "<<par[u]<<endl;
            cnt[u]+=(cnt[v]+1);
        }
        else c++;
        vector<ll> x;
        for(ll i=1;i<=n;i++)
            if(par[i]==i)
                x.pb(cnt[i]);
        sort(all(x),greater<ll>());
        ans=x[0];
        for(ll i=1;i<x.size() && i<=c;i++){
            ans+=(x[i]+1);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}