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
 
vector<ll> g[200007];
ll vis[200007],x[200007],px[200007],y[200007],py[200007],ans[200007];
 
void dfs(ll u){
    vis[u]=1;
    x[u]=1;
    px[u]=g[u].size();
    py[u]=1;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(!vis[v]){
            dfs(v);
            x[u]+=y[v];
            px[u]+=py[v];
 
            if(x[v]>y[v]){
                y[u]+=x[v];
                py[u]+=px[v];
            }
            else if(x[v]==y[v]){
                y[u]+=x[v];
                py[u]+=min(px[v],py[v]);
            }
            else{
                y[u]+=y[v];
                py[u]+=py[v];
            }
        }
    }
    //cout<<u<<" "<<x[u]<<" "<<px[u]<<" "<<y[u]<<" "<<py[u]<<endl;
}
 
void make_soln(ll u,ll state){
    vis[u]=0;
    if(state==1){
        ans[u]=1;
        for(ll i=0;i<g[u].size();i++){
            ll v=g[u][i];
            if(vis[v]) make_soln(v,0);
        }
        return;
    }
    if(x[u]>y[u] || (x[u]==y[u] && px[u]<py[u])){
        ans[u]=g[u].size();
        for(ll i=0;i<g[u].size();i++){
            ll v=g[u][i];
            if(vis[v]) make_soln(v,1);
        }
        return;
    }
    else{
        ans[u]=1;
        for(ll i=0;i<g[u].size();i++){
            ll v=g[u][i];
            if(vis[v]) make_soln(v,0);
        }
        return;
    }
}
 
int main()
{   
    ll n;
    cin>>n;
 
    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
 
        g[u].pb(v);
        g[v].pb(u);
    }
    if(n==2){
        cout<<2<<" "<<2<<endl<<1<<" "<<1<<endl;
        return 0;
    }
 
    dfs(1);
    make_soln(1,0);
    
    if(x[1]>y[1] || (x[1]==y[1] && px[1]<py[1])) cout<<x[1]<<" "<<px[1]<<endl;
    else cout<<y[1]<<" "<<py[1]<<endl;
 
    for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
 
    return 0;
}