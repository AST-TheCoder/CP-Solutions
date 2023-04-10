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
        ll n;
        cin>>n;
 
        ll a[n],b[n],c[n],mod=1000000007;
 
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];
        for(ll i=0;i<n;i++) cin>>c[i];
 
        ll idx[n+1];
        for(ll i=0;i<n;i++) idx[a[i]]=i;
 
        for(ll i=0;i<n;i++){
            if(c[i]<=0) continue;
 
            ll j=idx[b[i]];
            c[i]=c[j]=-1;
            while(a[i]!=b[j]){
                j=idx[b[j]];
                c[j]=-1;
            }
        }
        ll ans=1;
        for(ll i=0;i<n;i++){
            if(c[i]<0 || a[i]==b[i]) continue;
 
            ll j=idx[b[i]];
            c[i]=c[j]=-1;
            while(a[i]!=b[j]){
                j=idx[b[j]];
                c[j]=-1;
            }
            ans=(ans*2)%mod;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}