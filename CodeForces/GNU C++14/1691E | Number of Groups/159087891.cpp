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
 
int main()
{   
    ll t,ii=0;
    cin>>t;
 
    read:
    while(t--){
        ll n;
        cin>>n;
 
        vector<pair<ll,ll>> x,y;
        for(ll i=0;i<n;i++){
            ll op,u,v;
            cin>>op>>u>>v;
            if(op) x.pb({u,v});
            else y.pb({u,v});
        }
 
        sort(all(x));
        sort(all(y));
        vector<ll> g[n];
 
        //cout<<endl;
        //for(ll i=0;i<x.size();i++) cout<<x[i].first<<" "<<x[i].second<<endl;
        //cout<<endl;
        //for(ll i=0;i<y.size();i++) cout<<y[i].first<<" "<<y[i].second<<endl;
 
        ll ans=0;
        for(ll i=0,j=0;i<x.size();i++){
            for(;j<y.size();j++){
                if(y[j].first<=x[i].second && y[j].second>=x[i].first){
                    g[i].pb(x.size()+j);
                    g[x.size()+j].pb(i);
                }if(y[j].first>x[i].second) break;
            }
            if(j) j--;
        }
        for(ll j=0,i=0;j<y.size();j++){
            for(;i<x.size();i++){
                if(x[i].first<=y[j].second && x[i].second>=y[j].first){
                    g[i].pb(x.size()+j);
                    g[x.size()+j].pb(i);
                }if(x[i].first>y[j].second) break;
            }
            if(i) i--;
        }
        ll vis[n];
        memset(vis,-1,sizeof(vis));
        for(ll i=0;i<n;i++){
            if(!vis[i]) continue;
            //cout<<i<<endl;
            queue<ll> q;
            q.push(i);
            vis[i]=0;
            ans++;
            while(!q.empty()){
                ll u=q.front();
                q.pop();
                for(ll j=0;j<g[u].size();j++){
                    ll v=g[u][j];
                    if(vis[v]){
                        vis[v]=0;
                        q.push(v);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}