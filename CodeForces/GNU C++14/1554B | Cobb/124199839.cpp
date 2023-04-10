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
        ll n,k;
        cin>>n>>k;
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        ll ans=-Max;
        for(ll i=max(n-2*k,1LL);i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                ll x=(i*j)-k*(a[i]|a[j]);
                ans=max(ans,x);
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}