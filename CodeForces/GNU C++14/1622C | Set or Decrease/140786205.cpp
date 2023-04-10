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
        ll n,k;
        cin>>n>>k;
 
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        ll ans=Max;
        sort(a,a+n);
        for(ll i=1;i<n;i++) swap(a[i],a[i-1]);
        for(ll i=0,s=0;i<n;i++){
            //if(s>k) break;
            ll m=(k-s)/(n-i);
            if(m*(n-i)>(k-s)) m--;
            ll temp=max(a[n-1]-m,0LL)+n-i-1;
            ans=min(ans,temp);
            //cout<<s<<" "<<i<<" "<<a[i]<<" "<<m<<" "<<temp<<" "<<ans<<endl;
            s+=a[i];
        }
        cout<<ans<<endl;
    }
 
    return 0;
}