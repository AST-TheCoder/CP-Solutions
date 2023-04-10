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
ll bigmod(ll n,ll p){
    if(p==0) return 1;
    if(p%2) return (bigmod(n,p-1)*n)%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}
 
int main()
{
 
    ll t;
    cin>>t;
 
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(n==1){
            cout<<k<<endl;
            continue;
        }
        ll ans=0;
        for(ll i=0;i<31;i++){
            if((k&(1<<i)) && (1<<i)<=k){
                //cout<<i<<endl;
                ans+=bigmod(n,i);
                ans%=mod;
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}