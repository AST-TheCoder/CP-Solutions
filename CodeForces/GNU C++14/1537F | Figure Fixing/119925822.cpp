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
 
int main()
{
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll p[n+1],t[n+1];
        for(ll i=1;i<=n;i++) cin>>p[i];
        for(ll i=1;i<=n;i++) cin>>t[i];
 
        vector<ll> g[n+1],seq;
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
 
        ll par[n+1],lvl[n+1];
        memset(lvl,-1,sizeof(lvl));
        lvl[1]=1;
        par[1]=-1;
        queue<ll> q;
 
        q.push(1);
        while(!q.empty()){
            ll u=q.front();
            q.pop();
            for(ll i=0;i<g[u].size();i++){
                ll v=g[u][i];
                if(lvl[v]==-1){
                    lvl[v]=lvl[u]+1;
                    par[v]=u;
                    q.push(v);
                }
            }
            seq.pb(u);
        }
        reverse(all(seq));
 
        for(ll i=0;i<seq.size()-1;i++){
            ll u=seq[i];
            // for(ll j=0;j<g[u].size();j++){
            //     ll v=g[u][j];
            //     ll c1=t[u]-p[u],c2=t[v]-p[v];
            //     if(c1 && c2 && c1/abs(c1)==c2/abs(c2)){
            //         ll c=(c1/abs(c1))*min(abs(c1),abs(c2));
            //         p[v]+=c;
            //         p[u]+=c;
            //         cout<<u<<" "<<v<<" "<<c<<endl;
            //     }
            // }
            ll v=par[u];
            ll c=t[u]-p[u];
            p[v]+=c;
            p[u]+=c;
            //cout<<u<<" "<<v<<" "<<c<<endl;
        }
        if(p[1]==t[1]) cout<<"YES"<<endl;
        else if(abs(t[1]-p[1])%2==0){
            ll ok=0;
            for(ll u=1;u<=n;u++){
                for(ll j=0;j<g[u].size();j++){
                    ll v=g[u][j];
                    if(lvl[u]%2==lvl[v]%2){
                        ok=1;
                        break;
                    }
                }
            }
            if(ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
 
    return 0;
}