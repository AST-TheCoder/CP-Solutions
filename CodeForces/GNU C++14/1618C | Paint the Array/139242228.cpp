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
        ll n;
        cin>>n;
 
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
 
        ll ans=0;
        for(ll i=0;i<n;i+=2){
            ans=__gcd(ans,a[i]);
        }
        for(ll i=1;i<n;i+=2){
            if(a[i]%ans==0) break;
            if(i+2>=n){
                cout<<ans<<endl;
                goto read;
            }
        }
        ans=0;
        for(ll i=1;i<n;i+=2){
            ans=__gcd(ans,a[i]);
        }
        for(ll i=0;i<n;i+=2){
            if(a[i]%ans==0) break;
            if(i+2>=n){
                cout<<ans<<endl;
                goto read;
            }
        }
        cout<<0<<endl;
    }
 
    return 0;
}