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
 
vector<ll> g1[1007],g2[1007],cm1[1007],cm2[1007];
ll c1,c2,v1[1007],v2[1007],m1[1007],m2[1007];
 
void dfs1(ll u){
    v1[u]=1;
    m1[u]=c1;
    cm1[c1].pb(u);
    for(ll i=0;i<g1[u].size();i++){
        ll v=g1[u][i];
        if(!v1[v]) dfs1(v);
    }
}
void dfs2(ll u){
    v2[u]=1;
    m2[u]=c2;
    cm2[c2].pb(u);
    for(ll i=0;i<g2[u].size();i++){
        ll v=g2[u][i];
        if(!v2[v]) dfs2(v);
    }
}
 
int main()
{   
 
    ll n,p,q;
    cin>>n>>p>>q;
    for(ll i=1;i<=p;i++){
        ll u,v;
        cin>>u>>v;
        g1[u].pb(v);
        g1[v].pb(u);
    }
    for(ll i=1;i<=n;i++){
        if(!v1[i]){
            c1++;
            dfs1(i);
        }
    }
    for(ll i=1;i<=q;i++){
        ll u,v;
        cin>>u>>v;
        g2[u].pb(v);
        g2[v].pb(u);
    }
    for(ll i=1;i<=n;i++){
        if(!v2[i]){
            c2++;
            dfs2(i);
        }
    }
 
    vector<pair<ll,ll>> ans;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(m1[i]!=m1[j] && m2[i]!=m2[j]){
                ans.pb({i,j});
                if(cm1[m1[i]].size()<=cm1[m1[j]].size()){
                    ll x=m1[i];
                    for(ll k=0;k<cm1[x].size();k++){
                        cm1[m1[j]].pb(cm1[x][k]);
                        m1[cm1[x][k]]=m1[j];
                    }
                    cm1[x].clear();
                }
                else{
                    ll x=m1[j];
                    for(ll k=0;k<cm1[x].size();k++){
                        cm1[m1[i]].pb(cm1[x][k]);
                        m1[cm1[x][k]]=m1[i];
                    }
                    cm1[x].clear();
                }
                if(cm2[m2[i]].size()<=cm2[m2[j]].size()){
                    ll x=m2[i];
                    for(ll k=0;k<cm2[x].size();k++){
                        cm2[m2[j]].pb(cm2[x][k]);
                        m2[cm2[x][k]]=m2[j];
                    }
                    cm2[x].clear();
                }
                else{
                    ll x=m2[j];
                    for(ll k=0;k<cm2[x].size();k++){
                        cm2[m2[i]].pb(cm2[x][k]);
                        m2[cm2[x][k]]=m2[i];
                    }
                    cm2[x].clear();
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
 
    return 0;
}