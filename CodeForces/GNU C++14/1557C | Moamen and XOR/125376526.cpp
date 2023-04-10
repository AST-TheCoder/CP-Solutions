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
 
ll n,k,mod=1000000007;
 
ll bigmod(ll v,ll p){
    if(!p) return 1;
    if(p%2) return (v*bigmod(v,p-1))%mod;
    ll x=bigmod(v,p/2);
    return (x*x)%mod;
}
 
ll solve(ll pos){
    if(pos>k) return 1;
    ll ans=0,cnt=0;
    if(n%2==0){
        cnt=-1;
        ans=bigmod(2,n*(k-pos));
    }
    else cnt=1;
    ll x=solve(pos+1);
    cnt+=bigmod(2,n-1);
    ans+=(x*cnt);
    return ans%mod;
}
 
int main()
{   
 
    ll t;
    cin>>t;
 
    while(t--){
        cin>>n>>k;
        ll ans=solve(1);
        cout<<ans<<endl;
    }
 
    return 0;
}