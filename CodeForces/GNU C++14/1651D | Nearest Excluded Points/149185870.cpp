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
 
pair<ll,ll> p[200007],ans[200007];
vector<ll> g[200007];
vector<pair<ll,ll>> x[200007],y[200007];
bool vis[200007];
 
int main()
{   
    
    ll n;
    cin>>n;
 
    for(ll i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
        y[p[i].second].pb({p[i].first,i});
        x[p[i].first].pb({p[i].second,i});
    }
    for(ll i=1;i<=200000;i++){
        sort(all(y[i]));
        sort(all(x[i]));
        for(ll j=1;j<y[i].size();j++){
            if(y[i][j-1].first==y[i][j].first-1){
                g[y[i][j-1].second].pb(y[i][j].second);
                g[y[i][j].second].pb(y[i][j-1].second);
            }
        }
        for(ll j=1;j<x[i].size();j++){
            if(x[i][j-1].first==x[i][j].first-1){
                g[x[i][j-1].second].pb(x[i][j].second);
                g[x[i][j].second].pb(x[i][j-1].second);
            }
        }
    }
 
    queue<ll> q;
    for(ll i=1;i<=n;i++){
        if(g[i].size()<4){
            vis[i]=1;
            q.push(i);
            pair<ll,ll> c;
 
            for(ll j=1;j<=4;j++){
                if(j==1) c.first=p[i].first-1,c.second=p[i].second;
                if(j==2) c.first=p[i].first+1,c.second=p[i].second;
                if(j==3) c.first=p[i].first,c.second=p[i].second-1;
                if(j==4) c.first=p[i].first,c.second=p[i].second+1;
    
                ll ok=0;
                for(ll k=0;k<g[i].size();k++){
                    ll v=g[i][k];
                    if(c==p[v]){
                        ok=1;
                        break;
                    }
                }
                if(!ok){
                    ans[i]=c;
                }
            }
        }
    }
 
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(ll i=0;i<g[u].size();i++){
            ll v=g[u][i];
            if(!vis[v]){
                vis[v]=1;
                ans[v]=ans[u];
                q.push(v);
            }
        }
    }
 
    for(ll i=1;i<=n;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
 
    return 0;
}