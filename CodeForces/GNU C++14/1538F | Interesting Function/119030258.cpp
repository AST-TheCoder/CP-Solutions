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
        ll l,r;
        cin>>l>>r;
        ll ans=0;
        for(ll i=1;i<=1000000000;i*=10){
            ans+=(r/i-l/i);
        }
        cout<<ans<<endl;
    }
 
    return 0;
}