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
 
ll mod=1000000007;
 
vector<ll> g[101];
ll vl[101];
ll dfs(ll u,ll p,ll lvl){
    ll ans=lvl;
    vl[lvl]++;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v!=p){
            ans=max(ans,dfs(v,u,lvl+1));
        }
    }
    return ans;
}
 
int main()
{   
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n,k,ans=0;
        cin>>n>>k;
 
        for(ll i=1;i<=100;i++) g[i].clear();
 
        for(ll i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
 
        if(k==2){
            cout<<(n*(n-1))/2<<endl;
            continue;
        }
        for(ll u=1;u<=n;u++){
            ll lvl[n+1];
            vector<ll> c[n+1];
            memset(lvl,0,sizeof(lvl));
 
            for(ll i=0;i<g[u].size();i++){
                ll l=dfs(g[u][i],u,1);
                for(ll j=l;j>=1;j--){
                    c[j].pb(vl[j]);
                    lvl[j]++;
                    vl[j]=0;
                }
            }
 
            for(ll i=1;i<=n;i++){
                if(lvl[i]>=k){
                    ll chk[k+1];
                    memset(chk,0,sizeof(chk));
                    chk[0]=1;
                    for(ll j=0,sp=1;j<c[i].size();j++){
                        for(ll l=sp-1;l>=0;l--){
                            chk[l+1]+=(chk[l]*c[i][j]);
                            chk[l+1]%=mod;
                        }
                        sp=min(sp+1,k);
                    }
                    ans+=chk[k];
                    ans%=mod;
                }
                else break;
            }
        }
        cout<<ans<<endl;
 
    }
 
    return 0;
}