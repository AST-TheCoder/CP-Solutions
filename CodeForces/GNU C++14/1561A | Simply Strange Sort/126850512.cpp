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
        ll n;
        cin>>n;
 
        ll ans=0;
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll i=1;i<=10000;i++){
            ll ok=0;
            for(ll i=1;i<n;i++){
                if(a[i+1]<a[i]){
                    ok=1;
                    break;
                }
            }
            if(!ok) break;
            ans++;
            if(i%2){
                for(ll i=1;i<=n-2;i+=2)
                    if(a[i]>a[i+1]) swap(a[i],a[i+1]);
            }
            else{
                for(ll i=2;i<=n-1;i+=2)
                    if(a[i]>a[i+1]) swap(a[i],a[i+1]);
            }
        }
        cout<<ans<<endl;
    }
 
    return 0;
}