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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main()
{   
 
    ll t;
    cin>>t;
 
    read:
    while(t--){
        ll n,k,ans=0;
        cin>>n>>k;
 
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
 
        for(ll i=n-1,j=n-k-1;i>=n-k;i--,j--){
            ans+=(a[j]/a[i]);
        }
        for(ll i=0;i<n-2*k;i++) ans+=a[i];
        cout<<ans<<endl;
    }
 
    return 0;
}