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
 
ll fact[200007],mod=998244353;
 
ll bigmod(ll n,ll p){
    if(p==0) return 1;
    if(p%2) return (bigmod(n,p-1)*n)%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}
 
int main()
{
 
    fact[0]=1;
    for(ll i=1;i<200007;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod; 
    }
 
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n;cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
            sort(a,a+n,greater<ll>());
 
        if(a[0]==a[1]) cout<<fact[n]<<endl;
        else{
            if(a[0]-1!=a[1]){
                cout<<0<<endl;
                continue;
            }
            ll c=1;
            for(ll i=1;i<n;i++)
                if(a[1]==a[i]) c++;
            ll ans=(fact[c]-fact[c-1]+mod)%mod;
            ll r=(fact[n]*bigmod(fact[c],mod-2))%mod;
            r=(r*bigmod(fact[n-c],mod-2))%mod;
            ans*=r;
            ans%=mod;
            ans*=fact[n-c];
            ans%=mod;
            cout<<ans<<endl;
        }
    }
 
    return 0;
}