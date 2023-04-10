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
 
ll n,k,a[2001],dpt[2001];
vector<ll> g[2001];
 
ll dfs(ll u){
 
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(dpt[v]==1)
            dpt[u]=max(dpt[u],dfs(v)+1);
        else dpt[u]=max(dpt[u],dpt[v]+1);
    }
    return dpt[u];
}
 
int main()
{   
 
    ll t;
    scanf("%lli",&t);
 
    while(t--){
        scanf("%lli %lli",&n,&k);
        for(ll i=1;i<=n;i++)
            scanf("%lli",&a[i]);
        
        for(ll i=0;i<=n;i++){
            g[i].clear();
            dpt[i]=1;
        }
 
        for(ll i=2;i<=n;i++){
            for(ll j=i-1;j>=1;j--){
                if(a[j]<a[i] && a[j]<=j && j-a[j]<=i-a[i]) g[i].pb(j);
            }
        }
 
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<g[i].size();j++){
                //cout<<i<<" "<<g[i][j]<<endl;
            }
        }
 
        ll ans=Max;
        for(ll i=n;i>=1;i--){
            if(a[i]<=i && dfs(i)>=k) ans=min(ans,i-a[i]);
        }
 
        if(ans==Max) printf("-1\n");
        else printf("%lli\n",ans);
    }
 
    return 0;
}