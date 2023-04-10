#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int main()
{   
    ll t;
    cin>>t;
 
    read:
 
    while(t--){
        ll n,x;
        cin>>n>>x;
 
        multiset<ll> s;
        for(ll i=0;i<n;i++){
            ll v;
            cin>>v;
            s.insert(v);
        }
 
        ll ans=0;
        for(auto v:s){
            multiset<ll>::iterator it=s.lower_bound(x*v);
            if(*it==x*v) s.erase(it);
            else ans++;
        }
 
        cout<<ans<<endl;
    }
 
    return 0;
}