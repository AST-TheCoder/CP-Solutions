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
 
    while(t--){
        ll n;
        cin>>n;
        ll a[2*n+1][2*n+1];
        ll ans=0;
        for(ll i=1;i<=2*n;i++){
            for(ll j=1;j<=2*n;j++){
                cin>>a[i][j];
                if(i>n && j>n) ans+=a[i][j];
            }
        }
        ans+=min(min(min(a[1][n+1],a[1][2*n]),min(a[n][n+1],a[n][2*n])),min(min(a[n+1][1],a[n+1][n]),min(a[2*n][1],a[2*n][n])));
        cout<<ans<<endl;
    }
 
    return 0;
}