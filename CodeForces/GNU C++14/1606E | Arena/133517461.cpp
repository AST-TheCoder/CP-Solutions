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
 
ll n,x;
ll dp[1000][1000];
ll mod=998244353;
ll fact[1000];
 
ll bigmod(ll c,ll p){
    if(!p) return 1;
    if(p%2) return (bigmod(c,p-1)*c)%mod;
    ll v=bigmod(c,p/2);
    return (v*v)%mod;
}
 
ll solve(ll p,ll v){
    if(p+v-1>x){
        if(p>=x) return 0;
        else{
            ll b=x-p;
            return (((fact[n]*bigmod((fact[v]*fact[n-v])%mod,mod-2))%mod)*bigmod(b,v))%mod;
        }
    }
    if(dp[p][v]!=-1) return dp[p][v];
    dp[p][v]=(((fact[n]*bigmod((fact[v]*fact[n-v])%mod,mod-2))%mod)*bigmod(v-1,v))%mod;
    for(ll i=2;i<=v;i++){
        ll val=solve(p+v-1,i);
        val=(val*fact[n-i])%mod;
        val=(val*bigmod((fact[v-i]*fact[n-v])%mod,mod-2))%mod;
        val=(val*bigmod(v-1,v-i))%mod;
        dp[p][v]+=val;
        dp[p][v]%=mod;
    }
    //cout<<p<<" "<<v<<" "<<dp[p][v]<<endl;
    return dp[p][v];
}
 
int main()
{
 
 
    cin>>n>>x;
    memset(dp,-1,sizeof(dp));
    fact[0]=1;
    for(ll i=1;i<1000;i++)
        fact[i]=(fact[i-1]*i)%mod;
    ll ans=solve(0,n);
    cout<<ans<<endl;
 
    return 0;
}