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
        ll n,ans=0;
        cin>>n;
 
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
 
        for(ll i=n-2,x=a[n-1];i>=0;i--){
            if(a[i]>x){
                x=a[i];
                ans++;
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}