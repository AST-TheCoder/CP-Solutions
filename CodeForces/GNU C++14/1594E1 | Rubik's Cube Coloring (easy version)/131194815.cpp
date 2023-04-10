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
 
ll mod=1000000007LL;
ll bigmod(ll n,ll p){
    if(p==0LL) return 1LL;
    if(p%2LL) return (bigmod(n,p-1LL)*n)%mod;
    ll x=bigmod(n,p/2LL);
    return (x*x)%mod;
}
 
int main()
{
 
    ll n;
    cin>>n;
    ll p=1LL;
    ll ans=6LL;
    for(ll i=2LL;i<=n;i++){
        p*=2LL;
        //cout<<p<<endl;
        ans*=bigmod(4LL,p);
        ans%=mod;
    }
    cout<<ans<<endl;
 
    return 0;
}