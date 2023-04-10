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
        ll a[n],cnt[200];
        memset(cnt,0,sizeof(cnt));
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
 
            if(x<0) a[i]=-x;
            else a[i]=x;
            cnt[a[i]]++;
        }
        ll ans=0;
        for(ll i=0;i<=100;i++){
            if(cnt[i]) ans++;
            if(i && cnt[i]>1) ans++;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}