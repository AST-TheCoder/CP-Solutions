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
 
        vector<pair<ll,ll>> p;
        for(ll i=1;i<=n;i++){
            ll m;
            cin>>m;
            ll mx=0;
            for(ll i=0;i<m;i++){
                ll x;
                cin>>x;
                x-=i;
                mx=max(mx,x);
            }
            p.pb({mx,m});
        }
        ll ans=0,cur=0;
        sort(all(p));
        for(ll i=0;i<n;i++){
            if(p[i].first>=cur){
                ll d=p[i].first-cur+1;
                ans+=d;
                cur=p[i].first+1;
            }
            cur+=p[i].second;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}